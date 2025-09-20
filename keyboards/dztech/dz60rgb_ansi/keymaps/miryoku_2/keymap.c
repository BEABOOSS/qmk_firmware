#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_CUSTOM_USER
#    include "features/palettefx.h"
#endif // RGB_MATRIX_CUSTOM_USER
#ifdef SELECT_WORD_ENABLE
#    include "features/select_word.h"
#endif // SELECT_WORD_ENABLE

enum layers {
    BASE,
    TAP,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUN,
    GAME,
};
enum {
    U_TD_BOOT,
    U_TD_U_TAP,
    U_TD_U_BASE,
    U_TD_U_NUM,
    U_TD_U_NAV,
    U_TD_U_MOUSE,
    U_TD_U_MEDIA,
    U_TD_U_SYM,
    U_TD_U_FUN,
    U_TD_U_GAME,
};


// static td_state_t td_state;

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        reset_keyboard();
    }
}

void u_td_fn_U_BASE(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << BASE);
    }
}

// to be fixed
void u_td_fn_U_TAP(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << GAME);
    }
}

void u_td_fn_U_NAV(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << NAV);
    }
}

void u_td_fn_U_MOUSE(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << MOUSE);
    }
}

void u_td_fn_U_MEDIA(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << MEDIA);
    }
}

void u_td_fn_U_NUM(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << NUM);
    }
}

void u_td_fn_U_SYM(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << SYM);
    }
}

void u_td_fn_U_FUN(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << FUN);
    }
}

void u_td_fn_U_GAME(tap_dance_state_t *state, void *user_data) {
    if(state->count == 2) {
        default_layer_set((layer_state_t)1 << GAME);
    }
}


enum custom_keycodes {
    ALT_MOD,
    RGBBRI,
    RGBNEXT,
    RGBHUP,
    RGBHRND,
    RGBDEF1,
    RGBDEF2,
    // Macros invoked through the Magic key.
#ifdef SELECT_WORD_ENABLE
    SELLINE,
    SELWBAK,
    SELWFWD,
#endif // SELECT_WORD_ENABLE
    M_NOOP,
};

bool alt_mod_active = false;

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // key is not assigned
#define U_NU KC_NO // key is not used

#define U_RDO C(S(KC_Z))
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

// Define the mod-tap keys for the home row
#define HRM_A LALT_T(KC_A)
#define HRM_R LGUI_T(KC_R)
#define HRM_S LSFT_T(KC_S)
#define HRM_T LCTL_T(KC_T)

#define HRM_N LCTL_T(KC_N)
#define HRM_E RSFT_T(KC_E)
#define HRM_I LGUI_T(KC_I)
#define HRM_O LALT_T(KC_O)

#define TME_ESC LT(MEDIA, KC_ESC)
#define TN_SPC LT(NAV, KC_SPC)
#define TMO_TAB LT(MOUSE, KC_TAB)

#define TS_ENT LT(SYM,KC_ENT)
#define TN_BSP LT(NUM,KC_BSPC)
#define TF_DEL LT(FUN,KC_DEL)

