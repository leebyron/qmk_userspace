#include QMK_KEYBOARD_H

#include "features/mod_override.h"
#include "layers.h"
#include "keycodes.h"
#include "macros.h"

// Toggles on a one-shot layer
bool process_sticky_layer(uint16_t keycode, keyrecord_t *record) {
  if (keycode == _SLIDE_ && !record->event.pressed && record->tap.count == 2) {
    reset_oneshot_layer();
    set_oneshot_layer(LAYER_SLIDE, ONESHOT_TOGGLED);
    return false;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_mod_overrides(keycode, record)) return false;
  if (!process_sticky_layer(keycode, record)) return false;
  if (!process_macros(keycode, record)) return false;
  return true;
}
