#include QMK_KEYBOARD_H
#include "leebyron.h"

// TODOs:
//   - Inner column keys shifting up to <>
//   - Add offical inner column keys
//   - Color-coordinated should show layer status for OSL keys
//   - slide+shift inner thumb keys
//   - triple-tap sys-tap (Q) to bootload
//   - retrotap still isnt working

#define KEYMAP_TECHNIK(\
  TOP_L,               TOP_R,\
  MID_L,               MID_R,\
  BOT_L, INN_L, INN_R, BOT_R,\
         THM_L, THM_R) KEYMAP(LAYOUT_ortho_4x12,\
  TOP_L,               KC_NO, KC_NO,               TOP_R,\
  MID_L,               KC_NO, KC_NO,               MID_R,\
  BOT_L,               INN_L, INN_R,               BOT_R,\
  KC_NO, KC_NO, KC_NO, THM_L, THM_R, KC_NO, KC_NO, KC_NO)

// Layer keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_MAIN] = KEYMAP_TECHNIK(
    MAIN_TOP_5C_L,                   MAIN_TOP_5C_R,
    MAIN_MID_5C_L,                   MAIN_MID_5C_R,
    MAIN_BOT_5C_L, BRO_SYS, BRC_SYS, MAIN_BOT_5C_R,
             MAIN_THM_3C_L, MAIN_THM_3C_R),

  [LAYER_SLIDE] = KEYMAP_TECHNIK(
    SLIDE_TOP_5C_L,                   SLIDE_TOP_5C_R,
    SLIDE_MID_5C_L,                   SLIDE_MID_5C_R,
    SLIDE_BOT_5C_L, KC_LPRN, KC_RPRN, SLIDE_BOT_5C_R,
             SLIDE_THM_3C_L, SLIDE_THM_3C_R),

  [LAYER_SYS] = KEYMAP_TECHNIK(
    SYS_TOP_5C_L,                     SYS_TOP_5C_R,
    SYS_MID_5C_L,                     SYS_MID_5C_R,
    SYS_BOT_5C_L, TAB_PREV, TAB_NEXT, SYS_BOT_5C_R,
              SYS_THM_3C_L, SYS_THM_3C_R),
};
