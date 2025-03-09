#include QMK_KEYBOARD_H

#ifdef KEYCODE_STRING_ENABLE
#    include "features/keycode_string.h"
#endif // KEYCODE_STRING_ENABLE
#ifdef ORBITAL_MOUSE_ENABLE
#    include "features/orbital_mouse.h"
#endif // ORBITAL_MOUSE_ENABLE
#ifdef RGB_MATRIX_CUSTOM_USER
#    include "features/palettefx.h"
#endif // RGB_MATRIX_CUSTOM_USER
#ifdef SELECT_WORD_ENABLE
#    include "features/select_word.h"
#endif // SELECT_WORD_ENABLE

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

enum custom_keycodes {
    ARROW = SAFE_RANGE,
    STDCC,
    USRNAME,
    SELLINE,
    SELWBAK,
    SELWFWD,
    RGBBRI,
    RGBNEXT,
    RGBHUP,
    RGBHRND,
    RGBDEF1,
    RGBDEF2,
    // Macros invoked through the Magic key.
    M_DOCSTR,
    M_EQEQ,
    M_INCLUDE,
    M_ION,
    M_MENT,
    M_MKGRVS,
    M_QUEN,
    M_THE,
    M_TMENT,
    M_NBSP,
    M_NOOP,
};

// The "magic" key is the Alternate Repeat Key.
#define MAGIC QK_AREP
// F20 mutes the mic on my system.
#define MUTEMIC KC_F21

// Define the mod-tap keys for the home row
#define HRM_A LALT_T(KC_A)
#define HRM_SR LT(SYM, KC_R)
#define HRM_S LSFT_T(KC_S)
#define HRM_NT LT(NAV, KC_T)
#define HRM_B LCTL_T(KC_B)
#define HRM_X LGUI_T(KC_X)

#define HRM_NN LT(NUM, KC_N)
#define HRM_E RSFT_T(KC_E)
#define HRM_SI LT(SYM, KC_I)
#define HRM_O LALT_T(KC_O)
#define HRM_M RCTL_T(KC_M)
#define HRM_WDOT LT(WIN, KC_DOT)
#define HRM_SLS RGUI_T(KC_SLSH)

