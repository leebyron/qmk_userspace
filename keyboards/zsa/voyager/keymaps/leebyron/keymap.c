#include QMK_KEYBOARD_H
#include "leebyron.h"

// TODO: this must have a better way to do this
KEY_COMBOS()

#define _LAYOUT(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_MAIN] = _LAYOUT(
      MAIN_NUM_6C_L, MAIN_NUM_6C_R,
      MAIN_TOP_6C_L, MAIN_TOP_6C_R,
      MAIN_MID_6C_L, MAIN_MID_6C_R,
      MAIN_BOT_6C_L, MAIN_BOT_6C_R,
      MAIN_THM_2C_L, MAIN_THM_2C_R
  ),
  [LAYER_SLIDE] = _LAYOUT(
      SLIDE_NUM_6C_L, SLIDE_NUM_6C_R,
      SLIDE_TOP_6C_L, SLIDE_TOP_6C_R,
      SLIDE_MID_6C_L, SLIDE_MID_6C_R,
      SLIDE_BOT_6C_L, SLIDE_BOT_6C_R,
      SLIDE_THM_2C_L, SLIDE_THM_2C_R
  ),
    [LAYER_SYS] = _LAYOUT(
      SYS_NUM_6C_L, SYS_NUM_6C_R,
      SYS_TOP_6C_L, SYS_TOP_6C_R,
      SYS_MID_6C_L, SYS_MID_6C_R,
      SYS_BOT_6C_L, SYS_BOT_6C_R,
      SYS_THM_2C_L, SYS_THM_2C_R
    ),
};
