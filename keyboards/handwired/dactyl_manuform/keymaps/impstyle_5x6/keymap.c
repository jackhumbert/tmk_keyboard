#include "dactyl_manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define _______ KC_TRNS



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


 // QUERTY LAYER
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
  //  ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  // TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,MINS ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  // LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
  // LCTL, Z  , X  , C  , V  , B  ,PLUS ,     MOUS , N  , M  ,COMM,DOT ,SLSH,BSLASH,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
  //                   LGUI,RASE,SPC ,         ENT ,LOWR,LALT
  //                  `----+----+----'        `----+----+----'

  [_QWERTY] = LAYOUT_5x6( 
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC, 
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS, 
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT, 
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH, 
                      KC_LBRC,KC_RBRC,                                                       KC_MINS, KC_EQL,                    
                                      SFT_ESC, CTL_BSPC,                      ALT_SPC, SFT_ENT,                                          
                                      KC_TAB,  KC_HOME,                       KC_END,  KC_DEL,                                            
                                      RAISE,   KC_GRV,                        KC_LGUI, LOWER 
  ),   
  
  // LOWER Layer
   //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
  // TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  //     ,    ,    ,    ,    ,LBRC,               RBRC, P7 , P8 , P9 ,    ,PLUS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  //     ,HOME,PGUP,PGDN,END,LPRN,               RPRN, P4 , P5 , P6 ,MINS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
  //     ,    ,    ,    ,    ,    ,    ,         ,    , P1 , P2 , P3 ,EQL ,UNDS ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
  //                       ,    ,DEL ,        BSPC ,    , P0
  //                  `----+----+----'        `----+----+----' 

  [_LOWER] = LAYOUT_5x6( 
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_PSCR,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______
),
  // RAISE LAYER
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
  // F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  //     ,    ,    ,    ,    ,LBRC,               RBRC,    ,NLCK,INS ,SLCK,MUTE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
  //     ,LEFT,UP  ,DOWN,RGHT,LPRN,               RPRN,MPRV,MPLY,MNXT,    ,VOLU,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
  //     ,    ,    ,    ,    ,    ,    ,      PLUS ,    ,    ,    ,    ,    ,VOLD,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
  //                       ,    ,    ,          EQL,    ,
  //                  `----+----+----'        `----+----+----'

  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                                               _______,_______,            KC_EQL ,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______,
                                               _______,_______,            _______,_______
  ),



};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