#define EXT_EQ LT(EXT, KC_Q)
#define NAV_SLS LT(NAV, KC_SLSH)
#define NAV_BEQL LT(BASE, KC_EQL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    //
    // [0] = LAYOUT_60_ansi(
    //     QK_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    //     KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    //     CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    //     KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    //     KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   MO(2),   KC_RCTL
    // ),

    [BASE] = LAYOUT_60_ansi(  // Base layer green
        KC_ESC , SELLINE, C(KC_V), C(KC_A), C(KC_C), MS_BTN1, KC_HOME, KC_LEFT, KC_RGHT, KC_END , KC_TAB , KC_MPLY, _______, _______,
        KC_TAB , EXT_EQ , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, _______, _______, _______,
        MAGIC  , HRM_A  , HRM_SR , HRM_S  , HRM_NT , KC_D   , KC_H   , HRM_NN , HRM_E  , HRM_SI , HRM_O  , KC_BSPC, MAGIC  ,
        _______, HRM_X  , KC_C   , KC_V   , HRM_B  , KC_Z   , KC_K   , HRM_M  , KC_COMM, HRM_WDOT, HRM_SLS, KC_ENT ,
        _______, _______, _______,                         KC_SPC,                                _______, _______, _______, _______
    ),

    [SYM] = LAYOUT_60_ansi( // Symbols red
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_GRV , KC_LT  , KC_GT  , KC_MINS, KC_PIPE, KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR , _______, _______, _______, _______,
        _______, KC_EXLM, KC_ASTR, NAV_SLS, NAV_BEQL, KC_AMPR, KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, _______, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC, KC_AT  , KC_COLN, KC_COMM, KC_DOT , KC_QUOT, _______,
        _______, _______, USRNAME,                         KC_SPC,                                _______, _______, _______, _______
    ),

    [NAV] = LAYOUT_60_ansi(  // Navigation blue
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_WREF, C(KC_PGUP), C(KC_PGDN), _______, _______, KC_PGUP, KC_HOME, KC_UP  , KC_END  , _______, _______, _______, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, SELLINE, MS_BTN1, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , _______, _______,
        _______, KC_LGUI, KC_PGUP, KC_PGDN, _______, _______, C(KC_Z), SELWBAK, SELWFWD, KC_APP , XXXXXXX, _______,
        _______, _______, _______,                         KC_SPC,                                QK_LOCK, _______, _______, _______
    ),

    [NUM] = LAYOUT_60_ansi(  // Number white
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_SLSH, KC_9   , KC_8   , KC_7   , KC_ASTR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,
        _______, KC_MINS, KC_3   , KC_2   , KC_1   , KC_PLUS, KC_0   , XXXXXXX, KC_E   , KC_RCTL, KC_LALT, _______, _______,
        _______, KC_X   , KC_6   , KC_5   , KC_4   , KC_PERC, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT , KC_LGUI, _______,
        _______, _______, _______,                         KC_SPC,                                QK_LOCK, _______, _______, _______
    ),

    [WIN] = LAYOUT_60_ansi(  // Window management layer white
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, MUTEMIC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, XXXXXXX, KC_LALT, XXXXXXX, _______,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(A(KC_TAB)), A(KC_TAB), XXXXXXX, XXXXXXX, G(KC_ENT),
        _______, _______, _______,                         KC_SPC,                                QK_LOCK, _______, _______, _______
    ),

    [FUN] = LAYOUT_60_ansi(  // Funky fun layer white
        _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, _______, _______,
        XXXXXXX, KC_F18 , KC_F9  , KC_F8  , KC_F7  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        XXXXXXX, KC_F10 , KC_F14  , KC_F19  , KC_F20  , XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, XXXXXXX, _______,
        XXXXXXX, KC_F11 , KC_F6  , KC_F5  , KC_F4  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, QK_RBT ,
        _______, _______, DB_TOGG,                         KC_SPC,                                QK_LOCK, _______, _______, _______
    ),

    [EXT] = LAYOUT_60_ansi(  // Mouse and extra white
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LALT, KC_LCTL, KC_LSFT, SELLINE, XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LGUI, C(KC_V), C(KC_A), C(KC_C), C(KC_X), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______,                         KC_SPC,                                QK_LOCK, _______, _______, _______
    ),

    [GAME] = LAYOUT_60_ansi(  // Gaming Layer
        QK_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_BSPC, KC_RSFT,
        KC_CAPS, KC_X   , KC_C   , KC_V   , KC_B   , KC_Z   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                                KC_LALT, KC_RCTL, TO(BASE), _______
    )
};
// clang-format on
// A cheap pseudorandom generator.
uint8_t myrand(void) {
    static uint16_t state = 1;
    state                 = UINT16_C(36563) * (state + timer_read());
    return state >> 8;
}

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
// const uint16_t caps_combo[] PROGMEM = {KC_J, KC_COMM, COMBO_END};
// const uint16_t c_v_combo[] PROGMEM = {KC_C, KC_V, COMBO_END};
// const uint16_t h_comm_combo[] PROGMEM = {HRM_H, KC_COMM, COMBO_END};
// const uint16_t comm_dot_combo[] PROGMEM = {KC_COMM, HRM_DOT, COMBO_END};
const uint16_t h_n_combo[] PROGMEM = {KC_H, HRM_NN, COMBO_END};
// clang-format off
combo_t key_combos[] = {
    // COMBO(caps_combo, CW_TOGG),          // J and , => activate Caps Word.
    // COMBO(c_v_combo, KC_BSLS),           // c and v => backslash
    // COMBO(h_comm_combo, KC_QUOT),        // H and , => '
    // COMBO(comm_dot_combo, KC_SCLN),      // , and . => ;
    COMBO(h_n_combo, OSL(FUN)),          // H and N => FUN layer
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case HRM_S:
        case HRM_E:
            return TAPPING_TERM - 45;
        default:
            return TAPPING_TERM;
    }
};

