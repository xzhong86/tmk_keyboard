#include "keymap_common.h"

enum {
	LAYER_DEFAULT,
	//LAYER_CAPS_AS_LCTL,
	//LAYER_LGUI_AS_FN,
	LAYER_DIS_SPACEFN,
	LAYER_MAP_SPACEFN,
	LAYER_MAP_FN,
};

/*
 * SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Bspc |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn |
     * |-----------------------------------------------------------|
     * |    |Gui |Alt |      Space             |    |Alt |Gui |    |
     * `-----------------------------------------------------------'
     */
    [LAYER_DEFAULT] = KEYMAP_HHKB(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, NO,  \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,       \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,FN0,       \
        NO,  LGUI,LALT,          FN1,                     NO,  RALT,RGUI,NO),
#define FN_OpenFnMap      0
#define FN_SpaceFnMap     1


    [LAYER_MAP_SPACEFN] = KEYMAP_HHKB(
        TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS, TRNS, \
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,  PGUP,UP,  END, NO,  NO,  DEL, TRNS, \
        TRNS,NO,  NO,  NO,  NO,  NO,  HOME,LEFT,DOWN,RGHT,NO,  GRV,      NO,   \
        TRNS,NO,  DEL, NO,  NO,  SPC, PGDN,NO,  BSPC,DEL, NO,       TRNS,NO,   \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),

    // Overlay : Disable SpaceFn
    [LAYER_DIS_SPACEFN] = KEYMAP_HHKB(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS, \
        TRNS,TRNS,TRNS,          SPC,                     TRNS,TRNS,TRNS,TRNS),

    // Functions for Fn
    [LAYER_MAP_FN] = KEYMAP_HHKB(
        GRV, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, \
        NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,NO,   \
        FN3, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  GRV,      NO,   \
        CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,       CAPS,NO,   \
        NO,  FN5, NO,            FN2,                     NO,  NO,  NO,  NO),
#define FN_DisableSpaceFn  2

};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [FN_OpenFnMap]      = ACTION_LAYER_MOMENTARY(LAYER_MAP_FN),
    [FN_SpaceFnMap]     = ACTION_LAYER_TAP_KEY(LAYER_MAP_SPACEFN, KC_SPACE),
    [FN_DisableSpaceFn] = ACTION_LAYER_TOGGLE(LAYER_DIS_SPACEFN),
};

