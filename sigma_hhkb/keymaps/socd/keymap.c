// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

enum anne_pro_keycodes {
  SOCD_A = SAFE_RANGE,
  SOCD_D
};

bool a_down = false;
bool d_down = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ \ │MUT│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ Bspc│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift│MO1│
     * └─────┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┘
     *       │Alt│ GUI │                           │ GUI │Alt│
     *       └───┴─────┴───────────────────────────┴─────┴───┘
     */
    [0] = LAYOUT_60_hhkb(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, SOCD_A,  KC_S,    SOCD_D,  KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_QUOT,     KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,     KC_RSFT,    MO(1),
                          KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, KC_RALT
    ),

    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │` ~│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Ins│PLY│
     * ├───┴─┬─┴───┴───┴───┴───┴───┴───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┘
     * │Caps │ Q │ W │ E │ R │ T │ Y │ U │PSc│Scr│Pse│ ↑ │ ] │ Del │
     * └─────┘┌───┬───┬───┐──┴┬──┴┌───┬──┴┬──┴┬──┴┬──┴┬──┴┬────────┐
     * │ Ctrl │ A │ S │ D │ F │ G │ * │ / │Hom│PgU│ ← │ → │  Enter │
     * ├──────└───┴───┴───┘─┬─┴─┬─└─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┘
     * │ Shift  │ Z │ X │ C │ V │ B │ + │ - │End│PgD│ ↓ │ Shift│MO1│
     * └─────┬──┴┬──┴──┬┴───┴───┴───└───┴───┴───┴───┴───┘┬───┬─┴───┘
     *       │Alt│ GUI │                           │ GUI │Alt│
     *       └───┴─────┴───────────────────────────┴─────┴───┘
     */
    [1] = LAYOUT_60_hhkb(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_MPLY,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,   _______,  KC_DEL,
        _______, _______, _______, _______, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,          KC_PENT,
        _______, _______, _______, _______, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN,      _______,     _______,
                          _______, _______,                   _______,                            _______, QK_BOOT
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] = { ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    
    case SOCD_A:
        if (record->event.pressed) {
            if (d_down) {
                unregister_code(KC_D);
            }
            register_code(KC_A);
            a_down = true;
        } else {
            unregister_code(KC_A);
            a_down = false;

            if (d_down) {
                register_code(KC_D);
            }

        }
        return false;
        break;
    
    case SOCD_D:
        if (record->event.pressed) {
            if (a_down) {
                unregister_code(KC_A);
            }
            register_code(KC_D);
            d_down = true;
        } else {
            unregister_code(KC_D);
            d_down = false;

            if (a_down) {
                register_code(KC_A);
            }
        }
        return false;
        break;
    }
    return true;
}