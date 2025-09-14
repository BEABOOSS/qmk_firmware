#pragma once

#define MIRYOKU_BASE \
KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, U_NP, U_NP, U_NP, KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,      U_NP, \
HRM_A,   HRM_R,   HRM_S,   HRM_T,   KC_D, U_NP, U_NP, U_NP, KC_H,    HRM_N,   HRM_E,   HRM_I, HRM_O,    U_NP, \
KC_X,    KC_C,    KC_V,    KC_B,    KC_Z, U_NP, U_NP, U_NP, KC_K,    KC_M,    KC_COMM, HRM_WDOT,        KC_SLSH, \
U_NP,    TME_ESC, TN_SPC,  TMO_TAB, U_NP, U_NP, U_NP, U_NP, TS_ENT,  TN_BSP,  TF_DEL,                   U_NP, \
U_NP, U_NP,       U_NP,                         U_NP,                         U_NP,    U_NP,      U_NP, U_NP

#define MIRYOKU_TAP_BASE \
KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, U_NP, U_NP, U_NP, KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,  U_NP, \
KC_A,    KC_R,    KC_S,    KC_T,    KC_D, U_NP, U_NP, U_NP, KC_H,    KC_N,    KC_E,    KC_I,   KC_O,     U_NP, \
KC_X,    KC_C,    KC_V,    KC_B,    KC_Z, U_NP, U_NP, U_NP, KC_K,    KC_M,    KC_COMM, KC_DOT,           KC_SLSH, \
U_NP,    KC_ESC,  KC_SPC,  KC_TAB,  U_NP, U_NP, U_NP, U_NP, KC_ENT,  KC_BSP,  KC_DEL,                    U_NP, \
U_NP, U_NP,       U_NP,                         U_NP,                         U_NP,    U_NP,      U_NP,  U_NP

#define MIRYOKU_NAV \
TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), U_NA, U_NP, U_NP, U_NP, U_RDO,   U_PST,   U_CPY,   U_CUT,  U_UND,    U_NP, \
KC_LALT,       KC_LGUI,        KC_LSFT,          KC_LCTL,         U_NA, U_NP, U_NP, U_NP, CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,  U_NP, \
U_NA,          KC_ALGR,        TD(U_TD_U_NUM),   TD(U_TD_U_NAV),  U_NA, U_NP, U_NP, U_NP, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP,          KC_END, \
U_NP,          U_NA,           U_NA,             U_NA,            U_NP, U_NP, U_NP, U_NP, KC_ENT,  KC_BSPC, KC_DEL,                    U_NP, \
U_NP, U_NP,    U_NP,                                                    U_NP,                      U_NP,    U_NP,                U_NP, U_NP \

#define MIRYOKU_MOUSE \
TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), U_NA,    U_NP, U_NP, U_NP, U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   U_NP, \
KC_LALT,       KC_LGUI,        KC_LSFT,          KC_LCTL,         U_NA,    U_NP, U_NP, U_NP, U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NP, \
U_NA,          KC_ALGR,        TD(U_TD_U_SYM),   TD(U_TD_U_MOUSE),U_NA,    U_NP, U_NP, U_NP, U_NU,    KC_WH_L, KC_WH_D, KC_WH_U,          KC_WH_R, \
U_NP,          U_NA,           U_NA,             U_NA,            U_NP,    U_NP, U_NP, U_NP, KC_BTN2, KC_BTN1, TF_DEL ,                   U_NP, \
U_NP, U_NP,    U_NP,                                                       U_NP,                               U_NP,    U_NP,       U_NP, U_NP

#define MIRYOKU_MEDIA \
TD(U_TD_BOOT), TD(U_TD_U_TAP), TD(U_TD_U_EXTRA), TD(U_TD_U_BASE), U_NA,    U_NP, U_NP, U_NP, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, U_NP, \
KC_LALT,       KC_LGUI,        KC_LSFT,          KC_LCTL,         U_NA,    U_NP, U_NP, U_NP, U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NP, \
U_NA,          KC_ALGR,        TD(U_TD_U_FUN),   TD(U_TD_U_MEDIA),U_NA,    U_NP, U_NP, U_NP, OU_AUTO, U_NU,    U_NU,    U_NU,             U_NU, \
U_NP,          U_NA,           U_NA,             U_NA,            U_NP,    U_NP, U_NP, U_NP, KC_MSTP, KC_MPLY, KC_MUTE,                   U_NP, \
U_NP, U_NP,    U_NP,                                                       U_NP,                               U_NP,    U_NP,       U_NP, U_NP

#define MIRYOKU_NUM \
KC_LBRC,      KC_7,            KC_8,             KC_9,            KC_RBRC, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_BASE), TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT), U_NP, \
KC_SCLN,      KC_4,            KC_5,             KC_6,            KC_EQL,  U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,          KC_LGUI,        KC_LALT,       U_NP, \
KC_GRV,       KC_1,            KC_2,             KC_3,            KC_BSLS, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_NUM),  TD(U_TD_U_NAV),   KC_ALGR,                       U_NA, \
U_NP,         KC_DOT,          KC_0,             KC_MINS,         U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,                                            U_NP, \
U_NP, U_NP,   U_NP,                                                        U_NP,                                    U_NP,             U_NP,              U_NP,       U_NP

#define MIRYOKU_SYM \
KC_LCBR,      KC_AMPR,        KC_ASTR,           KC_LPRN,         KC_RCBR, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_BASE), TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT), U_NP, \
KC_COLN,      KC_DLR,         KC_PERC,           KC_CIRC,         KC_PLUS, U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,          KC_LGUI,        KC_LALT,       U_NP, \
KC_TILD,      KC_EXLM,        KC_AT,             KC_HASH,         KC_PIPE, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_NUM),  TD(U_TD_U_NAV),   KC_ALGR,                       U_NA, \
U_NP,         KC_LPRN,        KC_RPRN,           KC_UNDS,         U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,                                            U_NP, \
U_NP, U_NP,   U_NP,                                                        U_NP,                                    U_NP,             U_NP,                    U_NP, U_NP

#define MIRYOKU_FUN \
KC_F12,       KC_F7,          KC_F8,             KC_F9,           KC_PSCR, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_BASE), TD(U_TD_U_EXTRA), TD(U_TD_U_TAP), TD(U_TD_BOOT), U_NP, \
KC_F11,       KC_F4,          KC_F5,             KC_F6,           KC_SCRL, U_NP, U_NP, U_NP, U_NA, KC_LCTL,         KC_LSFT,          KC_LGUI,        KC_LALT,       U_NP, \
KC_F10,       KC_F1,          KC_F2,             KC_F3,           KC_PAUS, U_NP, U_NP, U_NP, U_NA, TD(U_TD_U_FUN),  TD(U_TD_U_MEDIA), KC_ALGR,                       U_NA, \
U_NP,         KC_APP,         KC_SPC,            KC_TAB,          U_NP,    U_NP, U_NP, U_NP, U_NA, U_NA,            U_NA,                                            U_NP, \
U_NP, U_NP,   U_NP,                                                        U_NP,                                    U_NP,             U_NP,                    U_NP, U_NP

#define MIRYOKU_GAME \
KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC, \
KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, \
KC_LSFT, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_BSPC, KC_RSFT, \
KC_CAPS, KC_X   , KC_C   , KC_V   , KC_B   , KC_Z   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT , \
KC_LCTL, KC_LGUI, KC_LALT,                         KC_SPC,                                KC_LALT, KC_F2, DF(BASE), KC_F3
