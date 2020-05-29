/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers
{
    _QWERTY, _COLEMAK, _DVORAK, _LOWER, _RAISE, _PLOVER, _ADJUST
};

enum planck_keycodes
{
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PLOVER,
    BACKLIT,
    EXT_PLV,
    BROWSER_FORWARD,
    BROWSER_BACKWARDS,
    JETBRAINS_RUN,
    JETBRAINS_DEBUG,
    JETBRAINS_TERMINAL,
    JETBRAINS_PROJECT,
    ALT_INSERT,
    JETBRAINS_REFORMAT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM

keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY]  =

LAYOUT_ortho_4x12(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(

7),

LOWER, KC_SPC, KC_SPC, RAISE, KC_RALT, KC_RGUI, KC_RSFT, KC_RCTL

),
[_COLEMAK] =

LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, KC_ESC, KC_A, KC_R,
    KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM,
    KC_DOT, KC_SLSH, KC_ENT, BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT,
    KC_DOWN, KC_UP, KC_RGHT

),
[_DVORAK]  =

LAYOUT_ortho_4x12(KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, KC_ESC, KC_A,
    KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH, KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M,
    KC_W, KC_V, KC_Z, KC_ENT, BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_LEFT,
    KC_DOWN, KC_UP, KC_RGHT

),
[_LOWER]   =

LAYOUT_ortho_4x12(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    ALT_INSERT, KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_NUHS),KC_HOME, KC_END, LSFT(KC_NUBS), KC_RSFT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, KC_VOLD, KC_VOLU, _______

),
[_RAISE]   =

LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_INSERT, KC_DEL, KC_F1, KC_F2,
    KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, _______, KC_VOLD, KC_VOLU, _______

),
[_PLOVER]  =

LAYOUT_ortho_4x12(KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_1, KC_NO, KC_Q, KC_W, KC_E, KC_R,
    KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
    KC_QUOT, TO(_QWERTY), KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_N, KC_M, KC_NO, KC_NO, KC_NO

),
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK,  DVORAK,  PLOVER,  _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
[7]        =

LAYOUT_ortho_4x12(
    LALT(KC_TAB), KC_NO, KC_NO, KC_NO, JETBRAINS_RUN, JETBRAINS_TERMINAL, KC_NO, BROWSER_BACKWARDS, KC_UP, BROWSER_FORWARD,
    JETBRAINS_PROJECT, KC_NO,
    KC_NO, KC_NO, KC_NO, JETBRAINS_DEBUG, JETBRAINS_REFORMAT, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_NO, LALT(KC_ENT),
    KC_LCTRL, KC_LGUI, KC_LALT, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, KC_RCTL

)};

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state)
{ return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            print("mode just switched to qwerty and this is a huge string\n");
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case COLEMAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
        }
        return false;
        break;
    case DVORAK:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_DVORAK);
        }
        return false;
        break;
    case BACKLIT:
        if (record->event.pressed) {
            register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
            backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
            writePinLow(E6);
#endif
        }
        else {
            unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
            writePinHigh(E6);
#endif
        }
        return false;
        break;
    case PLOVER:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            stop_all_notes();
            PLAY_SONG(plover_song);
#endif
            layer_off(_RAISE);
            layer_off(_LOWER);
            layer_off(_ADJUST);
            layer_on(_PLOVER);
            if (!eeconfig_is_enabled()) {
                eeconfig_init();
            }
            keymap_config.raw = eeconfig_read_keymap();
            keymap_config.nkro = 1;
            eeconfig_update_keymap(keymap_config.raw);
        }
        return false;
        break;
    case EXT_PLV:
        if (record->event.pressed) {
#ifdef AUDIO_ENABLE
            PLAY_SONG(plover_gb_song);
#endif
            layer_off(_PLOVER);
        }
        return false;
        break;
    case BROWSER_FORWARD:
        if (record->event.pressed) {
            register_code(KC_LCTRL);
            register_code(KC_TAB);
        }
        else {
            unregister_code(KC_LCTRL);
            unregister_code(KC_TAB);
        }

        return false;
        break;
    case BROWSER_BACKWARDS:
        if (record->event.pressed) {
            register_code(KC_LCTRL);
            register_code(KC_LSHIFT);
            register_code(KC_TAB);
        }
        else {
            unregister_code(KC_LCTRL);
            unregister_code(KC_TAB);
            unregister_code(KC_LSHIFT);
        }

        return false;
        break;
    case JETBRAINS_DEBUG:
        if (record->event.pressed) {
            register_code(KC_LSHIFT);
            register_code(KC_F9);
        }
        else {
            unregister_code(KC_LSHIFT);
            unregister_code(KC_F9);
        }

        return false;
        break;
    case JETBRAINS_RUN:
        if (record->event.pressed) {
            register_code(KC_LSHIFT);
            register_code(KC_F10);
        }
        else {
            unregister_code(KC_LSHIFT);
            unregister_code(KC_F10);
        }

        return false;
        break;

    case JETBRAINS_TERMINAL:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F12);
        }
        else {
            unregister_code(KC_LALT);
            unregister_code(KC_F12);
        }

        return false;
        break;

    case JETBRAINS_PROJECT:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_1);
        }
        else {
            unregister_code(KC_LALT);
            unregister_code(KC_1);
        }

        return false;
        break;

    case ALT_INSERT:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_INSERT);
        }
        else {
            unregister_code(KC_LALT);
            unregister_code(KC_INSERT);
        }

        return false;
        break;

    case JETBRAINS_REFORMAT:
        if (record->event.pressed){
            register_code(KC_LALT);
            register_code(KC_LCTL);
            register_code(KC_L);
        } else {
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
            unregister_code(KC_L);
        }
    }
    return true;
}

bool muse_mode = false;

uint8_t last_muse_note = 0;

uint16_t muse_counter = 0;

uint8_t muse_offset = 70;

uint16_t muse_tempo = 50;

void encoder_update(bool clockwise)
{
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            }
            else {
                muse_offset--;
            }
        }
        else {
            if (clockwise) {
                muse_tempo += 1;
            }
            else {
                muse_tempo -= 1;
            }
        }
    }
    else {
        if (clockwise) {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_DOWN);
#else
            tap_code(KC_PGDN);
#endif
        }
        else {
#ifdef MOUSEKEY_ENABLE
            tap_code(KC_MS_WH_UP);
#else
            tap_code(KC_PGUP);
#endif
        }
    }
}

void dip_switch_update_user(uint8_t index, bool active)
{
    switch (index) {
    case 0: {
#ifdef AUDIO_ENABLE
        static bool play_sound = false;
#endif
        if (active) {
#ifdef AUDIO_ENABLE
            if (play_sound) {
                PLAY_SONG(plover_song);
            }
#endif
            layer_on(_ADJUST);
        }
        else {
#ifdef AUDIO_ENABLE
            if (play_sound) {
                PLAY_SONG(plover_gb_song);
            }
#endif
            layer_off(_ADJUST);
        }
#ifdef AUDIO_ENABLE
        play_sound = true;
#endif
        break;
    }
    case 1:
        if (active) {
            muse_mode = true;
        }
        else {
            muse_mode = false;
        }
    }
}

void matrix_scan_user(void)
{
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode)
{
    switch (keycode) {
    case RAISE:
    case LOWER:return false;
    default:return true;
    }
}
