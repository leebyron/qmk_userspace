#include "keycodes.h"
#include QMK_KEYBOARD_H

#include "leebyron.h"
#include "features/mod_override.h"
#include "keycodes.h"
#include "macros.h"

// Toggles on a one-shot layers
bool process_sticky_layer(uint16_t keycode, keyrecord_t *record) {
  if (IS_QK_ONE_SHOT_LAYER(keycode) && !record->event.pressed && record->tap.count == 2) {
    reset_oneshot_layer();
    set_oneshot_layer(QK_ONE_SHOT_LAYER_GET_LAYER(keycode), ONESHOT_TOGGLED);
    return false;
  }
  return true;
}

#define IS_ALPHANUMERIC(keycode) \
  ((keycode >= KC_A && keycode <= KC_Z) || (keycode >= KC_1 && keycode <= KC_0))

// Permissive hold for non-alphanum-space keys
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  return IS_QK_MOD_TAP(keycode) &&
    !IS_ALPHANUMERIC(QK_MOD_TAP_GET_TAP_KEYCODE(keycode)) &&
    QK_MOD_TAP_GET_TAP_KEYCODE(keycode) != KC_SPACE;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  return keycode == CMD_BKSP;
}

// Enables retro tap for alphanum keys, but with a timeout.
uint16_t last_mt_held_time = 0;

bool process_retro_tap_time(uint16_t keycode, keyrecord_t *record) {
  if (IS_QK_MOD_TAP(keycode) && record->event.pressed && !record->tap.count) {
    last_mt_held_time = record->event.time;
  }
  return true;
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  // Otherwise for the alphanumeric mods
  return IS_QK_MOD_TAP(keycode) &&
    IS_ALPHANUMERIC(QK_MOD_TAP_GET_TAP_KEYCODE(keycode)) &&
    !timer_expired(record->event.time, last_mt_held_time + MOD_RETRO_TIMEOUT);
}

// Custom tap actions for some hold/taps where the keycode encodes the hold.
bool process_complex_tap_mods(uint16_t keycode, keyrecord_t *record) {
  if (!IS_QK_LAYER_TAP(keycode) || QK_LAYER_TAP_GET_LAYER(keycode) > 0) return true;

  if (!record->tap.count) {
    if (record->event.pressed) {
      register_code16(QK_LAYER_TAP_GET_TAP_KEYCODE(keycode));
    } else {
      // Neutralize single-tap of FN key
      if (QK_LAYER_TAP_GET_TAP_KEYCODE(keycode) == KC_FN_MOD) {
        tap_code16(KC_RIGHT_CTRL);
      }
      unregister_code16(QK_LAYER_TAP_GET_TAP_KEYCODE(keycode));
    }
  } else if (record->event.pressed) {
    switch (keycode) {
      case SHFT_UNDO: tap_code16(LCMD(KC_Z)); break;
      case CTRL_CUT:  tap_code16(LCMD(KC_X)); break;
      case ALT_COPY:  tap_code16(LCMD(KC_C)); break;
      case CMD_PASTE: tap_code16(LCMD(KC_V)); break;
      case FN_ESC:    tap_code16(KC_ESCAPE); break;
    }
  }
  return false;
}

// Core record processing event
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_complex_tap_mods(keycode, record)) return false;
  if (!process_retro_tap_time(keycode, record)) return false;
  if (!process_mod_overrides(keycode, record)) return false;
  if (!process_sticky_layer(keycode, record)) return false;
  if (!process_macros(keycode, record)) return false;
  return true;
}
