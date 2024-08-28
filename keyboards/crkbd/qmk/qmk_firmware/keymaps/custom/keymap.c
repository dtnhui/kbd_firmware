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
    _NAV,       // Navigation
    _NUM,       // Number & Symbol
    _KPAD,       // Keypad
    _FUNC,       // Function
};

#define NUM_SPC     LT(_NUM, KC_SPC)
#define NAV_ENT     LT(_NAV, KC_ENT)
#define FUNC_ENT    LT(_FUNC, KC_ENT)
#define MO_FUNC     MO(_FUNC)
#define MO_KPAD     MO(_KPAD)

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
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|    `   |    q   |    w   |    e   |    r   |    t   |                    |    y   |    u   |    i   |    o   |    p   |    \   |
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|gui/caps|    a   |    s   |    d   |    f   |    g   |                    |    h   |    j   |    k   |    l   |    ;   |  gui/' |
     GUI_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,GUI_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   alt  |    z   |    x   |    c   |    v   |    b   |                    |    n   |    m   |    ,   |    .   |    /   |   alt  |
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //| ctl/esc| L2/spc | sft/tab|  |sft/bspc| L1/ent | ctl/del|
                                          CTL_ESC, NUM_SPC, SFT_TAB,   SFT_BSPC, NAV_ENT, CTL_DEL
                                      //|--------------------------|  |--------------------------|
  ),

  [_NAV] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|   esc  |        |        |        |        |        |                    |        | pageup |   up   |pagedown|        |  bspc  |
       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PGUP,   KC_UP, KC_PGDN, XXXXXXX, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   gui  |        |        |alt+pscr| insert |        |                    |  home  |  left  |  down  |  right |   end  |   gui  |
      KC_LGUI, XXXXXXX, XXXXXXX,ALT_PSCR,  KC_INS, XXXXXXX,                      KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END, KC_RGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   alt  |        |        |        |        |        |                    |        | cg+left|        |cg+right|        |   alt  |
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, CG_LEFT, XXXXXXX, CG_RGHT, XXXXXXX, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|   ctl  |   L4   |  shift |  |        |        |        |
                                          KC_LCTL, MO_FUNC, KC_LSFT,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_NUM] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|    ~   |    !   |    @   |    #   |    $   |    %   |                    |    ^   |    &   |    *   |    (   |    )   |    |   |
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   gui  |    4   |    2   |    3   |    1   |    5   |                    |    6   |    0   |    8   |    9   |    7   |   gui  |
      KC_LGUI,    KC_4,    KC_2,    KC_3,    KC_1,    KC_5,                         KC_6,    KC_0,    KC_8,    KC_9,    KC_7, KC_RGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   alt  |   L3   |    {   |    +   |    _   |    }   |                    |    ]   |    -   |    =   |    [   |        |   alt  |
      KC_LALT, MO_KPAD, KC_LCBR, KC_PLUS, KC_UNDS, KC_RCBR,                      KC_RBRC, KC_MINS,  KC_EQL, KC_LBRC, XXXXXXX, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        | L4/ent |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    _______,FUNC_ENT, _______
                                      //|--------------------------|  |--------------------------|
  ),

  [_KPAD] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |    /   |    7   |    8   |    9   |    -   |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_SLSH,    KC_7,    KC_8,    KC_9, KC_MINS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |    *   |    4   |    5   |    6   |    +   |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |   esc  |    1   |    2   |    3   |  enter |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_ESC,    KC_1,    KC_2,    KC_3,  KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |  bspc  |    0   |    .   |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_BSPC,    KC_0,  KC_DOT
                                      //|--------------------------|  |--------------------------|
  ),

  [_FUNC] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|  gui+l |   F1   |   F2   |   F3   |   F4   |        |                    | rainbow|        |        |        |        | ca+del |
        GUI_L,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      RGB_M_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  CA_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   gui  |   F5   |   F6   |   F7   |   F8   |        |                    | on/off |  mute  | vol dn | vol up |  calc  |   gui  |
      KC_LGUI,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      RGB_TOG, KC_MUTE, KC_VOLD, KC_VOLU, KC_CALC, KC_RGUI,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   alt  |   F9   |   F10  |   F11  |   F12  |        |                    | breath |        |        |        |        |   alt  |
      KC_LALT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      RGB_M_B, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //| spd dec|        | spd inc|  | hue inc|        | hue dec|
                                          RGB_SPD, XXXXXXX, RGB_SPI,    RGB_HUI, XXXXXXX, RGB_HUD
                                      //|--------------------------|  |--------------------------|
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

void oled_render_4layers_state(void) {
    /* 32 x 32 pixels */
    static const char PROGMEM layer_inactive[128] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x18, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x08,
        0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x18, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x78, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x0f, 0x08, 0x08, 0x08, 0xc8, 0xe8, 0xe8, 0xf8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8,
        0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xe8, 0xf8, 0xe8, 0xe8, 0xc8, 0x08, 0x08, 0x08, 0x0f, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x38, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
        0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x38, 0x00, 0x00, 0x00, 0x00
    };
    /* 32 x 32 pixels */
    static const char PROGMEM layer_pressed[4][2][128] = {
        { /* Layer i */
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x64,
                0x64, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f,
                0x7f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* upper */
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
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x64, 0x64, 0x04,
                0x04, 0x64, 0x64, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f, 0x7f, 0x40,
                0x41, 0x7f, 0x7f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* upper */
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
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x62, 0x64, 0x04, 0x04, 0x64,
                0x64, 0x04, 0x04, 0x64, 0x62, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f, 0x7f, 0x40, 0x41, 0x7f,
                0x7f, 0x40, 0x41, 0x7f, 0x7f, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* upper */
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
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x80, 0x70, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x62, 0x64, 0x04, 0x04, 0x04,
                0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x7f, 0x7f, 0x40, 0x00, 0x03,
                0x1f, 0x78, 0x40, 0x78, 0x1f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x07, 0x04, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
                0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x04, 0x07, 0x00, 0x00
            },
            { /* upper */
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
        if (i == curr_layer) {
            oled_write_raw(layer_pressed[i][led_state.caps_lock], sizeof(layer_pressed[0][0]));
        } else {
            oled_write_raw(layer_inactive, sizeof(layer_inactive));
        }
    }
}

void oled_render_5layers_state(void) {
    /* 32 x 24 pixels */
    static const char PROGMEM layer_inactive[96] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x0c, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x78, 0x47, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x40, 0x40,
        0x40, 0x40, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x47, 0x78, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x78, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
        0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7e, 0x78, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    /* 32 x 32 pixels */
    static const char PROGMEM layer_pressed[5][2][128] = {
        { /* Layer i */
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf6,
                0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8c, 0x8f,
                0x8f, 0x8c, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0xc7, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x03,
                0x03, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc7, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xb3, 0xb0,
                0xb0, 0xb3, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer ii */
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf6, 0xf6, 0x00,
                0x30, 0xf6, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8c, 0x8f, 0x8f, 0x8c,
                0x8c, 0x8f, 0x8f, 0x8c, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0xc7, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x03, 0x03, 0xf3,
                0xf3, 0x03, 0x03, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc7, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xb3, 0xb0, 0xb0, 0xb3,
                0xb3, 0xb0, 0xb0, 0xb3, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer iii */
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf6, 0xf6, 0x00, 0x30, 0xf6,
                0xf6, 0x00, 0x30, 0xf6, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8c, 0x8f, 0x8f, 0x8c, 0x8c, 0x8f,
                0x8f, 0x8c, 0x8c, 0x8f, 0x8f, 0x8c, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0xc7, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x03, 0x03, 0xf3, 0xf3, 0x03,
                0x03, 0xf3, 0xf3, 0x03, 0x03, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc7, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xb3, 0xb0, 0xb0, 0xb3, 0xb3, 0xb0,
                0xb0, 0xb3, 0xb3, 0xb0, 0xb0, 0xb3, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer iv */
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf6, 0xf6, 0x00, 0x00, 0x30,
                0xf0, 0x80, 0x00, 0x80, 0xf0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8c, 0x8f, 0x8f, 0x8c, 0x80, 0x80,
                0x81, 0x8f, 0x8c, 0x8f, 0x81, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0xc7, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x03, 0x03, 0xf3, 0xff, 0xc3,
                0x03, 0x3f, 0xff, 0x3f, 0x03, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc7, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xb3, 0xb0, 0xb0, 0xb3, 0xbf, 0xbf,
                0xbc, 0xb0, 0xb3, 0xb0, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
        },
        { /* Layer v */
            { /* lower */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf8, 0xc0, 0x00,
                0xc0, 0xf8, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x87, 0x86,
                0x87, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
            { /* upper */
                0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x40, 0x40, 0x40, 0x40,
                0x40, 0x40, 0x40, 0x40, 0xa0, 0xa0, 0xa0, 0xa0, 0xa0, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0xc0, 0x38, 0xc7, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0x03, 0x3f, 0xff,
                0x3f, 0x03, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xc7, 0x38, 0xc0, 0x00, 0x00,
                0x00, 0xfc, 0x83, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0xb0, 0xb3,
                0xb0, 0xbc, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbf, 0xbc, 0x83, 0xfc, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
                0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00
            },
        }
    };
    uint32_t curr_layer = get_highest_layer(layer_state);
    led_t led_state = host_keyboard_led_state();
    uint32_t line_number = 0;
    bool require_offset = false;
    for (uint32_t i = 0; i < 5; i++) {
        oled_set_cursor(0, line_number);
        if (i == curr_layer) {
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
        oled_render_5layers_state();
        return false;
    }
}
#endif
