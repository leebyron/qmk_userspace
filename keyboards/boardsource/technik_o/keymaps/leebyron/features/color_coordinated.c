#include QMK_KEYBOARD_H

//  Override the RGB state as a way to indicate keyboard modal states.
// This highlights arrows and numpads when they are available, it also highlights
// the LSHIFT key based on which state it's in (held, OSM, caps-word).
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
      uint8_t index = g_led_config.matrix_co[row][col];
      if (index >= led_min && index < led_max && index != NO_LED) {
        // Get the keycode at this position, following fall-throughs.
        keypos_t key = MAKE_KEYPOS(row, col);
        uint16_t keycode = keymap_key_to_keycode(layer_switch_get_layer(key), key);
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
        } else if ((keycode >= KC_1 && keycode <= KC_0) || (keycode >= KC_P1 && keycode <= KC_P0)) {
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
