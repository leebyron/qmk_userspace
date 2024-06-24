#include QMK_KEYBOARD_H
#include "macros.h"

bool process_macros(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _SLIDE_:
      if (!record->event.pressed && record->tap.count == 2) {
        reset_oneshot_layer();
        set_oneshot_layer(LAYER_SLIDE, ONESHOT_TOGGLED);
        return false;
      }
    break;
    case MCR_PAREN_PAIR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("90")SS_TAP(X_LEFT));
      }
      break;
    case MCR_BRACE_PAIR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT("[]")SS_TAP(X_LEFT));
      }
      break;
    case MCR_ANGLE_PAIR:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(",.")SS_TAP(X_LEFT));
      }
      break;
    case MCR_BRACKET_PAIR:
      if (record->event.pressed) {
        SEND_STRING("[]"SS_TAP(X_LEFT));
      }
      break;
    case MCR_NOT_EQUAL:
      if (record->event.pressed) {
        SEND_STRING("!=");
      }
      break;
    case MCR_SGL_ARROW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      break;
    case MCR_DBL_ARROW:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      break;
  }
  return true;
}
