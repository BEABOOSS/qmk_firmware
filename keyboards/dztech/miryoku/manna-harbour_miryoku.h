#pragma once

#include "miryoku_babel/miryoku_layer_list.h"

enum miryoku_layers {
    #define MIRYOKU_X(LAYER, STRING) U_##LAYER,
    MIRYOKU_LAYER_LIST
    #undef MIRYOKU_X
};

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)


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
#define HRM_WDOT LT(WIN, KC_DOT)

#define TME_ESC LT(MEDIA, KC_ESC)
#define TN_SPC LT(NAV, KC_SPC)
#define TMO_TAB LT(MOUSE, KC_TAB)

#define TS_ENT LT(SYM,KC_ENT)
#define TN_BSP LT(NUM,KC_BSPC)
#define TF_DEL LT(FUN,KC_DEL)
