#include "shift_override.h"

bool process_shift_overrides(uint16_t keycode, keyrecord_t *record) {
  static uint16_t shifted_keycode = 0;

  // If a shifted key is registered, then this event is either releasing it or
  // manipulating another key at the same time. Either way, release it first.
  if (shifted_keycode != 0) {
    unregister_code16(shifted_keycode);
    send_keyboard_report();
    shifted_keycode = 0;
  }

  // Continue default handling if this is a tap-hold key being held.
  if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) &&
      record->event.pressed && record->tap.count == 0) {
    return true;
  }

  // Don't mess with releases.
  if (!record->event.pressed) return true;

  const uint8_t real_shift = get_mods() & MOD_MASK_SHIFT;
  const uint8_t weak_shift = get_weak_mods() & MOD_MASK_SHIFT;
  const uint8_t oneshot_shift = get_oneshot_mods() & MOD_MASK_SHIFT;
  if ((real_shift | weak_shift | oneshot_shift) != 0) {  // Shift is held.

    // Search for a custom shift key whose keycode is `keycode`.
    for (int i = 0; shift_overrides[i].keycode != 0; ++i) {
      if (keycode == shift_overrides[i].keycode) {
        shifted_keycode = shift_overrides[i].shifted_keycode;
        // Should key be shifted?
        if (IS_QK_MODS(shifted_keycode) && (QK_MODS_GET_MODS(shifted_keycode) & MOD_LSFT) != 0) {
          // If so, press directly
          register_code16(shifted_keycode);
        } else {
          // If not, cancel shift mods, press the key, and restore mods.
          del_mods(real_shift);
          del_weak_mods(weak_shift);
          del_oneshot_mods(oneshot_shift);
          send_keyboard_report();
          register_code16(shifted_keycode);
          add_mods(real_shift);
        }
        return false;
      }
    }
  }

  return true;
}
