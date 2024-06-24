#include "mod_override.h"

bool process_mod_overrides(uint16_t keycode, keyrecord_t *record) {
  static uint16_t registered_mod_keycode = 0;

  // If a modifed key is registered, then this event is either releasing it or
  // manipulating another key at the same time. Either way, release it first
  if (registered_mod_keycode != 0) {
    unregister_code16(registered_mod_keycode);
    send_keyboard_report();
    registered_mod_keycode = 0;
  }

  // Don't mess with releases
  if (!record->event.pressed) return true;

  // Continue default handling if this is a tap-hold key being held
  if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) &&
      record->event.pressed && record->tap.count == 0) {
    return true;
  }

  // Loop through all mod overrides to see if any apply for the pressed keycode
  for (int i = 0; mod_overrides[i].keycode != 0; ++i) {
    if (keycode == mod_overrides[i].keycode) {
      const uint8_t mod_mask = mod_overrides[i].mod_mask;
      const uint8_t real_mod = get_mods() & mod_mask;
      const uint8_t weak_mod = get_weak_mods() & mod_mask;
      const uint8_t osm_mod = get_oneshot_mods() & mod_mask;
      // And the required mod is held...
      if ((real_mod | weak_mod | osm_mod) != 0) {
        registered_mod_keycode = mod_overrides[i].mod_keycode;
        // If the modified keycode doesn't expect the held mod to be applied, then
        // the held mod needs to be removed before registering the modified keycode
        if (!IS_QK_MODS(registered_mod_keycode) ||
            (QK_MODS_GET_MODS(registered_mod_keycode) & (mod_mask & 0x0F)) == 0) {
          del_mods(real_mod);
          del_weak_mods(weak_mod);
          del_oneshot_mods(osm_mod);
          send_keyboard_report();
        }
        register_code16(registered_mod_keycode);
        add_mods(real_mod); // No-op if it wasn't removed above
        return false;
      }
    }
  }

  return true;
}
