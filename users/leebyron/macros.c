#include QMK_KEYBOARD_H
#include "macros.h"

bool process_macros(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MCR_PAREN_PAIR:
      if (record->event.pressed) {
        SEND_STRING("()"SS_TAP(X_LEFT));
      }
      break;
    case MCR_BRACE_PAIR:
      if (record->event.pressed) {
        SEND_STRING("{}"SS_TAP(X_LEFT));
      }
      break;
    case MCR_ANGLE_PAIR:
      if (record->event.pressed) {
        SEND_STRING("<>"SS_TAP(X_LEFT));
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
    case MCR_COLON_EQUAL:
      if (record->event.pressed) {
        SEND_STRING(":=");
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
    case MCR_LESS_THAN:
      if (record->event.pressed) {
        SEND_STRING("<=");
      }
      break;
    case MCR_GREATER_THAN:
      if (record->event.pressed) {
        SEND_STRING(">=");
      }
      break;
  }
  return true;
}
