#include QMK_KEYBOARD_H

// FIX KEYBOARD
// todo update current layout to follow the TD_XXXX format
// todo: fix any other issues so this keymap can be rebuilt again

enum layers {
    BASE,
    NAV,
    MOUSE,
    NUM,
    MEDIA,
    SYM,
    FUN,
    GAME,
    QWERTY,
    LAYER_COUNT
};
enum {
    TD_BOOT,
    TD_BASE,
    TD_NUM,
    TD_NAV,
    TD_MOUSE,
    TD_MEDIA,
    TD_SYM,
    TD_FUN,
    TD_GAME,
    TD_QWERTY,
    TD_COUNT, // keep last
};


// Helper to compute the current effective layer.
static inline uint8_t effective_layer_state(layer_state_t st) {
    return get_highest_layer(st | default_layer_state);
}
static inline uint8_t effective_layer_now(void) {
    return effective_layer_state(layer_state);
}

// Replace the per-layer tap-dance functions with a single macro.
#define TD_SET_DEF_FN(fname, target_layer)                  \
    void fname(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) {                            \
            default_layer_set(1UL << (target_layer));       \
        }                                                   \
    }

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

// Generate all layer-switch TD handlers.
TD_SET_DEF_FN(u_td_fn_U_BASE, BASE)
TD_SET_DEF_FN(u_td_fn_U_NAV, NAV)
TD_SET_DEF_FN(u_td_fn_U_MOUSE, MOUSE)
TD_SET_DEF_FN(u_td_fn_U_MEDIA, MEDIA)
TD_SET_DEF_FN(u_td_fn_U_NUM, NUM)
TD_SET_DEF_FN(u_td_fn_U_SYM, SYM)
TD_SET_DEF_FN(u_td_fn_U_FUN, FUN)
TD_SET_DEF_FN(u_td_fn_U_GAME, GAME)
TD_SET_DEF_FN(u_td_fn_U_QWERTY, QWERTY)


enum custom_keycodes {
    ALT_MOD,
    RGBBRI,
    RGBNEXT,
    RGBHUP,
    RGBHRND,
    RGBDEF1,
    RGBDEF2,
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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [BASE] = LAYOUT_60_ansi(  // Base layer
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, U_NP, U_NP, U_NP, KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,      U_NP,
        HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_D, U_NP, U_NP, U_NP, KC_H,    HRM_N,   HRM_E,   HRM_I, HRM_O,    U_NP,
        KC_X,    KC_C,    KC_V,    KC_B,    KC_Z, U_NP, U_NP, U_NP, KC_K,    KC_M,    KC_COMM, ALT_MOD,        KC_SLSH,
        U_NP,    TME_ESC, TN_SPC,  TMO_TAB, U_NP, U_NP, U_NP, U_NP, TS_ENT,  TN_BSP,  TF_DEL,                   U_NP,
        U_NP, U_NP,       U_NP,                         U_NP,                         U_NP,    U_NP,      U_NP, U_NP
    ),

    [NAV] = LAYOUT_60_ansi( // Symbols red
        TD(TD_BOOT), TD(TD_NAV), TD(TD_GAME),  TD(TD_BASE),  U_NA, U_NP, U_NP, U_NP, U_RDO,   U_PST,   U_CPY,   U_CUT,  U_UND, TD(TD_QWERTY),
        KC_LALT,       KC_LGUI,      KC_LSFT,      KC_LCTL,  U_NA, U_NP, U_NP, U_NP, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  U_NP,
        U_NA,          KC_ALGR,   TD(TD_NUM),   TD(TD_NAV),  U_NA, U_NP, U_NP, U_NP, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP,      KC_END,
        U_NP,          U_NA,           U_NA,          U_NA,        U_NP, U_NP, U_NP, U_NP, KC_ENT,  KC_BSPC, KC_DEL,         U_NP,
        U_NP, U_NP,    U_NP,                                              U_NP,                      U_NP,    U_NP,    U_NP, U_NP
    ),

    [MOUSE] = LAYOUT_60_ansi(  // Navigation blue
        TD(TD_BOOT), TD(TD_NAV), TD(TD_GAME),  TD(TD_BASE), U_NA,   U_NP, U_NP, U_NP, U_RDO, U_PST,    U_CPY,   U_CUT,   U_UND, TD(TD_QWERTY),
        KC_LALT,       KC_LGUI,      KC_LSFT,      KC_LCTL, U_NA,   U_NP, U_NP, U_NP, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  U_NP,
        U_NA,          KC_ALGR,   TD(TD_SYM), TD(TD_MOUSE), U_NA,   U_NP, U_NP, U_NP, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP,     KC_END,
        U_NP,          U_NA,            U_NA,         U_NA,         U_NP, U_NP, U_NP, U_NP, KC_ENT,  KC_BSPC, KC_DEL,         U_NP,
        U_NP, U_NP,    U_NP,                                              U_NP,                      U_NP,    U_NP,    U_NP, U_NP
    ),

