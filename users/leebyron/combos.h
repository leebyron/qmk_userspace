#pragma once
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "macros.h"

// Combos
#define COMBO_KC(name, ...) const uint16_t PROGMEM name[] = {__VA_ARGS__, COMBO_END}

#define KEY_COMBOS() \
// Left hand
COMBO_KC(combo_df, KC_D, KC_F);\
COMBO_KC(combo_fg, KC_F, KC_G);\
COMBO_KC(combo_dg, KC_D, KC_G);\
COMBO_KC(combo_er, KC_E, KC_R);\
COMBO_KC(combo_rt, KC_R, KC_T);\
COMBO_KC(combo_et, KC_E, KC_T);\
COMBO_KC(combo_cv, ALT_C, CMD_V);\
COMBO_KC(combo_vb, CMD_V, KC_B);\
COMBO_KC(combo_cb, ALT_C, KC_B);\
COMBO_KC(combo_sd, KC_S, KC_D);\
COMBO_KC(combo_we, KC_W, KC_E);\
COMBO_KC(combo_sf, KC_S, KC_F);\
COMBO_KC(combo_qw, KC_Q, KC_W);\
COMBO_KC(combo_as, KC_A, KC_S);\
// Right hand
COMBO_KC(combo_yu, KC_Y, KC_U);\
COMBO_KC(combo_ui, KC_U, KC_I);\
COMBO_KC(combo_io, KC_I, KC_O);\
// COMBO_KC(combo_op, KC_O, KC_P);
COMBO_KC(combo_hj, KC_H, KC_J);\
COMBO_KC(combo_jk, KC_J, KC_K);\
COMBO_KC(combo_kl, KC_K, KC_L);\
COMBO_KC(combo_lq, KC_L, HYPR_QUOT);\
COMBO_KC(combo_nm, KC_N, CMD_M);\
COMBO_KC(combo_mc, CMD_M, ALT_COMMA);\
COMBO_KC(combo_nc, KC_N, ALT_COMMA);\
COMBO_KC(combo_cd, ALT_COMMA, CTRL_DOT);\
COMBO_KC(combo_md, CMD_M, CTRL_DOT);\
COMBO_KC(combo_ds, CTRL_DOT, SHFT_SLSH);\
// Both hands
COMBO_KC(combo_vj, CMD_V, KC_J);\
COMBO_KC(combo_vm, CMD_V, CMD_M);\
COMBO_KC(combo_cm, ALT_C, CMD_M);\
COMBO_KC(combo_bm, KC_B, CMD_M);\

combo_t key_combos[] = {\
  // Left hand
  COMBO(combo_df, KC_LEFT_PAREN),\
  COMBO(combo_fg, KC_RIGHT_PAREN),\
  COMBO(combo_dg, MCR_PAREN_PAIR),\
  COMBO(combo_er, KC_LEFT_CURLY_BRACE),\
  COMBO(combo_rt, KC_RIGHT_CURLY_BRACE),\
  COMBO(combo_et, MCR_BRACE_PAIR),\
  COMBO(combo_cv, KC_LEFT_ANGLE_BRACKET),\
  COMBO(combo_vb, KC_RIGHT_ANGLE_BRACKET),\
  COMBO(combo_cb, MCR_ANGLE_PAIR),\
  COMBO(combo_sd, KC_LEFT_BRACKET),\
  COMBO(combo_we, KC_RIGHT_BRACKET),\
  COMBO(combo_sf, MCR_BRACKET_PAIR),\
  COMBO(combo_qw, KC_TAB),\
  COMBO(combo_as, KC_ESCAPE),\
  // Right hand
  COMBO(combo_yu, KC_AMPERSAND),\
  COMBO(combo_ui, KC_PLUS),\
  COMBO(combo_io, KC_SEMICOLON),\
  // COMBO(combo_op, KC_BACKSPACE),
  COMBO(combo_hj, KC_PIPE),\
  COMBO(combo_jk, KC_MINUS),\
  COMBO(combo_kl, KC_UNDERSCORE),\
  COMBO(combo_lq, KC_ENTER),\
  COMBO(combo_nm, KC_COLON),\
  COMBO(combo_mc, KC_EQUAL),\
  COMBO(combo_nc, MCR_COLON_EQUAL),\
  COMBO(combo_cd, KC_EXCLAIM),\
  COMBO(combo_md, MCR_NOT_EQUAL),\
  COMBO(combo_ds, KC_QUESTION),\
  // Both hands
  COMBO(combo_vj, MCR_SGL_ARROW),\
  COMBO(combo_vm, MCR_DBL_ARROW),\
  COMBO(combo_cm, MCR_LESS_THAN),\
  COMBO(combo_bm, MCR_GREATER_THAN),\
};
