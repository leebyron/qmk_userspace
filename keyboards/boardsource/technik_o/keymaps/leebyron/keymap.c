#include QMK_KEYBOARD_H
#include "features/shift_override.h"

// TODOs:
//   - Tap dance mods on the zxcv nav layer
//   - Simplify the slide key
//   - Add a full set of combos
//   - Oryx & 6th columns
//   - Draw it out

// Layer names
enum layers {
  LAYER_MAIN,
  LAYER_SLIDE,
  LAYER_SYS,
};

// Custom handlers in process_record_user()
enum custom_keycodes {
  // LINE_SEL = SAFE_RANGE,
  _SLIDE_,
};

// Composite keys using in layers
// System bracket keys
#define BRO_SYS   LT(LAYER_SYS, KC_LBRC)
#define BRC_SYS   LT(LAYER_SYS, KC_RBRC)
// Thumb keys
#define ALT_TAB   ALT_T(KC_TAB)
#define CMD_BKSP  CMD_T(KC_BSPC)
#define _SHIFT_   OSM(MOD_LSFT)
#define CTRL_ENT  CTL_T(KC_ENT)
// Main lower row mods
#define SHIFT_Z   LSFT_T(KC_Z)
#define CTRL_X    LCTL_T(KC_X)
#define ALT_C     LALT_T(KC_C)
#define CMD_V     LGUI_T(KC_V)
#define CMD_M     LGUI_T(KC_M)
#define ALT_COMMA LALT_T(KC_COMMA)
#define CTRL_DOT  LCTL_T(KC_DOT)
#define SHFT_SLSH LSFT_T(KC_SLASH)
#define HYPR_QUOT HYPR_T(KC_QUOT)
// Nav lower row mods
#define CMD_1     RGUI_T(KC_1)
#define ALT_2     RALT_T(KC_2)
#define CTRL_3    RCTL_T(KC_3)
#define SHFT_BKSL RSFT_T(KC_BACKSLASH)
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

// // Shift-overrides to further customize the SLIDE+SHIFT layer.
// // Main layer punctuation
// const key_override_t comma_semicolon = ko_make_basic(MOD_MASK_SHIFT, ALT_COMMA, KC_SEMICOLON);
// const key_override_t dot_colon = ko_make_basic(MOD_MASK_SHIFT, CTRL_DOT, KC_COLON);
// // Condensed numpad
// const key_override_t keypad_zero_dot = ko_make_basic(MOD_MASK_SHIFT, KC_KP_0, KC_KP_DOT);
// const key_override_t keypad_nine_slash = ko_make_basic(MOD_MASK_SHIFT, KC_KP_9, KC_KP_SLASH);
// // Paired punctuation
// const key_override_t paren_pair = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);
// const key_override_t brace_pair = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
// const key_override_t angle_pair = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET);
// const key_override_t **key_overrides = (const key_override_t *[]){
// 	&comma_semicolon,
// 	&dot_colon,
// 	&keypad_zero_dot,
// 	&keypad_nine_slash,
// 	&paren_pair,
// 	&brace_pair,
// 	&angle_pair,
// 	NULL // terminated array
// };

// Shift-overrides to further customize the SHIFT and SLIDE+SHIFT layers.
const shift_override_t shift_overrides[] = {
  {ALT_COMMA, KC_SEMICOLON},
  {CTRL_DOT,KC_COLON},
  {KC_KP_0, KC_KP_DOT},
  {KC_KP_9, KC_KP_SLASH},
  {KC_LEFT_PAREN, KC_RIGHT_PAREN},
  {KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE},
  {KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET},
  END_OF_SHIFT_OVERRIDES
};

// Combos
const uint16_t PROGMEM combo_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_mc[] = {KC_M, KC_COMM, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_df, KC_LEFT_PAREN),
    COMBO(combo_cv, KC_RIGHT_PAREN),
    COMBO(combo_jk, KC_MINUS),
    COMBO(combo_mc, KC_UNDERSCORE),
};