//
// gui plus alt
// shift and ctrl
//



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

    [BASE] = LAYOUT_60_ansi(  // Base layer
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, U_NP, U_NP, U_NP, KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,      U_NP,
        HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_D, U_NP, U_NP, U_NP, KC_H,    HRM_N,   HRM_E,   HRM_I, HRM_O,    U_NP,
        KC_X,    KC_C,    KC_V,    KC_B,    KC_Z, U_NP, U_NP, U_NP, KC_K,    KC_M,    KC_COMM, ALT_MOD,        KC_SLSH,
        U_NP,    TME_ESC, TN_SPC,  TMO_TAB, U_NP, U_NP, U_NP, U_NP, TS_ENT,  TN_BSP,  TF_DEL,                   U_NP,
        U_NP, U_NP,       U_NP,                         U_NP,                         U_NP,    U_NP,      U_NP, U_NP
    ),

    [NAV] = LAYOUT_60_ansi( // Symbols red
        TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_GAME),  TD(U_TD_U_BASE), U_NA, U_NP, U_NP, U_NP, U_RDO,   U_PST,   U_CPY,   U_CUT,  U_UND,    U_NP,
        KC_LALT,       KC_LGUI,        KC_LSFT,          KC_LCTL,         U_NA, U_NP, U_NP, U_NP, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  U_NP,
        U_NA,          KC_ALGR,        TD(U_TD_U_NUM),   TD(U_TD_U_NAV),  U_NA, U_NP, U_NP, U_NP, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP,          KC_END,
        U_NP,          U_NA,           U_NA,             U_NA,            U_NP, U_NP, U_NP, U_NP, KC_ENT,  KC_BSPC, KC_DEL,                    U_NP,
        U_NP, U_NP,    U_NP,                                                    U_NP,                      U_NP,    U_NP,                U_NP, U_NP
    ),

    [MOUSE] = LAYOUT_60_ansi(  // Navigation blue
        TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_GAME),  TD(U_TD_U_BASE), U_NA,    U_NP, U_NP, U_NP, U_RDO,        U_PST,   U_CPY,   U_CUT,   U_UND,   U_NP,
        KC_LALT,       KC_LGUI,        KC_LSFT,          KC_LCTL,         U_NA,    U_NP, U_NP, U_NP, U_NA,         KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NP,
        U_NA,          KC_ALGR,        TD(U_TD_U_SYM),   TD(U_TD_U_MOUSE),U_NA,    U_NP, U_NP, U_NP, U_NA,         KC_WH_L, KC_WH_D, KC_WH_U,          KC_WH_R,
        U_NP,          U_NA,           U_NA,             U_NA,            U_NP,    U_NP, U_NP, U_NP, KC_BTN2,      KC_BTN1, TF_DEL ,                   U_NP,
        U_NP, U_NP,    U_NP,                                                       U_NP,                                    U_NP,    U_NP,       U_NP, U_NP
    ),

    [MEDIA] = LAYOUT_60_ansi(  // Number PURPLE
        TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_GAME),  TD(U_TD_U_BASE), U_NA,    U_NP, U_NP, U_NP, RGB_TOG, RGB_MOD,   RGB_HUI, RGB_SAI, RGB_VAI, U_NP,
        KC_LALT,       KC_LGUI,        KC_LSFT,          KC_LCTL,         U_NA,    U_NP, U_NP, U_NP, U_NU,    KC_MPRV,   KC_VOLD, KC_VOLU, KC_MNXT, U_NP,
        DB_TOGG,          KC_ALGR,        TD(U_TD_U_FUN),   TD(U_TD_U_MEDIA),U_NA,    U_NP, U_NP, U_NP, OU_AUTO, U_NU,      U_NU,    U_NU,             U_NU,
        U_NP,          U_NA,           U_NA,             U_NA,            U_NP,    U_NP, U_NP, U_NP, KC_MSTP, KC_MPLY,   KC_MUTE,                   U_NP,
        U_NP, U_NP,    U_NP,                                                       U_NP,                               U_NP,    U_NP,       U_NP, U_NP
    ),

    [NUM] = LAYOUT_60_ansi(  // Window management layer GREEN
        KC_LBRC,      KC_7,            KC_8,             KC_9,            KC_RBRC, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_BASE), TD(U_TD_U_GAME),  TD(U_TD_U_TAP), TD(U_TD_BOOT), U_NP,
        KC_SCLN,      KC_4,            KC_5,             KC_6,            KC_EQL,  U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,          KC_LGUI,        KC_LALT,       U_NP,
        KC_GRV,       KC_1,            KC_2,             KC_3,            KC_BSLS, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_NUM),  TD(U_TD_U_NAV),   KC_ALGR,                       U_NA,
        U_NP,         KC_DOT,          KC_0,             KC_MINS,         U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,                                            U_NP,
        U_NP, U_NP,   U_NP,                                                        U_NP,                                    U_NP,             U_NP,              U_NP,       U_NP
    ),

    [SYM] = LAYOUT_60_ansi(  // Funky fun layer white
        KC_LCBR,      KC_AMPR,        KC_ASTR,           KC_LPRN,         KC_RCBR, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_BASE), TD(U_TD_U_GAME),  TD(U_TD_U_TAP), TD(U_TD_BOOT), U_NP,
        KC_COLN,      KC_DLR,         KC_PERC,           KC_CIRC,         KC_PLUS, U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,          KC_LGUI,        KC_LALT,       U_NP,
        KC_TILD,      KC_EXLM,        KC_AT,             KC_HASH,         KC_PIPE, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_NUM),  TD(U_TD_U_NAV),   KC_ALGR,                       U_NA,
        U_NP,         KC_LPRN,        KC_RPRN,           KC_UNDS,         U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,                                            U_NP,
        U_NP, U_NP,   U_NP,                                                        U_NP,                                    U_NP,             U_NP,                    U_NP, U_NP
    ),

    [FUN] = LAYOUT_60_ansi(  // Mouse and extra white
        KC_F12,       KC_F7,          KC_F8,             KC_F9,           KC_PSCR, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_BASE), TD(U_TD_U_GAME),  TD(U_TD_U_TAP), TD(U_TD_BOOT), U_NP,
        KC_F11,       KC_F4,          KC_F5,             KC_F6,           KC_SCRL, U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,          KC_LGUI,        KC_LALT,       U_NP,
        KC_F10,       KC_F1,          KC_F2,             KC_F3,           KC_PAUS, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_FUN),  TD(U_TD_U_MEDIA), KC_ALGR,                       U_NA,
        U_NP,         KC_APP,         KC_SPC,            KC_TAB,          U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,                                            U_NP,
        U_NP, U_NP,   U_NP,                                                        U_NP,                                    U_NP,             U_NP,                    U_NP, U_NP
    ),

    [GAME] = LAYOUT_60_ansi(  // Gaming Layer
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_BSPC, KC_RSFT,
        KC_CAPS, KC_X   , KC_C   , KC_V   , KC_B   , KC_Z   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                                KC_LALT, KC_F2, DF(BASE), KC_F3
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
// const uint16_t caps_combo[] PROGMEM = {KC_C, KC_COMM, COMBO_END};
// const uint16_t h_n_combo[] PROGMEM  = {KC_H, HRM_NN, COMBO_END};
// // clang-format off
// combo_t key_combos[] = {
//     COMBO(caps_combo, CW_TOGG),          // c and , => activate Caps Word.
//     COMBO(h_n_combo, OSL(FUN)),          // H and N => FUN layer
// };
// // clang-format on

const uint16_t PROGMEM thumbcombos_base_right[] = {LT(SYM, KC_ENT), LT(NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[] = {
    COMBO(thumbcombos_base_right, LT(FUN, KC_DEL)),
    COMBO(thumbcombos_base_left, LT(MEDIA, KC_ESC)),
    COMBO(thumbcombos_nav, KC_DEL),
    COMBO(thumbcombos_mouse, KC_BTN3),
    COMBO(thumbcombos_media, KC_MUTE),
    COMBO(thumbcombos_num, KC_DOT),
    COMBO(thumbcombos_sym, KC_LPRN),
    COMBO(thumbcombos_fun, KC_APP)
};

///////////////////////////////////////////////////////////////////////////////
// Tap-hold configuration (https://docs.qmk.fm/tap_hold)
///////////////////////////////////////////////////////////////////////////////
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case HRM_S:
        case HRM_E:
            return TAPPING_TERM - 35;
        default:
            return TAPPING_TERM;
    }
};

///////////////////////////////////////////////////////////////////////////////
// Caps word (https://docs.qmk.fm/features/caps_word)
///////////////////////////////////////////////////////////////////////////////
#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT_LSHIFT); // Apply shift to the next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_COLN:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

#endif // CAPS_WORD_ENABLE

///////////////////////////////////////////////////////////////////////////////
// RGB Matrix Lighting (https://docs.qmk.fm/features/rgb_matrix)
///////////////////////////////////////////////////////////////////////////////
#if RGB_MATRIX_CUSTOM_USER
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
    lighting_preset(RGB_MATRIX_CUSTOM_PALETTEFX_FLOW, PALETTEFX_AFTERBURN);
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
#endif // RGB_MATRIX_CUSTOM_USER

#if RGB_MATRIX_ENABLE
void set_layer_color(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                rgb_matrix_set_color(index, red, green, blue);
            }
            if (keymap_key_to_keycode(layer, (keypos_t){col, row}) <= KC_TRNS) {
                rgb_matrix_set_color(index, RGB_OFF);
            }
        }
    }
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    switch (layer) {
        case NAV:
            set_layer_color(led_min, led_max, layer, RGB_BLUE);
            break;
        case MOUSE:
            set_layer_color(led_min, led_max, layer, RGB_YELLOW);
            break;
        case MEDIA:
            set_layer_color(led_min, led_max, layer, RGB_PURPLE);
            break;
        case NUM:
            set_layer_color(led_min, led_max, layer, RGB_PINK);
            break;
        case SYM:
            set_layer_color(led_min, led_max, layer, RGB_GREEN);
            break;
        case FUN:
            set_layer_color(led_min, led_max, layer, RGB_RED);
            break;
        default:
            set_layer_color(led_min, led_max, layer, RGB_WHITE);
            break;
    }

    return false;
}
#endif // RGB_MATRIX_ENABLE