// The following describes the magic key functionality, where * represents the
// magic key and @ the repeat key. For example, tapping A and then the magic key
// types "ao". Most of this is coded in my `get_alt_repeat_key_keycode_user()`
// definition below.
//
// SFB removal and common n-grams:
//
//     A * -> AO     L * -> LK      S * -> SK
//     C * -> CY     M * -> MENT    T * -> TMENT
//     D * -> DY     O * -> OA      U * -> UE
//     E * -> EU     P * -> PY      Y * -> YP
//     G * -> GY     Q * -> QUEN    spc * -> THE
//     I * -> ION    R * -> RL
//
// When the magic key types a letter, following it with the repeat key produces
// "n". This is useful to type certain patterns without SFBs.
//
//     A * @ -> AON             (like "kaon")
//     D * @ -> DYN             (like "dynamic")
//     E * @ -> EUN             (like "reunite")
//     O * @ -> OAN             (like "loan")
//
// Other patterns:
//
//     spc * @ -> THEN
//     I * @ -> IONS            (like "nations")
//     M * @ -> MENTS           (like "moments")
//     Q * @ -> QUENC           (like "frequency")
//     T * @ -> TMENTS          (like "adjustments")
//     = *   -> ===             (JS code)
//     ! *   -> !==             (JS code)
//     " *   -> """<cursor>"""  (Python code)
//     ` *   -> ```<cursor>```  (Markdown code)
//     # *   -> #include        (C code)
//     & *   -> &nbsp;          (HTML code)
//     . *   -> ../             (shell)
//     . * @ -> ../../
// uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
//     if (mods == MOD_BIT_LALT) {
//         switch (keycode) {
//             case KC_U:
//                 return A(KC_O);
//             case KC_O:
//                 return A(KC_U);
//             case HRM_NN:
//                 return A(KC_I);
//             case HRM_SI:
//                 return A(KC_N);
//         }
//     } else if ((mods & ~MOD_MASK_SHIFT) == 0) {
//         // This is where most of the "magic" for the MAGIC key is implemented.
//         switch (keycode) {
//             case KC_SPC: // spc -> THE
//             case KC_ENT:
//             case KC_TAB:
//                 return M_THE;

//             // For navigating next/previous search results in Vim:
//             // N -> Shift + N, Shift + N -> N.
//             case HRM_NN:
//                 if ((mods & MOD_MASK_SHIFT) == 0) {
//                     return S(KC_N);
//                 }
//                 // Fall through intended.
//             case KC_N:
//                 return KC_N;
//             // Fix SFBs and awkward strokes.
//             case HRM_E:
//                 return KC_U; // E -> U
//             case KC_U:
//                 return KC_E; // U -> E
//             case HRM_SI:
//                 if ((mods & MOD_MASK_SHIFT) == 0) {
//                     return M_ION; // I -> ON
//                 } else {
//                     return KC_QUOT; // Shift I -> '
//                 }
//             case KC_M:
//                 return M_MENT; // M -> ENT
//             case EXT_EQ:
//                 return M_QUEN; // Q -> UEN
//             case HRM_NT:
//                 return M_TMENT; // T -> TMENT

//             case KC_P:
//                 return KC_D; // P -> D
//             // case HRM_NT:
//             //     return KC_D; // T -> D
//             case HRM_B:
//                 return KC_D; // B -> D
//             case KC_G:
//                 return KC_D; // G -> D
//             case KC_D:
//                 return KC_P; // D -> P

//             case KC_F:
//                 return KC_C; // F -> C
//             case HRM_A:
//                 return KC_C; // A -> C

