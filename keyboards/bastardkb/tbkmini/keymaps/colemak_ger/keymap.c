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

#define LT_BSPC LT(1,KC_BSPC)
#define LT_SPC LT(2,KC_SPC)
#define LC_DEL LCTL_T(KC_DEL)
#define LT_0 LT(2,KC_0)
#define LT_ENT LT(3,KC_ENT)
#define LT_ESC LT(5,KC_ESC)
#define LA_ESC LALT(KC_ESC)

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

enum combos {
  desktop_left,
  desktop_right,
  alttab,
  fancyzones1,
  fancyzones2,
  fancyzones3,
  fancyzones4,
  gaming1,
  gaming2,
};

const uint16_t PROGMEM arlsft[] = {KC_A, KC_R, KC_LSFT, COMBO_END};
const uint16_t PROGMEM rslsft[] = {KC_R, KC_S, KC_LSFT, COMBO_END};
const uint16_t PROGMEM stlsft[] = {KC_S, KC_T, KC_LSFT, COMBO_END};
const uint16_t PROGMEM ardel[] = {KC_A, KC_R, LC_DEL, COMBO_END};
const uint16_t PROGMEM rsdel[] = {KC_R, KC_S, LC_DEL, COMBO_END};
const uint16_t PROGMEM stdel[] = {KC_S, KC_T, LC_DEL, COMBO_END};
const uint16_t PROGMEM atdel[] = {KC_A, KC_T, LC_DEL, COMBO_END};
const uint16_t PROGMEM pg[] = {KC_P, KC_G, COMBO_END};
const uint16_t PROGMEM df[] = {KC_D, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [desktop_left] = COMBO(arlsft, LCTL(LGUI(KC_LEFT))),
    [desktop_right] = COMBO(stlsft, LCTL(LGUI(KC_RIGHT))),
    [alttab] = COMBO(rslsft, LALT(KC_TAB)),
    [fancyzones1] = COMBO(ardel, LCTL(KC_F21)),
    [fancyzones2] = COMBO(rsdel, LCTL(KC_F22)),
    [fancyzones3] = COMBO(stdel, LCTL(KC_F23)),
    [fancyzones4] = COMBO(atdel, LCTL(KC_F24)),
    [gaming1] = COMBO(pg, LCTL(KC_1)),
    [gaming2] = COMBO(df, LCTL(KC_2)),
};

const key_override_t ssat_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_AT);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ssat_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Z, DE_ODIA, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Y,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LT_BSPC, KC_LSFT,  LC_DEL,    KC_LALT,  LT_SPC,  LT_ENT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_ASTR, DE_PLUS,    KC_7,    KC_8,    KC_9, DE_MINS,                      DE_BSLS, DE_SLSH,  DE_EQL, DE_AMPR,  DE_DLR, DE_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    LT_0,    KC_4,    KC_5,    KC_6,  KC_DOT,                      DE_EXLM, DE_LPRN, DE_LCBR, DE_LBRC, DE_DQUO, DE_LABK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT,  KC_SPC,    KC_1,    KC_2,    KC_3, KC_COMM,                      DE_QUES, DE_RPRN, DE_RCBR, DE_RABK, DE_QUOT, DE_RBRC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_LCTL,  KC_SPC, KC_LSFT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3( 
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      DE_CIRC, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  TO(6),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_LALT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      DE_HASH, KC_LEFT, KC_DOWN,KC_RIGHT, KC_PGDN,  TO(4),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ENT,  KC_SPC,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                      DE_TILD, DE_EURO, DE_PIPE,  DE_DEG, DE_ACUT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, KC_LSFT,  LC_DEL,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_UP, XXXXXXX, XXXXXXX,                  XXXXXXX, KC_MNXT, KC_MS_UP, KC_MPRV, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MS_BTN3, KC_MS_BTN2, KC_MS_WH_DOWN, KC_MS_BTN1, XXXXXXX,       KC_MPLY, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, KC_SLEP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MUTE, KC_VOLU, KC_VOLD, KC_CALC, KC_PWR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, KC_LSFT,  LC_DEL,    XXXXXXX, XXXXXXX, XXXXXXX
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
                                             KC_C,  KC_SPC, KC_LCTL,      TO(0),    KC_H,  LA_ESC
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
  //League of Legends
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_F,                      XXXXXXX, XXXXXXX,    KC_0,    KC_4,    KC_5,    KC_6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_Y,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT,  KC_SPC,      TO(0), XXXXXXX,  LA_ESC
                                      //`--------------------------'  `--------------------------'
  )
};

