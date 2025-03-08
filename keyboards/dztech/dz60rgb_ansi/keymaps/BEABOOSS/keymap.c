#include QMK_KEYBOARD_H
#include <stdio.h>
#include "features/keycode_string.h"
#include "print.h"

// clang-format off
enum layers {
    BASE,
    SYM,
    NAV,
    NUM,
    WIN,
    FUN,
    EXT,
    GAME
};
// clang-format on

// Define the mod-tap keys for the home row
#define HRM_A LGUI_T(KC_A) // A acts as GUI (Cmd/Win) when held
// #define HRM_R LALT_T(KC_R) s// R acts as Alt when held
#define HRM_R LT(SYM, KC_R)
#define HRM_S LSFT_T(KC_S) // s acts as Shift when held
#define HRM_T LCTL_T(KC_T) // t acts as Ctrl when held

#define HRM_N RCTL_T(KC_N) // n acts as Ctrl when held
#define HRM_E RSFT_T(KC_E) // e acts as Shift when held
#define HRM_I LALT_T(KC_I) // i acts as Alt when held
#define HRM_O RGUI_T(KC_O) // o acts as GUI (Cmd/Win) when held

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

    [BASE] = LAYOUT_60_ansi( // Base
        KC_ESC , KC_EXLM, KC_HASH, KC_AMPR, KC_ASTR, KC_PERC, KC_DLR , KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL , KC_DEL ,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_SCLN, KC_GRV , KC_BSLS,
        _______, HRM_A  , HRM_R  , HRM_S  , HRM_T  , KC_D   , KC_H   , HRM_N  , HRM_E  , HRM_I  , HRM_O  , KC_BSPC, _______,
        _______, KC_X   , KC_C   , KC_V   , KC_B   , KC_Z   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        QK_BOOT, _______, TO(SYM),                           KC_SPC ,                             TO(SYM), _______, TO(GAME), _______
    ),

    [SYM] = LAYOUT_60_ansi( // Symbols Row
        QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        _______, KC_MNXT, KC_MPLY, KC_MSTP, KC_MNXT, _______, KC_DOWN, KC_RGHT, KC_PGDN, KC_PGUP, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, _______, KC_HOME, KC_END , _______, KC_DEL , _______,
        KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , _______, KC_UP  , _______, KC_F19 , KC_F20 , KC_F21 , _______,
        _______, _______, DB_TOGG,                        TO(BASE),                               _______, QK_LOCK, _______, _______
    ),

    [GAME] = LAYOUT_60_ansi( // Gaming
        QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_BSPC, KC_RSFT,
        KC_CAPS, KC_X   , KC_C   , KC_V   , KC_B   , KC_Z   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC ,                             KC_LALT, KC_RCTL, TO(BASE), _______
    )
};

// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case HRM_A:
            return TAPPING_TERM + 150;
        case HRM_O:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
};
// clang-format off
///////////////////////////////////////////////////////////////////////////////
// Debug logging
///////////////////////////////////////////////////////////////////////////////
#if !defined(NO_DEBUG)
#    pragma message "dlog_record: enabled"

static void dlog_record(uint16_t keycode, keyrecord_t* record) {
    const char* key_name = get_keycode_string(keycode);
    dprintf("%u %s\n", record->event.pressed, key_name);
}
#else
#    pragma message "dlog_record: disabled"
#    define dlog_record(keycode, record)
#endif // !defined(NO_DEBUG) && defined(KEYCODE_STRING_ENABLE)
// clang-format on

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // return true;
    if (get_highest_layer(layer_state) > BASE) {
        uint8_t layer = get_highest_layer(layer_state);
                
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }

    return false;
}

// bool layer_lock_set_user(layer_state_t locked_layers) {
//     if (is_layer_locked(SYM)) {
//         RGB_MATRIX_INDICATOR_SET_COLOR(56, 0, 0, 255);
//     }

//     return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifndef NO_DEBUG
    dlog_record(keycode, record);
#endif

    return true;
}
