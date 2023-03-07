#include QMK_KEYBOARD_H

#include "polyatom.h"
#include "print.h"
#include "base/disp_array.h"
#include "base/shift_reg.h"
#include "fonts/gfx_used_fonts.h"

#include "quantum/quantum_keycodes.h"

static int32_t last_update;

void update_performed(void) {
    last_update = timer_read32();
}

enum kb_layers { _LAYER0 = 0, NUM_LAYERS = 1 };


static bool rotarySwitchPressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_COLS][MATRIX_ROWS] = {
    [_LAYER0] = LAYOUT(
        KC_Q, KC_W, KC_E,
        KC_A, KC_S, KC_D,
        KC_Z, KC_C, KC_X
    )
};

led_config_t g_led_config = {{// Key Matrix to LED Index
                              {0}
                             },
                             {
                                 // LED Index to Physical Position
                                 {0, 0}
                             },
                             {
                                 // LED Index to Flag
                                 4
                             }};

void process_layer_switch_user(uint16_t new_layer);
/*
void matrix_init_user(void) {
    setPinInputHigh(ENCODERS_SWITCH);
#ifdef OLED_ENABLE
    OLED_INIT;
    #endif
}
*/
/*
void matrix_scan_user(void) {
    if (readPin(ENCODERS_SWITCH)==0) {
        if(rotarySwitchPressed) {
            register_code(KC_CAPS_LOCK);
            unregister_code(KC_CAPS_LOCK);
        }
        rotarySwitchPressed = false;
    } else if(!rotarySwitchPressed) {
        rotarySwitchPressed = true;
    }
}
*/


/*struct keycap_text {
    const char* lower;
    const char* upper;
    const char* num_lock;
};*/

struct diplay_info {
    uint8_t bitmask[NUM_SHIFT_REGISTERS];
};

#define BITMASK1(x) .bitmask = {~0, ~0, ~0, ~0, ~(1<<x)}
#define BITMASK2(x) .bitmask = {~0, ~0, ~0, ~(1<<x), ~0}
#define BITMASK3(x) .bitmask = {~0, ~0, ~(1<<x), ~0, ~0}
#define BITMASK4(x) .bitmask = {~0, ~(1<<x), ~0, ~0, ~0}
#define BITMASK5(x) .bitmask = {~(1<<x), ~0, ~0, ~0, ~0}

struct diplay_info key_display[] = {
        {BITMASK1(0)}, {BITMASK1(1)}, {BITMASK1(2)}, {BITMASK1(3)},
        {BITMASK2(0)}, {BITMASK2(1)}, {BITMASK2(2)}, {BITMASK2(3)},
        {BITMASK3(0)}, {BITMASK3(1)}, {BITMASK3(2)}, {BITMASK3(3)},
        {BITMASK4(0)}, {BITMASK4(1)}, {BITMASK4(2)}, {BITMASK4(3)},
        {BITMASK5(0)}, {BITMASK5(1)}, {BITMASK5(2)}, {BITMASK5(3)}
    };


