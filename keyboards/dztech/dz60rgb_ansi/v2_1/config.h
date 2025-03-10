/* Copyright 2021 QMK
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

#pragma once

// #define NO_DEBUG

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

#define IS31FL3733_I2C_ADDRESS_1 IS31FL3733_I2C_ADDRESS_GND_GND

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define PERMISSIVE_HOLD

// Don't apply custom shift keys with mods other than Shift.
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT

// Only apply custom shift keys on layers 0 and 4.
#define CUSTOM_SHIFT_KEYS_LAYER_MASK (1 << 0) | (1 << 4)

#define QUICK_TAP_TERM 0

#define SELECT_WORD_TIMEOUT 2000 // When idle, clear state after 2 seconds.
#define LAYER_LOCK_IDLE_TIMEOUT 6000

// Define speed curve for Orbital Mouse.
#define ORBITAL_MOUSE_SPEED_CURVE {24, 24, 24, 32, 62, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72}
//     |               |               |               |           |
// t = 0.000           1.024           2.048           3.072       3.840 s

// Matrix positions of the left home row keys.
#define LEFT_HOME_ROW 2
#define LEFT_HOME_PINKY_COL 1
#define LEFT_HOME_RING_COL 2
#define LEFT_HOME_MIDDLE_COL 3
#define LEFT_HOME_INDEX_COL 4

// #define PALETTEFX_ENABLE_ALL_EFFECTS
// #define PALETTEFX_ENABLE_ALL_PALETTES

// Enable just the Flow effects.
// #define PALETTEFX_GRADIENT_ENABLE
#define PALETTEFX_FLOW_ENABLE
// #define PALETTEFX_RIPPLE_ENABLE
// #define PALETTEFX_SPARKLE_ENABLE
// #define PALETTEFX_VORTEX_ENABLE
// #define PALETTEFX_REACTIVE_ENABLE

// Enable just the Afterburn palettes.
#define PALETTEFX_AFTERBURN_ENABLE
// #define PALETTEFX_AMBER_ENABLE
// #define PALETTEFX_BADWOLF_ENABLE
// #define PALETTEFX_CARNIVAL_ENABLE
// #define PALETTEFX_CLASSIC_ENABLE
// #define PALETTEFX_DRACULA_ENABLE
// #define PALETTEFX_GROOVY_ENABLE
// #define PALETTEFX_NOTPINK_ENABLE
// #define PALETTEFX_PHOSPHOR_ENABLE
// #define PALETTEFX_POLARIZED_ENABLE
// #define PALETTEFX_ROSEGOLD_ENABLE
// #define PALETTEFX_SPORT_ENABLE
// #define PALETTEFX_SYNTHWAVE_ENABLE
// #define PALETTEFX_THERMAL_ENABLE
// #define PALETTEFX_VIRIDIS_ENABLE
// #define PALETTEFX_WATERMELON_ENABLE