// Layer keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_MAIN] = LAYOUT_ortho_4x12(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     XXXXXXX,            XXXXXXX,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     XXXXXXX,            XXXXXXX,  KC_H,     KC_J,     KC_K,     KC_L,     HYPR_QUOT,
    SHIFT_Z,  CTRL_X,   ALT_C,    CMD_V,    KC_B,     BRO_SYS,            BRC_SYS,  KC_N,     CMD_M,    ALT_COMMA,CTRL_DOT, SHFT_SLSH,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  ALT_TAB,  CMD_BKSP, _SLIDE_,            _SHIFT_,  KC_SPACE, CTRL_ENT, XXXXXXX,  XXXXXXX,  XXXXXXX),

  [LAYER_SLIDE] = LAYOUT_ortho_4x12(
    KC_TAB,   KC_LBRC,  KC_UP,    KC_RBRC,  KC_BRACE, XXXXXXX,            XXXXXXX,  KC_PPLS,  KC_7,     KC_8,     KC_P9,    KC_GRV,
    SYS_ESC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PAREN, XXXXXXX,            XXXXXXX,  KC_MINS,  KC_4,     KC_5,     KC_6,     KC_P0,
    UNDO,     CUT,      COPY,     PASTE,    KC_ANGLE, KC_LPRN,            KC_RPRN,  KC_EQUAL, CMD_1,    ALT_2,    CTRL_3,   SHFT_BKSL,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,            _______,  KC_ENTER, _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

  [LAYER_SYS] = LAYOUT_ortho_4x12(
    QK_BOOT,  KC_BRID,  KC_PGUP,  KC_BRIU,  KC_MFFD,  XXXXXXX,            XXXXXXX,  KC_VOLU,  KC_F7,    KC_F8,    KC_F9,    KC_F10,
    _______,  KC_HOME,  KC_PGDN,  KC_END,   KC_MRWD,  XXXXXXX,            XXXXXXX,  KC_VOLD,  KC_F4,    KC_F5,    KC_F6,    KC_F11,
    RGB_MOD,  RGB_TOG,  RGB_VAD,  RGB_VAI,  KC_MPLY,  TAB_PREV,           TAB_NEXT, KC_MUTE,  KC_F1,    KC_F2,    KC_F3,    KC_F12,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,            _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX)
};

// Use permissive hold on the thumb keys
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_BKSP:
    case ALT_TAB:
    case CTRL_ENT:
      return true;
    default:
      return false;
  }
}

// _SLIDE_ is a custom key that adjusts the LAYER_SLIDE state. It is a combination of
// a Layer one-shot-modifier and a tap-toggle:
//  - If held, it acts as a layer momentary toggle.
//  - If tapped, it acts as a one-shot layer toggle, applying to the next non-mod keypress.
//  - If double-tapped, it toggles the layer state on or off.
//
// This behavior always operates as a toggle - so when double-tapped on, the key then works
// exactly the same way, but applies disabling the layer.
enum {
  SLIDE_UP,
  SLIDE_HELD,
  SLIDE_TAPPED,
};

static uint8_t  SLIDE_state     = SLIDE_UP;
static uint16_t SLIDE_hld_timer = 0;
static uint16_t SLIDE_dbl_timer = 0;