const uint16_t* keycode_to_disp_text(uint16_t keycode, led_t state) {
    bool shift = ((get_mods() & MOD_MASK_SHIFT)!=0) || state.caps_lock;
    switch (keycode) {
        case KC_0:
            return shift ? u")" : u"0";
        case KC_1:
            return shift ? u"!" : u"1";
        case KC_2:
            return shift ? u"@" : u"2";
        case KC_3:
            return shift ? u"#" : u"3";
        case KC_4:
            return shift ? u"$" : u"4";
        case KC_5:
            return shift ? u"%" : u"5";
        case KC_6:
            return shift ? u"^" : u"6";
        case KC_7:
            return shift ? u"&" : u"7";
        case KC_8:
            return shift ? u"*" : u"8";
        case KC_9:
            return shift ? u"(" : u"9";
        case KC_EQUAL:
            return shift ? u"+" : u"=";
        case KC_MINUS:
            return shift ? u"_" : u"-";
        case KC_GRAVE:
            return shift ? u"~" : u"`";
        case KC_COMMA:
            return shift ? u"<" : u",";
        case KC_DOT:
            return shift ? u">" : u",";
        case KC_A:
            return shift ? u"A" : u"a";
        case KC_B:
            return shift ? u"B" : u"b";
        case KC_C:
            return shift ? u"C" : u"c";
        case KC_D:
            return shift ? u"D" : u"d";
        case KC_E:
            return shift ? u"E" : u"e";
        case KC_F:
            return shift ? u"F" : u"f";
        case KC_G:
            return shift ? u"G" : u"g";
        case KC_H:
            return shift ? u"H" : u"h";
        case KC_I:
            return shift ? u"I" : u"i";
        case KC_J:
            return shift ? u"J" : u"j";
        case KC_K:
            return shift ? u"K" : u"k";
        case KC_L:
            return shift ? u"L" : u"l";
        case KC_M:
            return shift ? u"M" : u"m";
        case KC_N:
            return shift ? u"N" : u"n";
        case KC_O:
            return shift ? u"O" : u"o";
        case KC_P:
            return shift ? u"P" : u"p";
        case KC_Q:
            return shift ? u"Q" : u"q";
        case KC_R:
            return shift ? u"R" : u"r";
        case KC_S:
            return shift ? u"S" : u"s";
        case KC_T:
            return shift ? u"T" : u"t";
        case KC_U:
            return shift ? u"U" : u"u";
        case KC_V:
            return shift ? u"V" : u"v";
        case KC_W:
            return shift ? u"W" : u"w";
        case KC_X:
            return shift ? u"X" : u"x";
        case KC_Y:
            return shift ? u"Y" : u"y";
        case KC_Z:
            return shift ? u"Z" : u"z";
        case KC_KP_SLASH:
            return u"/";
        case KC_KP_ASTERISK:
            return u"*";
        case KC_KP_MINUS:
            return u"-";
        case KC_KP_7:
            return !state.num_lock ? u"Home" : u"7";
        case KC_KP_9:
            return !state.num_lock ? u"PgUp" : u"9";
        case KC_KP_PLUS:
            return u"+";
        case KC_KP_5:
            return !state.num_lock ? u"" : u"5";
        case KC_KP_EQUAL:
            return u"=";
        case KC_KP_1:
            return !state.num_lock ? u"End" : u"1";
        case KC_KP_3:
            return !state.num_lock ? u"PgDn" : u"3";
        case KC_CALCULATOR:
            return u"Calc";
        case KC_KP_0:
            return !state.num_lock ? u"Ins" : u"0";
        case KC_KP_DOT:
            return !state.num_lock ? u"Del" : u".";
        case KC_KP_ENTER:
            return u"Enter";
        case QK_BOOTLOADER:
            return u"BootL";
        case QK_DEBUG_TOGGLE:
            return u"Debug";
        case QK_CLEAR_EEPROM:
            return u"Clr EE";
        case KC_MEDIA_STOP:
            return u"Stop";
        case KC_MS_ACCEL0:
            return u">>";
        case KC_MS_ACCEL1:
            return u">>>";
        case KC_MS_ACCEL2:
            return u">>>>";
        case KC_AUDIO_MUTE:
            return u"Mute";
        case KC_PRINT_SCREEN:
            return u"PrtScn";
        case KC_SCROLL_LOCK:
            return u"SclLck";
        case KC_PAUSE:
            return u"Pause";
        case KC_INSERT:
            return u"Insert";
        case KC_HOME:
            return u"Home";
        case KC_PAGE_UP:
            return u"PgUp";
        case KC_PAGE_DOWN:
            return u"PgDn";
        case KC_BACKSLASH:
            return shift ? u"|" : u"\\";
        case KC_DELETE:
            return u"Delete";
        case KC_END:
            return u"End";
        case KC_SLASH:
            return shift ? u"?" : u"/";
        case KC_ESC:
            return u"ESC";
        case KC_F1:
            return u"F1";
        case KC_F2:
            return u"F2";
        case KC_F3:
            return u"F3";
        case KC_F4:
            return u"F4";
        case KC_F5:
            return u"F5";
        case KC_F6:
            return u"F6";
        case KC_F7:
            return u"F7";
        case KC_F8:
            return u"F8";
        case KC_F9:
            return u"F9";
        case KC_F10:
            return u"F10";
        case KC_F11:
            return u"F11";
        case KC_F12:
            return u"F12";
        case KC_LEFT_CTRL:
            return u"L Ctrl";
        case KC_LEFT_ALT:
            return u"L Alt";
        default:
            break;
    }
    return u"[?]";
}

//const GFXfont* ALL_FONTS [] = {&AsciiFont, &IconsFont, &HangulJamoFont};
//const uint8_t NUM_FONTS = sizeof(ALL_FONTS) / sizeof(GFXfont*);


void process_layer_switch_user(uint16_t new_layer) {
    layer_move(new_layer);
    led_t state = host_keyboard_led_state();

    // keypos_t key;
    for (uint8_t r = 0; r < MATRIX_ROWS; ++r) {
        for (uint8_t c = 0; c < MATRIX_COLS; ++c) {
            //key.col           = c;
            //key.row           = r;
            uint16_t keycode  = keymaps[new_layer][r][c];
            uint8_t  disp_idx = LAYOUT_TO_INDEX(r, c);

            if (disp_idx != 255) {
                const uint16_t* text = keycode_to_disp_text(keycode, state);
                sr_shift_out_buffer_latch(key_display[disp_idx].bitmask, sizeof(key_display->bitmask));
                kdisp_set_buffer(0x00);
 //               kdisp_write_gfx_text(ALL_FONTS, NUM_FONTS, 28, 18, text);
                kdisp_send_buffer();
            }
        }
    }
}

void post_process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint8_t disp_idx = LAYOUT_TO_INDEX(record->event.key.row, record->event.key.col);
    const uint8_t* bitmask = key_display[disp_idx].bitmask;
    sr_shift_out_buffer_latch(bitmask, sizeof(key_display->bitmask));
    if (record->event.pressed) {
        set_last_key(keycode);
        if (disp_idx != 255) {
            kdisp_invert(true);
        }
    } else {
        if (disp_idx != 255) {
            kdisp_invert(false);
        }
    }

    if(!record->event.pressed) {
        switch(keycode) {
            default:
                break;
        }
    } else {
        switch (keycode)
        {
        case KC_RIGHT_SHIFT:
//            force_layer_switch();
            break;
        default:
            break;
        }
    }


   update_performed();
};

