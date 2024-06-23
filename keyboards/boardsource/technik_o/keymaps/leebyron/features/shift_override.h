#pragma once
#include QMK_KEYBOARD_H

typedef struct {
  uint16_t keycode;
  uint16_t shifted_keycode;
} shift_override_t;

#define END_OF_SHIFT_OVERRIDES {0,0}

extern const shift_override_t shift_overrides[];

bool process_shift_overrides(uint16_t keycode, keyrecord_t *record);
