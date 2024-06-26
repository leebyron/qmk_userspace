#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

#define MOD_RHYPR (MOD_RGUI | MOD_RALT | MOD_RCTL | MOD_RSFT)

// Hacked keys - use software like Karabiner to remap
#define KC_FN_MOD  KC_PRINT_SCREEN

// Composite keys used in layers

// Inner column System bracket keys
#define BRO_SYS   LT(LAYER_SYS, KC_LBRC)
#define BRC_SYS   LT(LAYER_SYS, KC_RBRC)
#define TAB_PREV  SGUI(KC_LBRC)
#define TAB_NEXT  SGUI(KC_RBRC)
// Thumb keys
#define ALT_TAB   LALT_T(KC_TAB)
#define CMD_BKSP  LCMD_T(KC_BSPC)
#define CMD_SPACE RCMD_T(KC_SPACE)
#define CMD_ENTER RCMD_T(KC_ENTER)
#define _SLIDE_   OSL(LAYER_SLIDE)
#define _SHIFT_   OSM(MOD_LSFT)
#define CTRL_ENT  RCTL_T(KC_ENT)
// Main lower row mods
#define SHIFT_Z   LSFT_T(KC_Z)
#define CTRL_X    LCTL_T(KC_X)
#define ALT_C     LALT_T(KC_C)
#define CMD_V     LGUI_T(KC_V)
#define CMD_M     RGUI_T(KC_M)
#define ALT_COMMA RALT_T(KC_COMMA)
#define CTRL_DOT  RCTL_T(KC_DOT)
#define SHFT_SLSH RSFT_T(KC_SLASH)
#define HYPR_QUOT MT(MOD_RHYPR, KC_QUOTE)
// Nav lower row mods
#define SHFT_UNDO LT(0, KC_LEFT_SHIFT)
#define CTRL_CUT  LT(0, KC_LEFT_CTRL)
#define ALT_COPY  LT(0, KC_LEFT_ALT)
#define CMD_PASTE LT(0, KC_LEFT_GUI)
#define CMD_1     RGUI_T(KC_1)
#define ALT_2     RALT_T(KC_2)
#define CTRL_3    RCTL_T(KC_3)
#define SHFT_BKSL RSFT_T(KC_BACKSLASH)
#define HYPR_TICK MT(MOD_RHYPR, KC_GRAVE)
// Pinkie mods
#define SYS_TAB   LT(LAYER_SYS, KC_TAB)
#define CTRL_ESC  LCTL_T(KC_ESCAPE)
#define FN_ESC    LT(0, KC_FN_MOD)
#define HYPR_ENT  MT(MOD_RHYPR, KC_ENTER)
#define L_SPACECDT QK_SPACE_CADET_LEFT_SHIFT_PARENTHESIS_OPEN
#define R_SPACECDT QK_SPACE_CADET_RIGHT_SHIFT_PARENTHESIS_CLOSE
#define LSFT_BRC  LSFT_T(KC_LBRC)
#define RSFT_BRC  RSFT_T(KC_RBRC)
// Paired punct
#define KC_PAREN  KC_LEFT_PAREN
#define KC_BRACE  KC_LEFT_CURLY_BRACE
#define KC_ANGLE  KC_LEFT_ANGLE_BRACKET
