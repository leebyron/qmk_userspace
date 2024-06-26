#pragma once
#include QMK_KEYBOARD_H

typedef struct {
  uint8_t mod_mask;
  uint16_t keycode;
  uint16_t mod_keycode;
} mod_override_t;

#define END_OF_MOD_OVERRIDES {0,0,0}

bool process_mod_overrides(uint16_t keycode, keyrecord_t *record);

// Define this in your keymap as an array of {mod, keycode, replacement_code}
// ending with END_OF_MOD_OVERRIDES
extern const mod_override_t mod_overrides[];
