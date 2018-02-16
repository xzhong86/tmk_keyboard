#include "keymap_common.h"

enum {
	LAYER_DEFAULT,
	LAYER_CAPS_AS_LCTL,
	LAYER_LGUI_AS_FN,
	LAYER_EN_SPACEFN,
	LAYER_MAP_SPACEFN,
	LAYER_MAP_FN,
};

/*
 * SpaceFN
 * http://geekhack.org/index.php?topic=51069.0
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
     * |-----------------------------------------------------------|
     * |Caps  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
     * |-----------------------------------------------------------|
     * |Ctrl|Gui |Alt |      Space             |Alt |Gui |App |Ctrl|
     * `-----------------------------------------------------------'
     */
    [LAYER_DEFAULT] = KEYMAP_ANSI(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT, \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT, \
        LCTL,LGUI,LALT,          SPC,                     FN0, RALT,RGUI,RCTL),
#define FN_OpenFnMap     0

    /* Overlay : SpaceFN
     * ,-----------------------------------------------------------.
     * |`  | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Delete |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |Hom|Up |End|Psc|Slk|Pau|Ins  |
     * |-----------------------------------------------------------|
     * |      |   |   |   |   |   |PgU|Lef|Dow|Rig|   |   |        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |Spc|PgD|`  |~  |   |   |          |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    [LAYER_MAP_SPACEFN] = KEYMAP_ANSI(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,  \
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,  HOME,UP,  END, NO,  NO,  NO,  INS,  \
        TRNS,NO,  NO,  NO,  NO,  NO,  PGUP,LEFT,DOWN,RGHT,NO,  NO,       NO,   \
        TRNS,NO,  NO,  NO,  NO,  SPC, PGDN,NO,  BSPC,DEL, NO,            TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),

    // Overlay : Enable SpaceFn
    [LAYER_EN_SPACEFN] = KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          FN1,                     TRNS,TRNS,TRNS,TRNS),
#define FN_SpaceFnMap     1

    // Functions for Fn
    [LAYER_MAP_FN] = KEYMAP_ANSI(
        NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,   \
        NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,NO,   \
        FN3, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  GRV, NO,       NO,   \
        CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,            CAPS, \
        NO,  FN5, NO,            FN2,                     NO,  NO,  NO,  NO),
#define FN_EnableSpaceFn  2
#define FN_CapsAsLctl     3
#define FN_LGuiAsFn       5

    // Overlay : Use Crtl instead of CapsLock
    [LAYER_CAPS_AS_LCTL] = KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),

    // Overlay : Use LGUI as Space Fn
    [LAYER_LGUI_AS_FN] = KEYMAP_ANSI(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS, \
        TRNS,FN4, TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
#define FN_OpenSpcFnMap  4

};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
    [FN_OpenFnMap]      = ACTION_LAYER_MOMENTARY(LAYER_MAP_FN),
    [FN_SpaceFnMap]     = ACTION_LAYER_TAP_KEY(LAYER_MAP_SPACEFN, KC_SPACE),
    [FN_EnableSpaceFn]  = ACTION_LAYER_TOGGLE(LAYER_EN_SPACEFN),
    [FN_CapsAsLctl]     = ACTION_LAYER_TOGGLE(LAYER_CAPS_AS_LCTL),
    [FN_LGuiAsFn]       = ACTION_LAYER_TOGGLE(LAYER_LGUI_AS_FN),
    [FN_OpenSpcFnMap]   = ACTION_LAYER_MOMENTARY(LAYER_MAP_SPACEFN),
};