// clang-format off

///////////////////////////////////////////////////////////////////////////////
// Debug logging
///////////////////////////////////////////////////////////////////////////////

#if !defined(NO_DEBUG) && defined(KEYCODE_STRING_ENABLE)

#pragma message "dlog_record: enabled"
#include "print.h"
// #include "features/keycode_string.h"

// KEYCODE_STRING_NAMES_USER(
//   KEYCODE_STRING_NAME(SELLINE),
//   KEYCODE_STRING_NAME(SELWBAK),
//   KEYCODE_STRING_NAME(SELWFWD),
//   KEYCODE_STRING_NAME(RGBBRI),
//   KEYCODE_STRING_NAME(RGBNEXT),
//   KEYCODE_STRING_NAME(RGBHUP),
//   KEYCODE_STRING_NAME(RGBHRND),
//   KEYCODE_STRING_NAME(RGBDEF1),
//   KEYCODE_STRING_NAME(RGBDEF2),
// );

static void dlog_record(uint16_t keycode, keyrecord_t* record) {
  if (!debug_enable) { return; }
  uint8_t layer = read_source_layers_cache(record->event.key);
  bool is_tap_hold = IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode);
  xprintf("L%-2u ", layer);  // Log the layer.
  if (IS_COMBOEVENT(record->event)) {  // Combos don't have a position.
    xprintf("combo   ");
  } else {  // Log the "(row,col)" position.
    xprintf("(%2u,%2u) ", record->event.key.row, record->event.key.col);
  }
  xprintf("%-4s %-7s %s\n",  // "(tap|hold) (press|release) <keycode>".
      is_tap_hold ? (record->tap.count ? "tap" : "hold") : "",
      record->event.pressed ? "press" : "release",
      get_keycode_string(keycode));
}
#else
#pragma message "dlog_record: disabled"
#define dlog_record(keycode, record)
#endif  // !defined(NO_DEBUG) && defined(KEYCODE_STRING_ENABLE)


