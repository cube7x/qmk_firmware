/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_german.h>

#define LT_SPC LT(1,KC_SPC)
#define LT_DEL LT(2,KC_DEL)
#define LT_0 LT(3,KC_0)
#define LT_ENT LT(3,KC_ENT)
#define LT_ESC LT(5,KC_ESC)

#define LC_BSPC LCTL_T(KC_BSPC)
#define LC_EXLM LCTL_T(DE_EXLM)
#define LA_ENT LALT_T(KC_ENT)
#define RA_ADIA RALT_T(DE_ADIA)
#define LA_ESC LALT(KC_ESC)

void keyboard_pre_init_user(void) {
  // Set our LED pin as output88
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

enum combos {
  desktop_left,
  desktop_right,
  alttab,
};

const uint16_t PROGMEM arlsft[] = {KC_A, KC_R, KC_LSFT, COMBO_END};
const uint16_t PROGMEM stlsft[] = {KC_S, KC_T, KC_LSFT, COMBO_END};
const uint16_t PROGMEM rslsft[] = {KC_R, KC_S, KC_LSFT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [desktop_left] = COMBO(arlsft, LCTL(LGUI(KC_LEFT))),
    [desktop_right] = COMBO(stlsft, LCTL(LGUI(KC_RIGHT))),
    [alttab] = COMBO(rslsft, LALT(KC_TAB)),
};

const key_override_t exqu_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_EXLM, DE_QUES);
const key_override_t ssampr_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_AMPR);
const key_override_t circdeg_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_CIRC, DE_DEG);
const key_override_t quot_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_QUOT, DE_DQUO);
const key_override_t slsh_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_SLSH, DE_BSLS);
const key_override_t prn_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LPRN, DE_RPRN);
const key_override_t cbr_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LCBR, DE_RCBR);
const key_override_t brc_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LBRC, DE_RBRC);
const key_override_t abk_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LABK, DE_RABK);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &exqu_key_override,
    &ssampr_key_override,
    &circdeg_key_override,
    &quot_key_override,
    &slsh_key_override,
    &prn_key_override,
    &cbr_key_override,
    &brc_key_override,
    &abk_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Z, DE_ODIA, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, RA_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Y,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LC_BSPC, KC_LSFT,  LT_DEL,    DE_EXLM,  LT_SPC,  LA_ENT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_CIRC, DE_ASTR,    KC_7,    KC_8,    KC_9, DE_PERC,                      DE_TILD, DE_QUOT, DE_LPRN, DE_SLSH, DE_LABK, DE_HASH,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       DE_EQL,    LT_0,    KC_4,    KC_5,    KC_6, DE_EURO,                      KC_HOME, KC_LEFT,   KC_UP,KC_RIGHT, KC_DOWN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DE_ACUT, DE_PLUS,    KC_1,    KC_2,    KC_3,  DE_DLR,                      DE_PIPE, DE_LCBR, DE_LBRC, DE_AMPR,   TO(6),   TO(4),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LC_BSPC, KC_LSFT,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       DE_EQL, DE_PLUS,    KC_7,    KC_8,    KC_9, DE_MINS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    LT_0,    KC_4,    KC_5,    KC_6,  KC_DOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT,  KC_SPC,    KC_1,    KC_2,    KC_3, KC_COMM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LC_BSPC, KC_LSFT,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //Shooter
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_Z,    KC_G,    KC_Q,    KC_W,    KC_E,    KC_T,                         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_R,                         KC_7,    KC_8,    KC_9,    KC_0,    KC_A,    KC_B,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_Y,    KC_M,    KC_X,    KC_V,    KC_B,  LT_ESC,                       KC_ESC,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_C,  KC_SPC, KC_LCTL,     LA_ESC,    KC_H,   TO(0)
                                      //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //Shooter
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_1,    KC_2,    KC_3,    KC_4, XXXXXXX, XXXXXXX,                         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_5,    KC_6,    KC_7,    KC_8, XXXXXXX, XXXXXXX,                         KC_7,    KC_8,    KC_9,    KC_0,    KC_A,    KC_B,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_9,    KC_0,    KC_H,    KC_I, XXXXXXX, XXXXXXX,                       KC_ESC,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [6] = LAYOUT_split_3x6_3(
  //WOW
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_T,    KC_Z,    KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX, XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_B,    KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX, XXXXXXX,    KC_0,    KC_4,    KC_5,    KC_6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_Y,    KC_M,    KC_X,    KC_C,    KC_V,  KC_ESC,                      XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LSFT,  KC_SPC, KC_LCTL,     LA_ESC, XXXXXXX,   TO(0)
                                      //`--------------------------'  `--------------------------'
  )
};

