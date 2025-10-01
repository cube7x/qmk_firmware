// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_2x6(
        XXXXXXX,       KC_F,    LCTL_T(KC_B),    KC_C,    KC_L,    XXXXXXX,
        KC_COMM,    KC_LSFT,    LCTL_T(KC_U),    KC_T,    KC_M,    LT(1, KC_ESC)
    ),
    [1] = LAYOUT_ortho_2x6(
        KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    XXXXXXX,
        KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    XXXXXXX
    )
};
