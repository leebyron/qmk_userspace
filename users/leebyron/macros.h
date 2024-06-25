#pragma once
#include QMK_KEYBOARD_H

// Macro keys
enum macro_keycodes {
  MCR_PAREN_PAIR = SAFE_RANGE,
  MCR_BRACE_PAIR,
  MCR_ANGLE_PAIR,
  MCR_BRACKET_PAIR,
  MCR_NOT_EQUAL,
  MCR_COLON_EQUAL,
  MCR_SGL_ARROW,
  MCR_DBL_ARROW,
  MCR_LESS_THAN,
  MCR_GREATER_THAN,
};

bool process_macros(uint16_t keycode, keyrecord_t *record);
