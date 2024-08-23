/*
 * Copyright 2024 Danny Hui (@dtnhui)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,    // Qwerty Layout
    _LOWER,
    _UPPER,
    _ADJUST
};

#define CTL_ESC     CTL_T(KC_ESC)
#define SFT_SPC     SFT_T(KC_SPC)
#define NUM_TAB     LT(_UPPER, KC_TAB)
#define ADJ_TAB     LT(_ADJUST, KC_TAB)
#define NAV_BS      LT(_LOWER, KC_BSPC)
#define ADJ_BS      LT(_ADJUST, KC_BSPC)
#define SFT_ENT     SFT_T(KC_ENT)
#define CTL_DEL     CTL_T(KC_DEL)
#define GUI_CAPS    GUI_T(KC_CAPS)
#define ALT_PSCR    A(KC_PSCR)
#define CG_LEFT     C(G(KC_LEFT))
#define CG_RGHT     C(G(KC_RGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     GUI_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, SFT_SPC, NUM_TAB,     NAV_BS, SFT_ENT, CTL_DEL
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX,                      XXXXXXX, CG_LEFT,   KC_UP, CG_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CALC,ALT_PSCR, KC_PGDN,  KC_INS, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, ADJ_TAB,    XXXXXXX, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_UPPER] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, XXXXXXX,     ADJ_BS, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, RGB_MOD,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, RGB_TOG,                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12,RGB_RMOD,                         KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, XXXXXXX,    XXXXXXX, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DELETE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
#ifdef SPLIT_HAND_PIN
    if (is_keyboard_left()) {
        return OLED_ROTATION_0;
    }
#endif
    return rotation;
}

static void oled_render_layer_state(void) {
    static const char PROGMEM layer_inactive[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08,
        0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x18, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x0f, 0x08, 0x08, 0x08, 0xc8, 0xe8, 0xe8, 0xf8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8,
        0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xf8, 0xe8, 0xe8, 0xc8, 0x08, 0x08, 0x08, 0x0f, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x38, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
        0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x38, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM layer_pressed[4][2][128] = {
        { /* Layer i */
            { /* Normal */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x64,
                0x64, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f,
                0x7f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* Caps */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x8c, 0xf2, 0xfa, 0xfa, 0xfa, 0xfa, 0xf4, 0xf4, 0xb4, 0x34,
                0x34, 0xb4, 0xf4, 0xf4, 0xfa, 0xfa, 0xfa, 0xfa, 0xf2, 0x8c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0xc3, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x80,
                0x80, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xc3, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
                0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x04, 0x07, 0x00, 0x00
            },
        },
        { /* Layer ii */
            { /* Normal */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x64, 0x64, 0x04,
                0x04, 0x64, 0x64, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f, 0x7f, 0x40,
                0x41, 0x7f, 0x7f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* Caps */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x8c, 0xf2, 0xfa, 0xfa, 0xfa, 0xfa, 0xb4, 0x34, 0x34, 0xb4,
                0xb4, 0x34, 0x34, 0xb4, 0xfa, 0xfa, 0xfa, 0xfa, 0xf2, 0x8c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0xc3, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x80, 0x80, 0xbf,
                0xbf, 0x80, 0x80, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xc3, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
                0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x04, 0x07, 0x00, 0x00
            },
        },
        { /* Layer iii */
            { /* Normal */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x62, 0x64, 0x04, 0x04, 0x64,
                0x64, 0x04, 0x04, 0x64, 0x62, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f, 0x7f, 0x40, 0x41, 0x7f,
                0x7f, 0x40, 0x41, 0x7f, 0x7f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* Caps */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x8c, 0xf2, 0xfa, 0xfa, 0xba, 0x3a, 0x34, 0xb4, 0xb4, 0x34,
                0x34, 0xb4, 0xb4, 0x34, 0x3a, 0xba, 0xfa, 0xfa, 0xf2, 0x8c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0xc3, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x80, 0x80, 0xbf, 0xbf, 0x80,
                0x80, 0xbf, 0xbf, 0x80, 0x80, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xc3, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
                0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x04, 0x07, 0x00, 0x00
            },
        },
        { /* Layer iv */
            { /* Normal */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x62, 0x64, 0x04, 0x04, 0x04,
                0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f, 0x7f, 0x40, 0x00, 0x03,
                0x1f, 0x78, 0x40, 0x78, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* Caps */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x8c, 0xf2, 0xfa, 0xfa, 0xba, 0x3a, 0x34, 0xb4, 0xf4, 0x34,
                0x34, 0xf4, 0xf4, 0xf4, 0x3a, 0x3a, 0xfa, 0xfa, 0xf2, 0x8c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0xc3, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x80, 0x80, 0xbf, 0xff, 0xfe,
                0xf0, 0x83, 0x9f, 0x83, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xc3, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d,
                0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x3d, 0x04, 0x07, 0x00, 0x00
            },
        },
    };
    uint32_t curr_layer = get_highest_layer(layer_state);
    led_t led_state = host_keyboard_led_state();

    for (uint32_t i = 0; i < 4; i++) {
        oled_set_cursor(0, i * 4);
        if (curr_layer == i) {
            oled_write_raw(layer_pressed[curr_layer][led_state.caps_lock], sizeof(layer_inactive));
        } else {
            oled_write_raw(layer_inactive, sizeof(layer_inactive));
        }
    }
}

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        return true;
    } else {
        oled_render_layer_state();
        return false;
    }
}
#endif
