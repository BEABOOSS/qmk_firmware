#include QMK_KEYBOARD_H

enum layers {
    BASE,
    SYM,
    NAV,
    NUM,
    WIN,
    FUN,
    EXT,
};

// Define the mod-tap keys for the home row
#define HOME_A LGUI_T(KC_A) // A acts as GUI (Cmd/Win) when held
#define HOME_R LALT_T(KC_R) // R acts as Alt when held
#define HOME_S LSFT_T(KC_S) // s acts as Shift when held
#define HOME_T LCTL_T(KC_T) // t acts as Ctrl when held

#define HOME_N RCTL_T(KC_N) // n acts as Ctrl when held
#define HOME_E RSFT_T(KC_E) // e acts as Shift when held
#define HOME_I LALT_T(KC_I) // i acts as Alt when held
#define HOME_O RGUI_T(KC_O) // o acts as GUI (Cmd/Win) when held

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    // Typing layer
    [0] = LAYOUT_60_ansi(
        QK_GESC, KC_EXLM, KC_HASH, KC_AMPR, KC_ASTR, KC_PERC, KC_DLR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_SCLN, KC_GRV, KC_BSLS,
        _______, HOME_A, HOME_R, HOME_S, HOME_T, KC_D, KC_H, HOME_N, HOME_E, HOME_I, HOME_O, KC_BSPC, _______,
        _______, KC_X, KC_C, KC_V, KC_B, KC_Z, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        _______, _______, TO(1), KC_SPC, TO(1), _______, TO(2), _______
    ),
    // Symbols Row / nav
    [1] = LAYOUT_60_ansi(
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        _______, KC_MNXT, KC_MPLY, KC_MSTP, KC_MNXT, _______, KC_DOWN, KC_RIGHT, KC_PGDN, KC_PGUP, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, _______, KC_HOME, KC_END, _______, KC_DEL, _______,
        KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, _______, KC_UP, _______, KC_F19, KC_F20, KC_F21, _______,
        _______, _______, _______, TO(0), _______, _______, _______, _______
    ),
    // Gaming
    [2] = LAYOUT_60_ansi(
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_BSPC, KC_RSFT,
        KC_CAPS, KC_X, KC_C, KC_V, KC_B, KC_Z, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LALT, KC_RCTL, TO(0), _______
    )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return TAPPING_TERM + 150;
        case HOME_O:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
};
