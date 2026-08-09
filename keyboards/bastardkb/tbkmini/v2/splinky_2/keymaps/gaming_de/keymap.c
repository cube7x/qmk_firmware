#include QMK_KEYBOARD_H
#include "keymap_de.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        // left hand
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        KC_LCTL, KC_LGUI, KC_LALT, KC_NO,   KC_NO,   KC_NO,

        // right hand
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT
    )
};

// No special process_record_user needed for Option 1 (host DE layout)