//             case HRM_S:
//                 return KC_F; // S -> F
//             // case HRM_WDOT:
//             //     // if ((mods & MOD_MASK_SHIFT) == 0) {
//             //     //     return M_UPDIR; // . -> ./
//             //     // }
//             //     return M_NOOP;
//             case KC_HASH:
//                 return M_INCLUDE; // # -> include
//             case KC_AMPR:
//                 return M_NBSP; // & -> nbsp;
//             case KC_EQL:
//                 return M_EQEQ; // = -> ==
//             case KC_RBRC:
//                 return KC_SCLN; // ] -> ;
//             case KC_AT:
//                 return USRNAME; // @ -> <username>

//             case KC_COMM:
//                 if ((mods & MOD_MASK_SHIFT) != 0) {
//                     return KC_EQL; // ! -> =
//                 }
//                 return M_NOOP;
//             case HRM_O:
//                 if ((mods & MOD_MASK_SHIFT) != 0) {
//                     return M_DOCSTR; // " -> ""<cursor>"""
//                 }
//                 return M_NOOP;
//             case KC_GRV: // ` -> ``<cursor>``` (for Markdown code)
//                 return M_MKGRVS;
//         }
//     }
//     return KC_TRNS;
// }

// // An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// // held while sending the string. Additionally, the last key is set such that if
// // the Repeat Key is pressed next, it produces `repeat_keycode`. This helper is
// // used for several macros below in my process_record_user() function.
// #define MAGIC_STRING(str, repeat_keycode) magic_send_string_P(PSTR(str), (repeat_keycode))
// static void magic_send_string_P(const char* str, uint16_t repeat_keycode) {
//     send_string_P(str); // Send the string.
//     set_last_keycode(repeat_keycode);
// }

///////////////////////////////////////////////////////////////////////////////
// RGB Matrix Lighting (https://docs.qmk.fm/features/rgb_matrix)
///////////////////////////////////////////////////////////////////////////////
#if RGB_MATRIX_ENABLE
// The following logic controls the RGB Matrix light level with a convenient
// 3-state setting---off, dim, or full---and turns off automatically and with
// smooth transitions when the keyboard is idle.

#    include <lib/lib8tion/lib8tion.h>

static struct {
    uint32_t timer;
    uint8_t  event_count;
    uint8_t  val;
    uint8_t  val_start;
    uint8_t  val_end;
} lighting = {0};

static void lighting_set_val(uint8_t val) {
    lighting.val     = val;
    lighting.val_end = val;
    if (lighting.val_start != lighting.val_end) {
        lighting.timer = timer_read32();
    }
}

/** Cycles between off, 40% brightness, and max brightness. */
static void lighting_cycle_3_state(void) {
    if (lighting.val == 0) {
        lighting_set_val((RGB_MATRIX_MAXIMUM_BRIGHTNESS * 2 + 2) / 5);
    } else if (lighting.val < RGB_MATRIX_MAXIMUM_BRIGHTNESS) {
        lighting_set_val(RGB_MATRIX_MAXIMUM_BRIGHTNESS);
    } else {
        lighting_set_val(0);
    }
}

static void lighting_set_palette(uint8_t palette) {
    if (lighting.val == 0) {
        lighting_cycle_3_state();
    }
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * palette, 255, rgb_matrix_get_val());
}

static void lighting_preset(uint8_t effect, uint8_t palette) {
    lighting_set_palette(palette);
    rgb_matrix_mode_noeeprom(effect);
    rgb_matrix_set_speed_noeeprom(100);
}

static void lighting_init(void) {
    lighting.val_start = 0;
    lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_RIPPLE, PALETTEFX_CARNIVAL);
    lighting_set_val(RGB_MATRIX_MAXIMUM_BRIGHTNESS);
}

static void lighting_set_sleep_timer(void) {
    if (lighting.val_start == lighting.val_end) {
        const uint32_t duration = (lighting.event_count <= 10) ? UINT32_C(5000) : UINT32_C(30000);
        lighting.timer          = (timer_read32() + duration) | 1;
    }
}

