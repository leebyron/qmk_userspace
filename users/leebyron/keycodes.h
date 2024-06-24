#pragma once
#include QMK_KEYBOARD_H
#include "layers.h"

// Composite keys used in layers

// System bracket keys
#define BRO_SYS   LT(LAYER_SYS, KC_LBRC)
#define BRC_SYS   LT(LAYER_SYS, KC_RBRC)
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
#define MOD_RHYPR (MOD_RGUI | MOD_RALT | MOD_RCTL | MOD_RSFT)
#define HYPR_QUOT MT(MOD_RHYPR, KC_QUOTE)
// Nav lower row mods
#define CMD_1     RGUI_T(KC_1)
#define ALT_2     RALT_T(KC_2)
#define CTRL_3    RCTL_T(KC_3)
#define SHFT_BKSL RSFT_T(KC_BACKSLASH)
#define HYPR_TICK MT(MOD_RHYPR, KC_GRAVE)
// Nav layer holds
#define SYS_ESC   LT(LAYER_SYS, KC_ESCAPE)
// Nav commands
#define UNDO      LCMD(KC_Z)
#define CUT       LCMD(KC_X)
#define COPY      LCMD(KC_C)
#define PASTE     LCMD(KC_V)
// Sys commands
#define TAB_PREV  SGUI(KC_LBRC)
#define TAB_NEXT  SGUI(KC_RBRC)
// Paired punct
#define KC_PAREN  KC_LEFT_PAREN
#define KC_BRACE  KC_LEFT_CURLY_BRACE
#define KC_ANGLE  KC_LEFT_ANGLE_BRACKET
