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
    _BASE,
    _LAYER1,
    _LAYER2,
    _LAYER3,
    _LAYER4,
    _LAYER5,
    _LAYER6,
    _LAYER7
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|   Tab  |    q   |    w   |    f   |    p   |    b   |                    |    j   |    l   |    u   |    y   |   ;:   | BSpace |
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|   Esc  |    a   |    r   |    s   |    t   |    g   |                    |    m   |    n   |    e   |    i   |    o   |   '"   |
       KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|  LAlt  |    z   |    x   |    c   |    d   |    v   |                    |    k   |    h   |   ,<   |   .>   |   /?   |  RAlt  |
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|  LCtrl |        | LShift |  | RShift |        |  RCtrl |
                                          KC_LCTL,  KC_SPC, KC_LSFT,    KC_RSFT,  KC_ENT, KC_RCTL
                                      //|--------------------------|  |--------------------------|
  ),

  [_LAYER1] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        |        |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_LAYER2] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        |        |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_LAYER3] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        |        |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_LAYER4] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        |        |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_LAYER5] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        |        |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_LAYER6] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        |        |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //|--------------------------|  |--------------------------|
  ),

  [_LAYER7] = LAYOUT_split_3x6_3 (
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //|        |        |        |        |        |        |                    |        |        |        |        |        |        |
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      //|        |        |        |  |        |        |        |
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
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
#define ANIM_FRAME_DURATION 100 // in units of milliseconds

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void oled_render_matrix_rain(void) {
    static const char PROGMEM BASE58_CHAR[] = {
        '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
        'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    static uint32_t anim_timer = 0;
    static uint32_t frame = 0;
    static bool rain_dropped[OLED_DISPLAY_HEIGHT / OLED_FONT_WIDTH] = {false};
    static int32_t rain_y[OLED_DISPLAY_HEIGHT / OLED_FONT_WIDTH] = {0};
    static uint32_t rain_len[OLED_DISPLAY_HEIGHT / OLED_FONT_WIDTH] = {0};
    static uint32_t tail_y[OLED_DISPLAY_HEIGHT / OLED_FONT_WIDTH] = {0};
    static uint32_t rain_speed[OLED_DISPLAY_HEIGHT / OLED_FONT_WIDTH] = {0};

    /* Display Off */
    if (!is_oled_on()) {
        oled_clear();
        anim_timer = 0;
        frame = 0;
        for (uint32_t i = 0; i < oled_max_chars(); i++) {
            rain_dropped[i] = false;
        }
        return;
    }

    /* Character Spinning */
    if (timer_elapsed32(anim_timer) < ANIM_FRAME_DURATION) {
        for (uint32_t i = 0; i < oled_max_chars(); i++) {
            if (rain_y[i] < 0) {
                // Out of Display
            } else if (rain_y[i] < oled_max_lines()) {
                oled_set_cursor(i, rain_y[i]);
                oled_write_char(BASE58_CHAR[rand() % sizeof(BASE58_CHAR)], false);
            }
        }
        return;
    }

    /* New frame */
    frame++;
    anim_timer = timer_read32();
    for (uint32_t i = 0; i < oled_max_chars(); i++) {
        /* Re-Initialization */
        if (!rain_dropped[i]) {
            rain_dropped[i] = true;
            rain_y[i] = 0 - (rand() % oled_max_lines() / 2);
            rain_len[i] = (oled_max_lines() / 4) + (rand() % oled_max_lines() / 2);
            tail_y[i] = 0;
            rain_speed[i] = 1 + (rand() % 3);
        }
        /* Rain */
        if ((frame % rain_speed[i]) == 0) {
            if (rain_y[i] < 0) {
                // Out of Display
            } else if (rain_y[i] > rain_len[i]) {
                if (tail_y[i] < oled_max_lines()) {
                    oled_set_cursor(i, tail_y[i]++);
                    oled_write_char(' ', false);
                }
            }
            if (rain_y[i]++ == (oled_max_lines() + rain_len[i])) {
                rain_dropped[i] = false;
            }
            /* Glitch */
            uint32_t glitch_total = rand() % rain_len[i];
            for (uint32_t j = 0; j < glitch_total; j++) {
                if ((rain_y[i] > 0) && (tail_y[i] < oled_max_lines())) {
                    uint32_t glitch_y = tail_y[i] + (rand() % (rain_y[i] - tail_y[i]));
                    if (glitch_y < oled_max_lines()) {
                        oled_set_cursor(i, glitch_y);
                        oled_write_char(BASE58_CHAR[rand() % sizeof(BASE58_CHAR)], false);
                    }
                }
            }
        }
    }
}

bool oled_task_user(void) {
    led_t led_state = host_keyboard_led_state();
    oled_invert(led_state.caps_lock);

    if (is_keyboard_master()) {
        // TODO
    }

    oled_render_matrix_rain();

    return false;
}
#endif
