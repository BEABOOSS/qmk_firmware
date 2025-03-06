#include QMK_KEYBOARD_H

enum layers {
    BASE, // breath
    SYM,  // Symbols, color 1
    NAV,  // Navigation, color 2
    NUM,  // Numpad, color 3
    WIN,  // Window management, color 4
    FUN,  // Funky, color 5
    EXT,  // Extras, color 6
    GAME, // GAMING, color 7
};

// then if layer lock is true then
// add a specific set of keys to be red

// Define the mod-tap keys for the home row
#define HRM_A LALT_T(KC_A)
#define HRM_R LT(SYM, KC_R)
#define HRM_S LSFT_T(KC_S)
#define HRM_T LT(NAV, KC_T)
#define HRM_B LCTL_T(KC_B)
#define HRM_X LGUI_T(KC_X)

#define HRM_N LT(NUM, KC_N)
#define HRM_E RSFT_T(KC_E)
#define HRM_I LT(SYM, KC_I)
#define HRM_O LALT_T(KC_O)
#define HRM_K RCTL_T(KC_K)
#define HRM_SLS RGUI_T(KC_SLSH)



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

    [BASE] = LAYOUT_60_ansi( // Base layer
        QK_GESC, KC_EXLM, KC_HASH, KC_AMPR, KC_ASTR, KC_PERC, KC_DLR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL, KC_DEL,
        KC_TAB,     KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,   KC_J,   KC_L,    KC_U,   KC_Y,    KC_QUOT, KC_SCLN, KC_GRV, KC_BSLS,
        _______,    HRM_A,   HRM_R,  HRM_S,   HRM_T,   KC_D,   KC_H,   HRM_N,   HRM_E,  HRM_I,   HRM_O, KC_BSPC,          _______,
        _______,      HRM_X,    KC_C,   KC_V,   HRM_B,   KC_Z,  HRM_K,  KC_M,    KC_COMM, KC_DOT, HRM_SLS,                 KC_ENT,
        _______, _______, TO(SYM),                         KC_SPC,                                    TO(SYM), _______, TO(GAME), _______
    ),


    [SYM] = LAYOUT_60_ansi( // Symbols Row / nav
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        _______, KC_MNXT, KC_MPLY, KC_MSTP, KC_MNXT, _______, KC_DOWN, KC_RIGHT, KC_PGDN, KC_PGUP, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_LEFT, _______, KC_HOME, KC_END, _______, KC_DEL, _______,
        KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, _______, KC_UP, _______, KC_F19, KC_F20, KC_F21, _______,
        _______, _______, _______, TO(BASE), _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_60_ansi( // Navigation
        QK_GESC, KC_EXLM, KC_HASH, KC_AMPR, KC_ASTR, KC_PERC, KC_DLR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL, KC_DEL,
        KC_TAB,     KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,   KC_J,   KC_L,    KC_U,   KC_Y,    KC_QUOT, KC_SCLN, KC_GRV, KC_BSLS,
        _______,    HRM_A,   HRM_R,  HRM_S,   HRM_T,   KC_D,   KC_H,   HRM_N,   HRM_E,  HRM_I,   HRM_O, KC_BSPC,          _______,
        _______,      HRM_X,    KC_C,   KC_V,   HRM_B,   KC_Z,  HRM_K,  KC_M,    KC_COMM, KC_DOT, HRM_SLS,                 KC_ENT,
        _______, _______, TO(SYM),                         KC_SPC,                                    TO(SYM), _______, TO(BASE), _______
    ),

    [NUM] = LAYOUT_60_ansi( // Number
        QK_GESC, KC_EXLM, KC_HASH, KC_AMPR, KC_ASTR, KC_PERC, KC_DLR, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL, KC_DEL,
        KC_TAB,     KC_Q,    KC_W,   KC_F,    KC_P,    KC_G,   KC_J,   KC_L,    KC_U,   KC_Y,    KC_QUOT, KC_SCLN, KC_GRV, KC_BSLS,
        _______,    HRM_A,   HRM_R,  HRM_S,   HRM_T,   KC_D,   KC_H,   HRM_N,   HRM_E,  HRM_I,   HRM_O, KC_BSPC,          _______,
        _______,      HRM_X,    KC_C,   KC_V,   HRM_B,   KC_Z,  HRM_K,  KC_M,    KC_COMM, KC_DOT, HRM_SLS,                 KC_ENT,
        _______, _______, TO(SYM),                         KC_SPC,                                    TO(SYM), _______, TO(BASE), _______
    ),
    // Gaming
    [FUN] = LAYOUT_60_ansi(
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_BSPC, KC_RSFT,
        KC_CAPS, KC_X, KC_C, KC_V, KC_B, KC_Z, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LALT, KC_RCTL, TO(BASE), _______
    )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_O:
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
};



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case BASE:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case SYM:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case NAV:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0xFF,  0xFF, 0x00);
        break;
    }
  return state;
}