/** This function should be called on every key event to keep lights awake. */
static void lighting_activity_trigger(void) {
    if (lighting.val > 0) {
        lighting.event_count = qadd8(lighting.event_count, 1);
        if (lighting.val_end == 0) {
            lighting_set_val(lighting.val); // Wake lighting.
        } else {
            lighting_set_sleep_timer();
        }
    }
}

static void lighting_task(void) {
    if (!lighting.timer) {
        return;
    } // Early return if sleeping.
    const uint32_t diff = timer_read32() - lighting.timer;

    if (lighting.val_start != lighting.val_end) {
        const uint8_t t = (diff <= 511) ? (uint8_t)(diff / 2) : 255;

        hsv_t hsv = rgb_matrix_get_hsv();
        hsv.v     = (t == 255) ? lighting.val_end : lerp8by8(lighting.val_start, lighting.val_end, ease8InOutCubic(t));
        rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);

        if (t == 255) { // Transition complete.
            lighting.val_end   = rgb_matrix_get_val();
            lighting.val_start = lighting.val_end;
            if (lighting.val_end == 0) { // Sleep.
                lighting.timer       = 0;
                lighting.event_count = 0;
            } else {
                lighting_set_sleep_timer();
            }
        }
    } else if (diff < UINT32_MAX / 2) { // Sleep timeout expired; begin fading.
        lighting.val_end = 0;
    }
}
#endif // RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // return true;
    if (get_highest_layer(layer_state) == BASE) {
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

    if (get_highest_layer(layer_state) == SYM) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_RED);
                }
            }
        }
    }

    if (get_highest_layer(layer_state) == NAV) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_BLUE);
                }
            }
        }
    }

    if (get_highest_layer(layer_state) > NAV) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_WHITE);
                }
            }
        }
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#if RGB_MATRIX_ENABLE
    lighting_init();
#endif // RGB_MATRIX_ENABLE

#ifdef RGB_MATRIX_ENABLE
    lighting_activity_trigger();
#endif // RGB_MATRIX_ENABLE
#ifdef ORBITAL_MOUSE_ENABLE
    if (!process_orbital_mouse(keycode, record)) {
        return false;
    }
#endif // ORBITAL_MOUSE_ENABLE
#ifdef SELECT_WORD_ENABLE
    if (!process_select_word(keycode, record)) {
        return false;
    }
