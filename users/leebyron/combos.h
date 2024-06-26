#pragma once
#include QMK_KEYBOARD_H

// Fake, we provide the functions below
extern combo_t key_combos[1];

uint16_t combo_count(void);
combo_t* combo_get(uint16_t combo_idx);
