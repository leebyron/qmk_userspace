#pragma once
#include QMK_KEYBOARD_H

#include "layers.h"
#include "keycodes.h"
#include "combos.h"

#define KEYMAP(LAYOUT, ...) LAYOUT(__VA_ARGS__)

// Main layer
#define MAIN_NUM_5C_L               KC_1,     KC_2,     KC_3,     KC_4,     KC_5
#define MAIN_TOP_5C_L               KC_Q,     KC_W,     KC_E,     KC_R,     KC_T
#define MAIN_MID_5C_L               KC_A,     KC_S,     KC_D,     KC_F,     KC_G
#define MAIN_BOT_5C_L               SHIFT_Z,  CTRL_X,   ALT_C,    CMD_V,    KC_B
#define MAIN_NUM_6C_L     KC_GRAVE, MAIN_NUM_5C_L
#define MAIN_TOP_6C_L     KC_TAB,   MAIN_TOP_5C_L
#define MAIN_MID_6C_L     KC_ESC,   MAIN_MID_5C_L
#define MAIN_BOT_6C_L     QK_SPACE_CADET_LEFT_SHIFT_PARENTHESIS_OPEN,  MAIN_BOT_5C_L

#define MAIN_NUM_5C_R     KC_6,     KC_7,     KC_8,     KC_9,     KC_0
#define MAIN_TOP_5C_R     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P
#define MAIN_MID_5C_R     KC_H,     KC_J,     KC_K,     KC_L,     HYPR_QUOT
#define MAIN_BOT_5C_R     KC_N,     CMD_M,    ALT_COMMA,CTRL_DOT, SHFT_SLSH
#define MAIN_NUM_6C_R     MAIN_NUM_5C_R,      KC_EQUAL
#define MAIN_TOP_6C_R     MAIN_TOP_5C_R,      KC_MINS
#define MAIN_MID_6C_R     MAIN_MID_5C_R,      MT(MOD_RHYPR, KC_ENTER)
#define MAIN_BOT_6C_R     MAIN_BOT_5C_R,      QK_SPACE_CADET_RIGHT_SHIFT_PARENTHESIS_CLOSE

#define MAIN_THM_2C_L               CMD_BKSP, _SLIDE_
#define MAIN_THM_3C_L     ALT_TAB,  MAIN_THM_2C_L

#define MAIN_THM_2C_R     _SHIFT_,  CMD_SPACE
#define MAIN_THM_3C_R     MAIN_THM_2C_R,      CTRL_ENT

// Slide layer
#define SLIDE_NUM_5C_L              KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5
#define SLIDE_TOP_5C_L              KC_TAB,   KC_LBRC,  KC_UP,    KC_RBRC,  KC_BRACE
#define SLIDE_MID_5C_L              SYS_ESC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PAREN
#define SLIDE_BOT_5C_L              UNDO,     CUT,      COPY,     PASTE,    KC_ANGLE
#define SLIDE_NUM_6C_L    KC_SLEP,  SLIDE_NUM_5C_L
#define SLIDE_TOP_6C_L    _______,  SLIDE_TOP_5C_L
#define SLIDE_MID_6C_L    _______,  SLIDE_MID_5C_L
#define SLIDE_BOT_6C_L    LSFT_T(KC_LBRC),  SLIDE_BOT_5C_L

#define SLIDE_NUM_5C_R    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10
#define SLIDE_TOP_5C_R    KC_PPLS,  KC_7,     KC_8,     KC_P9,    KC_P0
#define SLIDE_MID_5C_R    KC_MINS,  KC_4,     KC_5,     KC_6,     HYPR_TICK
#define SLIDE_BOT_5C_R    KC_EQUAL, CMD_1,    ALT_2,    CTRL_3,   SHFT_BKSL
#define SLIDE_NUM_6C_R    SLIDE_NUM_5C_R,     KC_F11
#define SLIDE_TOP_6C_R    SLIDE_TOP_5C_R,     KC_F12
#define SLIDE_MID_6C_R    SLIDE_MID_5C_R,     _______
#define SLIDE_BOT_6C_R    SLIDE_BOT_5C_R,     RSFT_T(KC_RBRC)

#define SLIDE_THM_2C_L              _______,  _______
#define SLIDE_THM_3C_L    _______,  SLIDE_THM_2C_L

#define SLIDE_THM_2C_R    _______,  CMD_ENTER
#define SLIDE_THM_3C_R    SLIDE_THM_2C_R,     _______

// System layer
#define SYS_NUM_5C_L                KC_BRID,  KC_BRIU,  KC_MRWD,  KC_MPLY,  KC_MFFD
#define SYS_TOP_5C_L                QK_BOOT,  KC_BRID,  KC_PGUP,  KC_BRIU,  KC_MFFD
#define SYS_MID_5C_L                _______,  KC_HOME,  KC_PGDN,  KC_END,   KC_MRWD
#define SYS_BOT_5C_L                RGB_MOD,  RGB_TOG,  RGB_VAD,  RGB_VAI,  KC_MPLY
#define SYS_NUM_6C_L      QK_BOOT,  SYS_NUM_5C_L
#define SYS_TOP_6C_L      _______,  SYS_TOP_5C_L
#define SYS_MID_6C_L      _______,  SYS_MID_5C_L
#define SYS_BOT_6C_L      _______,  SYS_BOT_5C_L

#define SYS_NUM_5C_R      KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_VAD,  RGB_VAI
#define SYS_TOP_5C_R      KC_VOLU,  KC_F7,    KC_F8,    KC_F9,    KC_F10
#define SYS_MID_5C_R      KC_VOLD,  KC_F4,    KC_F5,    KC_F6,    KC_F11
#define SYS_BOT_5C_R      KC_MUTE,  KC_F1,    KC_F2,    KC_F3,    KC_F12
#define SYS_NUM_6C_R      SYS_NUM_5C_R,       RGB_MOD
#define SYS_TOP_6C_R      SYS_TOP_5C_R,       RGB_TOG
#define SYS_MID_6C_R      SYS_MID_5C_R,       _______
#define SYS_BOT_6C_R      SYS_BOT_5C_R,       _______

#define SYS_THM_2C_L                _______,  _______
#define SYS_THM_3C_L      _______,  SYS_THM_2C_L

#define SYS_THM_2C_R      _______,  _______
#define SYS_THM_3C_R      SYS_THM_2C_R,       _______
