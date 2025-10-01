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

#define LT_0 LT(2,KC_0)
#define LT_DEL LT(3,KC_DEL)
#define LT_SPC LT(1,KC_SPC)
#define LT_ESC LT(5,KC_ESC)

#define LA_TAB LALT_T(KC_TAB)
#define LC_BSPC LCTL_T(KC_BSPC)
#define LA_ADIA LALT_T(DE_ADIA)
#define RA_SPC RALT_T(KC_SPC)
#define RA_ENT RALT_T(KC_ENT)

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
       LA_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, LA_ADIA,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Y,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,   DE_SS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LC_BSPC, KC_LSFT,  LT_DEL,    DE_EXLM,  LT_SPC,  RA_ENT
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      DE_CIRC, DE_DQUO,    KC_7,    KC_8,    KC_9, DE_EURO,                      DE_LABK, DE_LPRN, DE_LCBR, DE_LBRC, DE_SLSH, DE_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       DE_EQL,    LT_0,    KC_4,    KC_5,    KC_6,  DE_DLR,                      KC_HOME, KC_LEFT,   KC_UP,KC_RIGHT, KC_DOWN,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      DE_AMPR, DE_QUOT,    KC_1,    KC_2,    KC_3, DE_HASH,                      DE_PIPE, DE_ASTR, KC_COMM,  KC_DOT, KC_SLSH, DE_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LC_BSPC, KC_LSFT,  RA_SPC,    XXXXXXX, XXXXXXX, XXXXXXX
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
                                          LC_BSPC, KC_LSFT,  KC_SPC,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  
  [3] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------. 
       KC_VOLU, KC_WH_U,KC_MS_BTN6,KC_WH_L, KC_WH_R, KC_MNXT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_VOLD, KC_WH_D,KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1,KC_MPLY,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
         DE_DEG, DE_TILD, XXXXXXX,KC_MS_BTN4,KC_MS_BTN5,KC_MPRV,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    )
};