#endif // SELECT_WORD_ENABLE

    // dlog_record(keycode, record);

    static bool left_home_ring_held  = false;
    static bool left_home_index_held = false;
    if (record->event.key.row == LEFT_HOME_ROW) {
        switch (record->event.key.col) {
            case LEFT_HOME_RING_COL:
                left_home_ring_held = record->event.pressed;
                break;
            case LEFT_HOME_INDEX_COL:
                left_home_index_held = record->event.pressed;
                break;
        }

        // NAV stays on while layer locked or while either ring or index is held.
        if ((is_layer_locked(NAV) || left_home_ring_held || left_home_index_held)) {
            layer_off(NAV);
        }
    }

    // Logic for Alt mod when using alt-tabbing keys.
    if (keycode == HRM_O && record->tap.count == 0 && !record->event.pressed) {
        unregister_mods(MOD_BIT(KC_LALT)); // not exactly sure
    } else if (record->event.pressed && (keycode == S(A(KC_TAB)) || keycode == A(KC_TAB))) {
        register_mods(MOD_BIT(KC_LALT)); // not exactly sure
    }

    // gets the current state of a modifier
    const uint8_t mods = get_mods();
    /// const uint8_t all_mods   = (mods | get_weak_mods());
    // const uint8_t shift_mods = all_mods & MOD_MASK_SHIFT;
    // const bool    alt        = all_mods & MOD_BIT(KC_LALT);
    const uint8_t layer = read_source_layers_cache(record->event.key);

    if (layer == SYM && record->event.pressed) {
        clear_weak_mods();
        send_keyboard_report();
    }

    // // If alt repeating key A, E, I, O, U, Y with no mods other than Shift, set
    // // the last key to KC_N. Above, alternate repeat of KC_N is defined to be
    // // again KC_N. This way, either tapping alt repeat and then repeat (or
    // // equivalently double tapping alt repeat) is useful to type certain patterns
    // // without SFBs:
    // //
    // //   D <altrep> <rep> -> DYN (as in "dynamic")
    // //   O <altrep> <rep> -> OAN (as in "loan")
    // if (get_repeat_key_count() < 0 && (all_mods & ~MOD_MASK_SHIFT) == 0 && (keycode == KC_A || keycode == KC_E || keycode == KC_I || keycode == KC_O || keycode == KC_U || keycode == KC_Y)) {
    //     set_last_keycode(KC_N);
    //     set_last_mods(0);
    // }

    switch (keycode) {
        case SELWBAK: // Backward word selection.
            if (record->event.pressed) {
                select_word_register('B');
            } else {
                select_word_unregister();
            }
            break;

        case SELWFWD: // Forward word selection.
            if (record->event.pressed) {
                select_word_register('W');
            } else {
                select_word_unregister();
            }
            break;

        case SELLINE: // Line selection.
            if (record->event.pressed) {
                select_word_register('L');
            } else {
                select_word_unregister();
            }
            break;

        case HRM_SR:
            if (!record->tap.count) {
                if (record->event.pressed) {
                    if ((mods & MOD_BIT_LSHIFT) != 0) {
                        register_mods(MOD_BIT_LCTRL);
                        layer_on(NAV);
                    } else {
                        layer_on(SYM);
                    }
                } else {
                    unregister_mods(MOD_BIT_LCTRL);
                    layer_off(SYM);
                }
                return false;
            }
            return true;

        case HRM_NT: // NAV switch.
            if (!record->tap.count) {
                if (record->event.pressed) {
                    layer_on(NAV);
                }
                return false;
            }
            return true;
    }

    // if (record->event.pressed) {
    //     switch (keycode) {
    //         case USRNAME:
    //             add_oneshot_mods(shift_mods);
    //             clear_weak_mods();
    //             MAGIC_STRING("BEABOOSS", KC_AT);
    //             return false;
    //         // Macros invoked through the MAGIC key.
    //         case M_THE:
    //             MAGIC_STRING(/* */ "the", KC_N);
    //             break;
    //         case M_ION:
    //             MAGIC_STRING(/*i*/ "on", KC_S);
    //             break;
    //         case M_MENT:
    //             MAGIC_STRING(/*m*/ "ent", KC_S);
    //             break;
    //         case M_QUEN:
    //             MAGIC_STRING(/*q*/ "uen", KC_C);
    //             break;
    //         case M_TMENT:
    //             MAGIC_STRING(/*t*/ "ment", KC_S);
    //             break;
    //         case M_INCLUDE:
    //             SEND_STRING_DELAY(/*#*/ "include ", TAP_CODE_DELAY);
    //             break;
    //         case M_EQEQ:
    //             SEND_STRING_DELAY(/*=*/"==", TAP_CODE_DELAY);
    //             break;
    //         case M_NBSP:
    //             SEND_STRING_DELAY(/*&*/ "nbsp;", TAP_CODE_DELAY);
    //             break;
    //         case M_DOCSTR:
    //             SEND_STRING_DELAY(/*"*/ "\"\"\"\"\"" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT), TAP_CODE_DELAY);
    //             break;
    //         case M_MKGRVS:
    //             SEND_STRING_DELAY(/*`*/ "``\n\n```" SS_TAP(X_UP), TAP_CODE_DELAY);
    //             break;
    //     }
    // }

    return true;
}

void housekeeping_task_user(void) {
#ifdef RGB_MATRIX_ENABLE
    lighting_task();
#endif // RGB_MATRIX_ENABLE
#ifdef ORBITAL_MOUSE_ENABLE
    orbital_mouse_task();
#endif // ORBITAL_MOUSE_ENABLE
#ifdef SELECT_WORD_ENABLE
    select_word_task();
#endif // SELECT_WORD_ENABLE
}
