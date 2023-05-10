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

#define LT_Y LT(4,KC_Y)
#define LT_DEL LT(3,KC_DEL)
#define LT_SPC LT(1,KC_SPC)
#define LA_ENT LALT_T(KC_ENT)
#define LT_0 LT(2,KC_0)
#define LA_ESC LALT(KC_ESC)
#define LCTL_X LCTL(KC_X)
#define LCTL_C LCTL(KC_C)
#define LCTL_V LCTL(KC_V)
#define LCTL_Z LCTL(DE_Z)
#define LCTL_A LCTL(KC_A)
#define LCTL_S LCTL(KC_S)
#define LCTL_P LCTL(KC_P)
#define LCTL_F LCTL(KC_F)
#define LCTL_E LCTL(KC_E)
#define LCTL_K LCTL(KC_K)
#define LC_SPC LCTL(KC_SPC)

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
const uint16_t PROGMEM ardel[] = {KC_A, KC_R, LT_DEL, COMBO_END};
const uint16_t PROGMEM rsdel[] = {KC_R, KC_S, LT_DEL, COMBO_END};
const uint16_t PROGMEM stdel[] = {KC_S, KC_T, LT_DEL, COMBO_END};
const uint16_t PROGMEM atdel[] = {KC_A, KC_T, LT_DEL, COMBO_END};
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

const key_override_t exlm_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_EXLM, DE_QUES);
const key_override_t ss_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_SS, DE_AT);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &exlm_key_override,
    &ss_key_override,
    NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Z, DE_ODIA, DE_UDIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, DE_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    LT_Y,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC, KC_LSFT,  LT_DEL,     LA_ENT,  LT_SPC, DE_EXLM
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_HASH, DE_EURO,    KC_7,    KC_8,    KC_9, DE_ASTR,                      DE_LBRC, KC_HOME,   KC_UP,  KC_END, DE_BSLS, DE_RBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DE_LABK,    LT_0,    KC_4,    KC_5,    KC_6,  DE_EQL,                      DE_SLSH, KC_LEFT, KC_DOWN,KC_RIGHT, DE_QUOT, DE_AMPR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DE_RABK, DE_PERC,    KC_1,    KC_2,    KC_3, DE_PLUS,                      DE_LCBR, DE_LPRN, DE_DQUO, DE_RPRN, DE_RCBR,  DE_DLR,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      XXXXXXX,   TO(5), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      XXXXXXX, DE_TILD, DE_PIPE, DE_CIRC, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                      XXXXXXX,  DE_DEG, DE_ACUT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT, KC_BSPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, DE_PLUS,    KC_7,    KC_8,    KC_9, DE_MINS,                      XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    LT_0,    KC_4,    KC_5,    KC_6,  KC_DOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       DE_EQL,  KC_SPC,    KC_1,    KC_2,    KC_3, KC_COMM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  LCTL_A,  LCTL_F,  LCTL_P,  LCTL_E,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,  LCTL_Z,  LCTL_S,  LC_SPC,  LCTL_K,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           LCTL_X,  LCTL_C,  LCTL_V,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_P,    KC_G,    KC_Q,    KC_W,    KC_E,    KC_R,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         KC_T,    KC_Z,    KC_Y,    KC_X,    KC_V,  KC_ESC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                             KC_C,  KC_SPC, KC_LCTL,      TO(0), XXXXXXX,  LA_ESC
                                      //`--------------------------'  `--------------------------'
  )
};

