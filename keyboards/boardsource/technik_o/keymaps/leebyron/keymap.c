#include QMK_KEYBOARD_H
#include "leebyron.h"

// TODOs:
//   - Tap dance mods on the zxcv nav layer
//   - Simplify the slide key
//   - Add a full set of combos
//   - "fn" hold key
//   - Oryx & 6th columns
//   - Inner column keys
//   - Draw it out
//   - Color-coordinated should show layer status for OSL keys

// TODO: this must have a better way to do this
KEY_COMBOS()

#define LAYOUT_4x12(...) LAYOUT_ortho_4x12(__VA_ARGS__)

// Layer keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_MAIN] = LAYOUT_4x12(
    MAIN_TOP_5C_L,                XXXXXXX,                  XXXXXXX,      MAIN_TOP_5C_R,
    MAIN_MID_5C_L,                XXXXXXX,                  XXXXXXX,      MAIN_MID_5C_R,
    MAIN_BOT_5C_L,                BRO_SYS,                  BRC_SYS,      MAIN_BOT_5C_R,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  MAIN_THM_3C_L,            MAIN_THM_3C_R,XXXXXXX,  XXXXXXX,  XXXXXXX),

  [LAYER_SLIDE] = LAYOUT_4x12(
    SLIDE_TOP_5C_L,               XXXXXXX,                  XXXXXXX,      SLIDE_TOP_5C_R,
    SLIDE_MID_5C_L,               XXXXXXX,                  XXXXXXX,      SLIDE_MID_5C_R,
    SLIDE_BOT_5C_L,               KC_LPRN,                  KC_RPRN,      SLIDE_BOT_5C_R,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  SLIDE_THM_3C_L,           SLIDE_THM_3C_R,XXXXXXX,  XXXXXXX,  XXXXXXX),

  [LAYER_SYS] = LAYOUT_4x12(
    SYS_TOP_5C_L,                 XXXXXXX,                  XXXXXXX,      SYS_TOP_5C_R,
    SYS_MID_5C_L,                 XXXXXXX,                  XXXXXXX,      SYS_MID_5C_R,
    SYS_BOT_5C_L,                 KC_LPRN,                  KC_RPRN,      SYS_BOT_5C_R,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  SYS_THM_3C_L,             SYS_THM_3C_R, XXXXXXX,  XXXXXXX,  XXXXXXX),
};