    [MEDIA] = LAYOUT_60_ansi(  // Number PURPLE
        TD(TD_BOOT), TD(TD_NAV), TD(TD_GAME),  TD(TD_BASE), U_NA,    U_NP, U_NP, U_NP, CW_TOGG, U_NU,    U_NU,    U_NU,    U_NU,  TD(TD_QWERTY),
        KC_LALT,       KC_LGUI,      KC_LSFT,      KC_LCTL, U_NA,    U_NP, U_NP, U_NP, U_NU,    KC_MPRV,   KC_VOLD, KC_VOLU, KC_MNXT, U_NP,
        DB_TOGG,       KC_ALGR,   TD(TD_FUN), TD(TD_MEDIA), U_NA,    U_NP, U_NP, U_NP, OU_AUTO, U_NU,      U_NU,    U_NU,       U_NU,
        U_NP,          U_NA,            U_NA,         U_NA, U_NP,    U_NP, U_NP, U_NP, KC_MSTP, KC_MPLY,   KC_MUTE,           U_NP,
        U_NP, U_NP,    U_NP,                                              U_NP,                      U_NP,    U_NP,    U_NP, U_NP
    ),

    [NUM] = LAYOUT_60_ansi(  // Window management layer GREEN
        KC_LBRC,      KC_7,            KC_8,             KC_9,            KC_RBRC, U_NP, U_NP, U_NP, U_NA, TD(TD_BASE),TD(TD_GAME),  TD(TD_NAV), TD(TD_BOOT), U_NP,
        KC_SCLN,      KC_4,            KC_5,             KC_6,            KC_EQL,  U_NP, U_NP, U_NP, U_NA, KC_LCTL,        KC_LSFT,   KC_LGUI,   KC_LALT,     U_NP,
        KC_GRV,       KC_1,            KC_2,             KC_3,            KC_BSLS, U_NP, U_NP, U_NP, U_NA, TD(TD_NUM),  TD(TD_NAV),   KC_ALGR,     U_NA,
        U_NP,         KC_DOT,          KC_0,             KC_MINS,         U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,                  U_NP,
        U_NP, U_NP,    U_NP,                                              U_NP,                      U_NP,    U_NP,    U_NP, U_NP
    ),

    [SYM] = LAYOUT_60_ansi(  // Funky fun layer white
        KC_LCBR,      KC_AMPR,        KC_ASTR,           KC_LPRN,         KC_RCBR, U_NP, U_NP, U_NP, U_NA, TD(TD_BASE), TD(TD_GAME),  TD(TD_NAV), TD(TD_BOOT), U_NP,
        KC_COLN,      KC_DLR,         KC_PERC,           KC_CIRC,         KC_PLUS, U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,    KC_LGUI,     KC_LALT,  U_NP,
        KC_TILD,      KC_EXLM,        KC_AT,             KC_HASH,         KC_PIPE, U_NP, U_NP, U_NP, U_NA, TD(TD_NUM),  TD(TD_NAV),      KC_ALGR,      U_NA,
        U_NP,         KC_LPRN,        KC_RPRN,           KC_UNDS,         U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,          U_NP,
        U_NP, U_NP,    U_NP,                                              U_NP,                      U_NP,    U_NP,    U_NP, U_NP
    ),

    [FUN] = LAYOUT_60_ansi(  // Mouse and extra white
        KC_F12,       KC_F7,          KC_F8,             KC_F9,           KC_PSCR, U_NP, U_NP, U_NP, U_NA, TD(TD_BASE), TD(TD_GAME),  TD(TD_NAV), TD(TD_BOOT), U_NP,
        KC_F11,       KC_F4,          KC_F5,             KC_F6,           KC_SCRL, U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,     KC_LGUI,     KC_LALT, U_NP,
        KC_F10,       KC_F1,          KC_F2,             KC_F3,           KC_PAUS, U_NP, U_NP, U_NP, U_NA, TD(TD_FUN),  TD(TD_MEDIA),    KC_ALGR,           U_NA,
        U_NP,         KC_APP,         KC_SPC,            KC_TAB,          U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,        U_NA,                U_NP,
        U_NP, U_NP,    U_NP,                                              U_NP,                      U_NP,    U_NP,    U_NP, U_NP
    ),

    [GAME] = LAYOUT_60_ansi(  // Gaming Layer
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_BSPC, KC_RSFT,
        KC_CAPS, KC_X   , KC_C   , KC_V   , KC_B   , KC_Z   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                                KC_LALT, KC_F2, DF(BASE), KC_F3
    ),

    [QWERTY] = LAYOUT_60_ansi(
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
        KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                                KC_LALT, KC_F2, DF(BASE), KC_F3
    ),
};

