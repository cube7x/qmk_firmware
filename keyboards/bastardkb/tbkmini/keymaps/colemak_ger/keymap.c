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

#define LT_ENT LT(1,KC_ENT)
#define LT_SPC LT(2,KC_SPC)
#define LC_BSPC LCTL_T(KC_BSPC)

//Homerow Mods
#define HOME_A LSFT_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S RALT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

#define HOME_N RCTL_T(KC_N)
#define HOME_E LT(3,KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RSFT_T(KC_O)

#define HOME_0 RSFT_T(KC_0)
#define HOME_4 LALT_T(KC_4)
#define HOME_5 RALT_T(KC_5)
#define HOME_6 RCTL_T(KC_6)

void keyboard_pre_init_user(void) {
  // Set our LED pin as output88
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

const key_override_t abk_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LABK, DE_RABK);
const key_override_t prn_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LPRN, DE_RPRN);
const key_override_t cbr_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LCBR, DE_RCBR);
const key_override_t brc_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LBRC, DE_RBRC);
const key_override_t sls_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_SLSH, DE_BSLS);
const key_override_t exqu_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_EXLM, DE_QUES);

const key_override_t *key_overrides[] = {
    &abk_key_override,
    &prn_key_override,
    &cbr_key_override,
    &brc_key_override,
    &sls_key_override,
    &exqu_key_override,
    NULL // Das NULL-Terminierungs-Element ist hier immer noch wichtig!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Z, DE_ODIA, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Y,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LC_BSPC,  LT_ENT,  KC_DEL,    DE_EXLM,  LT_SPC,  KC_ENT
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_CIRC, DE_DQUO,    KC_7,    KC_8,    KC_9, DE_EURO,                      DE_LABK, DE_LPRN, DE_LCBR, DE_LBRC, DE_SLSH, DE_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       DE_EQL,  HOME_0,  HOME_4,  HOME_5,  HOME_6,  DE_DLR,                      KC_HOME, KC_LEFT,   KC_UP,KC_RIGHT, KC_DOWN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DE_AMPR, DE_QUOT,    KC_1,    KC_2,    KC_3, DE_HASH,                      DE_PIPE, DE_ASTR, KC_COMM,  KC_DOT, KC_SLSH, DE_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    DE_EXLM,  LT_SPC,  KC_ENT
                                      //`--------------------------'  `--------------------------'
  ),
  
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_VOLU, KC_WH_U,KC_MS_BTN6,KC_WH_L,KC_WH_R, KC_MNXT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_VOLD, KC_WH_D,KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1,KC_MPLY,                 XXXXXXX, LCTL(KC_V), XXXXXXX, LCTL(KC_C), LCTL(KC_X), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       DE_DEG, DE_TILD,   TO(4),KC_MS_BTN4,KC_MS_BTN5,KC_MPRV,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT, KC_LALT,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //Shooter
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_G,    KC_V,    KC_W,    KC_F,    KC_T,                         KC_I,    KC_7,    KC_8,    KC_9,    KC_N,    KC_H,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_C, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_R,                         KC_B,    KC_4,    KC_5,    KC_6,    KC_0,    KC_J,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_M, KC_LCTL,    KC_Z,    KC_X, KC_LALT,  KC_ESC,                      KC_MUTE,    KC_1,    KC_2,    KC_3,    KC_K,    KC_L,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_Q,  KC_SPC,    KC_E,  LALT(KC_ESC), DE_CIRC,   TO(0)
                                      //`--------------------------'  `--------------------------'
  )
};