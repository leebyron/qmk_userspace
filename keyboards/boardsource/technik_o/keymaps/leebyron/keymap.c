#include QMK_KEYBOARD_H

// Layer names
enum layers {
  LAYER_MAIN,
  LAYER_SLIDE,
  LAYER_SYS,
};

// Custom handlers in process_record_user()
enum custom_keycodes {
  LINE_SEL = SAFE_RANGE,
  _SLIDE_,
};

// Composite keys using in layers
// System bracket keys
#define BRO_SYS   LT(LAYER_SYS, KC_LBRC)
#define BRC_SYS   LT(LAYER_SYS, KC_RBRC)
// Pinkie mods
#define CTRL_SEMI RCTL_T(KC_SEMICOLON)
#define HYPR_SLSH HYPR_T(KC_SLSH)
#define SHIFT_Z   RSFT_T(KC_Z)
// Thumb keys
#define ALT_TAB   ALT_T(KC_TAB)
#define CMD_BKSP  CMD_T(KC_BSPC)
#define _SHIFT_   OSM(MOD_LSFT)
#define CTRL_ENT  CTL_T(KC_ENT)
// Nav home row mods
#define SHFT_4    RSFT_T(KC_4)
#define CMD_5     RGUI_T(KC_5)
#define ALT_6     RALT_T(KC_6)
#define CTRL_QUOT RCTL_T(KC_QUOT)
// Nav commands
#define UNDO      LCMD(KC_Z)
#define CUT       LCMD(KC_X)
#define COPY      LCMD(KC_C)
#define PASTE     LCMD(KC_V)
// Sys commands
#define TAB_PREV  SGUI(KC_LBRC)
#define TAB_NEXT  SGUI(KC_RBRC)

// Shift-overrides to further customize the SLIDE+SHIFT layer.
const key_override_t left_paren_angle = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_LEFT_ANGLE_BRACKET);
const key_override_t right_paren_angle = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT_PAREN, KC_RIGHT_ANGLE_BRACKET);
const key_override_t keypad_plus_mul = ko_make_basic(MOD_MASK_SHIFT, KC_KP_PLUS, KC_KP_ASTERISK);
const key_override_t keypad_equal_div = ko_make_basic(MOD_MASK_SHIFT, KC_KP_EQUAL, KC_KP_SLASH);
const key_override_t **key_overrides = (const key_override_t *[]){
	&left_paren_angle,
	&right_paren_angle,
	&keypad_plus_mul,
	&keypad_equal_div,
	NULL // terminated array
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
    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     XXXXXXX,            XXXXXXX,  KC_H,     KC_J,     KC_K,     KC_L,     CTRL_SEMI,
    SHIFT_Z,  KC_X,     KC_C,     KC_V,     KC_B,     BRO_SYS,            BRC_SYS,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   HYPR_SLSH,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  ALT_TAB,  CMD_BKSP, _SLIDE_,            _SHIFT_,  KC_SPACE, CTRL_ENT, XXXXXXX,  XXXXXXX,  XXXXXXX),

  [LAYER_SLIDE] = LAYOUT_ortho_4x12(
    KC_GRV,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,  XXXXXXX,            XXXXXXX,  KC_PPLS,  KC_7,     KC_8,     KC_9,     KC_0,
    KC_ESC,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,  XXXXXXX,            XXXXXXX,  KC_MINS,  SHFT_4,   CMD_5,    ALT_6,    CTRL_QUOT,
    UNDO,     CUT,      COPY,     PASTE,    LINE_SEL, KC_LPRN,            KC_RPRN,  KC_PEQL,  KC_1,     KC_2,     KC_3,     KC_BSLS,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,            _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX),

  [LAYER_SYS] = LAYOUT_ortho_4x12(
    QK_BOOT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_BRIU,  XXXXXXX,            XXXXXXX,  XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KC_SLEP,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_BRID,  XXXXXXX,            XXXXXXX,  XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,
    RGB_MOD,  RGB_TOG,  RGB_VAD,  RGB_VAI,  RGB_RMOD, TAB_PREV,           TAB_NEXT, XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,            _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX)
};

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
  if (SLIDE_state != SLIDE_UP && keycode != _SLIDE_ && !IS_QK_MODS(keycode) && !IS_QK_ONE_SHOT_MOD(keycode)) {
    // On after press of a another key during the One-shot state, revert back to the
    // up state and un-toggle the layer state.
    if (SLIDE_state == SLIDE_TAPPED) {
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

//  Override the RGB state as a way to indicate keyboard modal states.
// This highlights arrows and numpads when they are available, it also highlights
// the LSHIFT key based on which state it's in (held, OSM, caps-word).
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  uint8_t layer = get_highest_layer(layer_state|default_layer_state);
  for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
      uint8_t index = g_led_config.matrix_co[row][col];
      if (index >= led_min && index < led_max && index != NO_LED) {
        // Get the keycode at this position, following fall-throughs.
        // TODO: Is this right? Surely there's a function that does this for us
        uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col,row});
        if (keycode == _______) {
          keycode = keymap_key_to_keycode(LAYER_MAIN, (keypos_t){col,row});
        }
        // Color the state of the LSHIFT key based on double-tap to caps word.
        if (keycode == KC_LSFT || keycode == OSM(MOD_LSFT)) {
          if (is_caps_word_on()) {
            rgb_matrix_set_color(index, RGB_GREEN);
          } else if (get_mods() & MOD_MASK_SHIFT) {
            rgb_matrix_set_color(index, RGB_BLUE);
          } else if (get_oneshot_mods() & MOD_MASK_SHIFT) {
            rgb_matrix_set_color(index, RGB_RED);
          }
        }
        // Otherwise get the basic keycode
        if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
          keycode &= QK_BASIC_MAX;
        }
        if (keycode == XXXXXXX)  {
          // Black out dead keys
          rgb_matrix_set_color(index, RGB_OFF);
        } else if (keycode >= KC_RIGHT && keycode <= KC_UP) {
          // Color in arrows
          rgb_matrix_set_color(index, RGB_CYAN);
        } else if (keycode >= KC_1 && keycode <= KC_0) {
          // Color in numbers
          rgb_matrix_set_color(index, RGB_GOLDENROD);
        } else if (keycode >= KC_F1 && keycode <= KC_F12) {
          // Color in functions
          rgb_matrix_set_color(index, RGB_RED);
        }
      }
    }
  }
  return true;
}