void process_slide(uint16_t keycode, keyrecord_t *record) {
  // On release
  if (!record->event.pressed) {
    // On releasing a held state
    if (SLIDE_state == SLIDE_HELD) {
      // On releasing a held state after the hold-timer has expired, treat
      // this as typical momentary toggle, reverting back to the up state
      // and un-toggling the layer state.
      if (timer_expired(record->event.time, SLIDE_hld_timer)) {
        SLIDE_state = SLIDE_UP;
        layer_invert(LAYER_SLIDE);
      } else {
        // On releasing a held state within the hold-timer, consider this
        // a "one-shot" tap, and enter the tapped state and set a new timer
        // indicating the duration of the one-shot state.
        SLIDE_state = SLIDE_TAPPED;
        SLIDE_dbl_timer = record->event.time + ONESHOT_TIMEOUT;
      }
    }
    return;
  }

  // On press in the tapped  state, then this is a double-tap.
  if (SLIDE_state == SLIDE_TAPPED) {
    // On press of a double-tap after the double-timer has expired, treat
    // this as a cancelation of the One-shot state, reverting back to the
    // up state and un-toggling the layer state.
    if (timer_expired(record->event.time, SLIDE_dbl_timer)) {
      SLIDE_state = SLIDE_UP;
      layer_invert(LAYER_SLIDE);
    } else {
      // On press of a double-tap within the double-timer, consider this a
      // permenant layer toggle. Since it was just in the tapped state the
      // layer has already been toggled, so just do not un-toggle it while
      // returning to the up state.
      SLIDE_state = SLIDE_UP;
    }
    return;
  }

  // Otherwise  this is a press from the up state. Enter the held state,
  // toggling the layer, and setting a timer for the tapping term to later
  // determine if this is a momentary or OSM key press.
  SLIDE_state = SLIDE_HELD;
  SLIDE_hld_timer = record->event.time + TAPPING_TERM;
  layer_invert(LAYER_SLIDE);
}

// After processing an applicable key record, disable the one-shot SLIDE state
// if it was applied.
void post_process_slide(uint16_t keycode, keyrecord_t *record) {
  // On after press of a different non-mod key while in some Slide state.
  if (SLIDE_state != SLIDE_UP && keycode != _SLIDE_) {
    // On after press of a another key during the One-shot state, revert back to the
    // up state and un-toggle the layer state.
    if (SLIDE_state == SLIDE_TAPPED && !IS_QK_ONE_SHOT_MOD(keycode)) {
      SLIDE_state = SLIDE_UP;
      layer_invert(LAYER_SLIDE);
    } else if (SLIDE_state == SLIDE_HELD) {
      // On after press of another key during the Momentary held state,
      // cancel the timer that would have enabled the one-shot tapped state ensuring
      // the behavior is restricted to momentary-only.
      SLIDE_hld_timer = 0;
    }
  }
}

// Check before using Slide layer state which may be timer-sensitive.
void check_timeout_slide(uint16_t moment) {
  // After the double-timer has expired while in the tapped state, revert back to the
  // up state and un-toggle the layer state. This only needs to be called before an
  // observable event (like a key record or RGB frame).
  if (SLIDE_state == SLIDE_TAPPED && timer_expired(moment, SLIDE_dbl_timer)) {
    SLIDE_state = SLIDE_UP;
    layer_invert(LAYER_SLIDE);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_shift_overrides(keycode, record)) return false;

  switch (keycode) {
  case LINE_SEL:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)SS_LSFT(SS_TAP(X_RGHT)SS_TAP(X_RGHT))));
    }
    break;
  case _SLIDE_:
    process_slide(keycode, record);
    break;
  }
  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
  post_process_slide(keycode, record);
}

// Disable slide before processing a record if timed out.
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  check_timeout_slide(record->event.time);
  return true;
}

// This is very hacky. We check for the timeout as part of record pre-processing,
// however if we want RGB feedback to appear correctly, we need to check for
// a timeout before flushing LED states as well.
bool rgb_matrix_indicators_user(void) {
  check_timeout_slide(timer_read());
  return true;
}

// Add __SLIDE__ to caps word
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_DOLLAR: // For JS
        case _SLIDE_: // For Slide layer // TODO: If _SLIDE_ was a real Layer key with overridden behavior, this would be much simpler.
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

// A mostly failed attempt at resetting LED state after rebooting
void keyboard_post_init_user(void) {
  rgb_matrix_set_color_all(RGB_OFF);
  rgb_matrix_reload_from_eeprom();
}
