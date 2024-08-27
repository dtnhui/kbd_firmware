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
    _COLEMAK,   // Colemak-DH Layout
    _NAV,       // Navigation
    _NUM,       // Number & Symbol
    _KPAD,       // Keypad
    _FUNC,       // Function
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK
};

#define NUM_SPC     LT(_NUM, KC_SPC)
#define FUNC_SPC    LT(_FUNC, KC_SPC)
#define NAV_ENT     LT(_NAV, KC_ENT)
#define FUNC_ENT    LT(_FUNC, KC_ENT)
#define KEYPAD      MO(_KPAD)

#define GUI_CAPS    GUI_T(KC_CAPS)
#define GUI_QUOT    GUI_T(KC_QUOT)
#define CTL_ESC     CTL_T(KC_ESC)
#define SFT_TAB     SFT_T(KC_TAB)
#define SFT_BSPC    SFT_T(KC_BSPC)
#define CTL_DEL     CTL_T(KC_DEL)

#define ALT_PSCR    A(KC_PSCR)
#define CG_LEFT     C(G(KC_LEFT))
#define CG_RGHT     C(G(KC_RGHT))
#define GUI_L       G(KC_L)
#define CA_DEL      C(A(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     GUI_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,GUI_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, NUM_SPC, SFT_TAB,   SFT_BSPC, NAV_ENT, CTL_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [_COLEMAK] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     GUI_CAPS,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,GUI_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          CTL_ESC, NUM_SPC, SFT_TAB,   SFT_BSPC, NAV_ENT, CTL_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX,ALT_PSCR,  KC_INS, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CG_LEFT, XXXXXXX, CG_RGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,FUNC_SPC, _______,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_GRV, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MINS,  KC_EQL, KC_LBRC, KC_SCLN, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_BSLS, XXXXXXX, XXXXXXX,  KEYPAD, XXXXXXX,                      XXXXXXX, XXXXXXX, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    _______,FUNC_ENT, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_KPAD] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_ESC,    KC_1,    KC_2,    KC_3,  KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_BSPC,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUNC] = LAYOUT_split_3x6_3 (
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        GUI_L,   KC_F1,   KC_F2,   KC_F3,   KC_F4, COLEMAK,                      RGB_M_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  CA_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  QWERTY,                      RGB_TOG, KC_MUTE, KC_VOLD, KC_VOLU, KC_CALC, KC_RGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      RGB_M_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          RGB_HUD, XXXXXXX, RGB_HUI,    RGB_SPI, XXXXXXX, RGB_SPD
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
    }
    return true;
}

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
    /* 32 x 24 pixels */
    static const char PROGMEM layer_inactive[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x43, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x40, 0x40,
        0x40, 0x40, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x43, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x7c, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
        0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    /* 32 x 32 pixels */
    static const char PROGMEM layer_layout[2][2][128] = {
        { /* q: qwerty */
            { /* lower */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10,
                0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf8, 0x8c, 0x8c,
                0x8c, 0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x20, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1,
                0xe1, 0xef, 0xef, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xd0, 0xd0, 0xd0, 0xd0,
                0xd0, 0xd0, 0xd0, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0x78, 0xfc,
                0xfc, 0x78, 0x01, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x87, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x2f, 0x2f, 0x2f, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xee, 0xec, 0xe8,
                0xe0, 0xe0, 0xe2, 0xe3, 0xeb, 0xef, 0xef, 0xef, 0xef, 0xef, 0x2f, 0x2f, 0x2f, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* c: colemak */
            { /* lower */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10,
                0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf8, 0x8c, 0x8c,
                0x8c, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x20, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1,
                0xe1, 0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xd0, 0xd0, 0xd0, 0xd0,
                0xd0, 0xd0, 0xd0, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0x78, 0xfc,
                0xfc, 0xfc, 0x79, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x87, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x2f, 0x2f, 0x2f, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xee, 0xec, 0xec,
                0xec, 0xec, 0xee, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0x2f, 0x2f, 0x2f, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
        }
    };
    static const char PROGMEM layer_pressed[5][2][128] = {
        { /* Layer i */
            { /* lower */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10,
                0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xfb,
                0xfb, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x20, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe3, 0xe3,
                0xe3, 0xe3, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xd0, 0xd0, 0xd0, 0xd0,
                0xd0, 0xd0, 0xd0, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00,
                0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x87, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x2f, 0x2f, 0x2f, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xec, 0xec,
                0xec, 0xec, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0x2f, 0x2f, 0x2f, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer ii */
            { /* lower */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10,
                0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xfb, 0xfb, 0x18,
                0x18, 0xfb, 0xfb, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x20, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe3, 0xe3, 0xe3, 0xe3,
                0xe3, 0xe3, 0xe3, 0xe3, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xd0, 0xd0, 0xd0, 0xd0,
                0xd0, 0xd0, 0xd0, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xfc,
                0xfc, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x87, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x2f, 0x2f, 0x2f, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xec, 0xec, 0xec, 0xec,
                0xec, 0xec, 0xec, 0xec, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0x2f, 0x2f, 0x2f, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer iii */
            { /* lower */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10,
                0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xfb, 0xfb, 0x18, 0x18, 0xfb,
                0xfb, 0x18, 0x18, 0xfb, 0xfb, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x20, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3,
                0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe3, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xd0, 0xd0, 0xd0, 0xd0,
                0xd0, 0xd0, 0xd0, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xfc, 0xfc, 0x00,
                0x00, 0xfc, 0xfc, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x87, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x2f, 0x2f, 0x2f, 0xef, 0xef, 0xef, 0xef, 0xec, 0xec, 0xec, 0xec, 0xec, 0xec,
                0xec, 0xec, 0xec, 0xec, 0xec, 0xec, 0xef, 0xef, 0xef, 0xef, 0x2f, 0x2f, 0x2f, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer iv */
            { /* lower */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10,
                0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xfb, 0xfb, 0x18, 0x00, 0x18,
                0xf8, 0xc0, 0x00, 0xc0, 0xf8, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x20, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe3, 0xe3, 0xe3, 0xe3, 0xe0, 0xe0,
                0xe0, 0xe3, 0xe2, 0xe3, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xd0, 0xd0, 0xd0, 0xd0,
                0xd0, 0xd0, 0xd0, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0xfc, 0xff, 0xf0,
                0x00, 0x0f, 0xff, 0x0f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x87, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x2f, 0x2f, 0x2f, 0xef, 0xef, 0xef, 0xef, 0xec, 0xec, 0xec, 0xec, 0xef, 0xef,
                0xef, 0xec, 0xec, 0xec, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0x2f, 0x2f, 0x2f, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer v */
            { /* lower */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x10, 0x10, 0x10, 0x10,
                0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x7c, 0xe0, 0x00,
                0xe0, 0x7c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x20, 0x20, 0x20, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1,
                0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x20, 0x20, 0x20, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x80, 0x70, 0x88, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xd0, 0xd0, 0xd0, 0xd0,
                0xd0, 0xd0, 0xd0, 0xd0, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0x88, 0x70, 0x80, 0x00, 0x00, 0x00,
                0x00, 0x80, 0x78, 0x87, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0xff,
                0x0f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x87, 0x78, 0x80, 0x00,
                0x00, 0x3f, 0x20, 0x2f, 0x2f, 0x2f, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xec, 0xec,
                0xec, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0xef, 0x2f, 0x2f, 0x2f, 0x20, 0x3f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
                0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
            },
        }
    };
    uint32_t default_layer = get_highest_layer(default_layer_state);
    uint32_t curr_layer = get_highest_layer(layer_state);
    led_t led_state = host_keyboard_led_state();
    uint32_t line_number = 0;
    bool require_offset = false;
    for (uint32_t i = 0; i < 5; i++) {
        oled_set_cursor(0, line_number);
        if ((0 == curr_layer) && (i == curr_layer)) {
            require_offset = true;
            if (_COLEMAK == default_layer) {
                oled_write_raw(layer_layout[_COLEMAK][led_state.caps_lock], sizeof(layer_layout[0][0]));
            } else {
                oled_write_raw(layer_layout[_QWERTY][led_state.caps_lock], sizeof(layer_layout[0][0]));
            }
        } else if ((1 + i) == curr_layer) {
            require_offset = true;
            oled_write_raw(layer_pressed[i][led_state.caps_lock], sizeof(layer_pressed[0][0]));
        } else {
            oled_write_raw(layer_inactive, sizeof(layer_inactive));
        }
        if (require_offset) {
            line_number += 4;
        } else {
            line_number += 3;
        }
        require_offset = false;
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