///////////////////////////////////////////////////////////////////////////////
// User functions
///////////////////////////////////////////////////////////////////////////////

// clang-format on

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_keyboard = true;
#if RGB_MATRIX_CUSTOM_USER
    lighting_init();
#endif // RGB_MATRIX_CUSTOM_USER
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef RGB_MATRIX_CUSTOM_USER
    lighting_activity_trigger();
#endif // RGB_MATRIX_CUSTOM_USER
#ifdef SELECT_WORD_ENABLE
    if (!process_select_word(keycode, record)) {
        return false;
    }
#endif // SELECT_WORD_ENABLE

    dlog_record(keycode, record);
    //const uint8_t layer = read_source_layers_cache(record->event.key);

    switch (keycode) {
        case ALT_MOD:
            if (record->event.pressed) {
                alt_mod_active = true;
                register_mods(MOD_BIT_LALT);
            } else {
                alt_mod_active = false;
                unregister_mods(MOD_BIT_LALT);
            }
            return false;
        case KC_COMM:
            if (alt_mod_active && record->event.pressed) {
                tap_code(KC_TAB); // Alt+Tab
                return false;
            }
            break;
        case KC_M:
            if (alt_mod_active && record->event.pressed) {
                register_mods(MOD_BIT_LSHIFT);
                tap_code(KC_TAB); // Shift+Alt+Tab
                unregister_mods(MOD_BIT_LSHIFT);
                return false;
            }
            break;

#ifdef SELECT_WORD_ENABLE
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
#endif // SELECT_WORD_ENABLE
    }

    return true;
}

tap_dance_action_t tap_dance_actions[] = {
    [U_TD_BOOT]      = ACTION_TAP_DANCE_FN(u_td_fn_boot), // Define this if you want a boot tap dance
    [U_TD_U_BASE]      = ACTION_TAP_DANCE_FN(u_td_fn_U_BASE), // Define this if you want a boot tap dance
    [U_TD_U_NUM]      = ACTION_TAP_DANCE_FN(u_td_fn_U_NUM), // Define this if you want a boot tap dance
    [U_TD_U_MOUSE]      = ACTION_TAP_DANCE_FN(u_td_fn_U_MOUSE), // Define this if you want a boot tap dance
    [U_TD_U_MEDIA]      = ACTION_TAP_DANCE_FN(u_td_fn_U_MEDIA), // Define this if you want a boot tap dance
    [U_TD_U_SYM]      = ACTION_TAP_DANCE_FN(u_td_fn_U_SYM), // Define this if you want a boot tap dance
    [U_TD_U_FUN]      = ACTION_TAP_DANCE_FN(u_td_fn_U_FUN), // Define this if you want a boot tap dance
    [U_TD_U_GAME]      = ACTION_TAP_DANCE_FN(u_td_fn_U_GAME), // Define this if you want a boot tap dance
    // Add more as needed
};



void housekeeping_task_user(void) {
#ifdef RGB_MATRIX_CUSTOM_USER
    lighting_task();
#endif // RGB_MATRIX_CUSTOM_USER
#ifdef SELECT_WORD_ENABLE
    select_word_task();
#endif // SELECT_WORD_ENABLE
}