// clang-format on
// A cheap pseudorandom generator.
// uint8_t myrand(void) {
//     static uint16_t state = 1;
//     state                 = UINT16_C(36563) * (state + timer_read());
//     return state >> 8;
// }

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

enum combo_events {
    CB_TNBSP_TFDEL_BASE,
};

const uint16_t PROGMEM thumbcombos_base_right[] = {LT(SYM, KC_ENT), LT(NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_G_r[] = {TN_BSP, TF_DEL, COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[] = {
    [CB_TNBSP_TFDEL_BASE] = COMBO_ACTION(thumbcombos_base_G_r),
    COMBO(thumbcombos_base_right, LT(FUN, KC_DEL)),
    COMBO(thumbcombos_base_left, LT(MEDIA, KC_ESC)),
    COMBO(thumbcombos_nav, KC_DEL),
    COMBO(thumbcombos_media, KC_MUTE),
    COMBO(thumbcombos_num, KC_DOT),
    COMBO(thumbcombos_sym, KC_LPRN),
    COMBO(thumbcombos_fun, KC_APP)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CB_TNBSP_TFDEL_BASE:
            if (pressed) {
                // Switch to the BASE layer
                default_layer_set((layer_state_t)1 << BASE);
            }
            break;
    }
}

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
// RGB Matrix Lighting (https://docs.qmk.fm/features/rgb_matrix)
///////////////////////////////////////////////////////////////////////////////
#if RGB_MATRIX_ENABLE
static void set_layer_color(uint8_t led_min, uint8_t led_max, uint8_t layer, uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index == NO_LED || index < led_min || index >= led_max) {
                continue;
            }
            uint16_t kc = keymap_key_to_keycode(layer, (keypos_t){col, row});
            if (kc > KC_TRNS) {
                rgb_matrix_set_color(index, red, green, blue);
            } else {
                rgb_matrix_set_color(index, RGB_OFF);
            }
        }
    }
}

static const uint8_t LAYER_RGB[LAYER_COUNT][3] = {
    {RGB_WHITE},  // BASE
    {RGB_BLUE},   // NAV
    {RGB_YELLOW}, // MOUSE
    {RGB_PURPLE}, // MEDIA
    {RGB_PINK},   // NUM
    {RGB_GREEN},  // SYM
    {RGB_RED},    // FUN
    {RGB_OFF},    // GAME
    {RGB_OFF},    // QWERTY
};
_Static_assert(LAYER_COUNT == (sizeof(LAYER_RGB) / sizeof(LAYER_RGB[0])), "Update LAYER_RGB when layers change.");

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = effective_layer_now();
    uint8_t idx   = (layer < LAYER_COUNT) ? layer : BASE;
    set_layer_color(led_min, led_max, layer, LAYER_RGB[idx][0], LAYER_RGB[idx][1], LAYER_RGB[idx][2]);
    return false;
}
#endif // RGB_MATRIX_ENABLE

#ifndef NO_DEBUG
// Log effective (momentary | default) layer in callbacks.
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = effective_layer_state(state);
    const char* name = (layer < LAYER_COUNT) ? LAYER_NAMES[layer] : "?";
    dprintf("Layer changed: %u (%s)\n", layer, name);
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    uint8_t layer = effective_layer_state(state);
    const char* name = (layer < LAYER_COUNT) ? LAYER_NAMES[layer] : "?";
    dprintf("Default layer changed: %u (%s)\n", layer, name);
    return state;
}
#endif // NO_DEBUG

// clang-format off

///////////////////////////////////////////////////////////////////////////////
// User functions
///////////////////////////////////////////////////////////////////////////////

// clang-format on

void keyboard_post_init_user(void) {
#ifndef NO_DEBUG
    debug_enable = true;
    debug_keyboard = true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
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
    }

    return true;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
    [TD_BASE] = ACTION_TAP_DANCE_FN(u_td_fn_U_BASE),
    [TD_NUM] = ACTION_TAP_DANCE_FN(u_td_fn_U_NUM),
    [TD_MOUSE] = ACTION_TAP_DANCE_FN(u_td_fn_U_MOUSE),
    [TD_MEDIA] = ACTION_TAP_DANCE_FN(u_td_fn_U_MEDIA),
    [TD_SYM] = ACTION_TAP_DANCE_FN(u_td_fn_U_SYM),
    [TD_FUN] = ACTION_TAP_DANCE_FN(u_td_fn_U_FUN),
    [TD_GAME] = ACTION_TAP_DANCE_FN(u_td_fn_U_GAME),
    [TD_NAV] = ACTION_TAP_DANCE_FN(u_td_fn_U_NAV),
    [TD_QWERTY] = ACTION_TAP_DANCE_FN(u_td_fn_U_QWERTY),
};
