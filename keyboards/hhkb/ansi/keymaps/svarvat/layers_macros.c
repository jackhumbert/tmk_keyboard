 bool isLeftThumbEMoStarted = false;
 bool isLeftThumbDMoStarted = false;
 //bool isDeadKeyCircStarted = false;
 //bool isDeadKeyTremaStarted = false;
 bool mouseLeft = false;
 bool mouseRight = false;
 bool mouseUp = false;
 bool mouseDown = false;
 bool isMouseX1Started = false;
 bool isMouseX2Started = false;
 bool isMouseX4Started = false;
 bool scrollLeft = false;
 bool scrollRight = false;
 bool scrollUp = false;
 bool scrollDown = false;
 bool isScrollX1Started = false;
 bool isScrollX2Started = false;
 bool isScrollX4Started = false;
 bool editModeLthumbOslStarted = false;
 bool isLpinkyLayerMouseStarted = false;

 bool processKeycodeIfLBase(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_LTHUMB:
             if (record->event.pressed) {
                 layer_on(LA_LTHUMB);
                 register_mods(MOD_MASK_CTRL);
             }
             return false;
         case MA_LPINKY:
             if (record->event.pressed) {layer_on(LA_LPINKY);}
             return false;
         case MA_MOUSE:
             if (record->event.pressed) {
                 if (mod_state & MOD_MASK_CSA) {
                     reset_keyboard();
                 } else {
 //                    set_auto_mouse_enable(true);
                     layer_on(LA_MOUSE);
                     isMouseX1Started = true;
                     isScrollX1Started = true;
                 }
             }
             return false;
         case MA_CAPSLOCK:
             if (record->event.pressed) {
                 layer_on(LA_CAPSLOCK);
             }
             return false;
         case KC_SLSH:
             if (record->event.pressed) {
                 if ((mod_state & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
                     unregister_code16(KC_LSFT);
                     tap_code16(ALGR(KC_8));
                     register_code16(KC_LSFT);
                     return false;
                 }
             }
             return true;
     }
     return true;
 }
 bool processKeycodeIfLMouse(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_MOUSE:
             if (record->event.pressed) {
 //                set_auto_mouse_enable(false);
                 layer_off(LA_MOUSE);
                 isMouseX1Started = false;
                 isScrollX1Started = false;
             }
             return false;
         case MA_MS_BTN1_UNREG:
             if (record->event.pressed) {
                 if (isLpinkyLayerMouseStarted) {isMouseX2Started = true;}
                 else {unregister_code16(KC_MS_BTN1);}
             } else {
                 if (isLpinkyLayerMouseStarted) {isMouseX2Started = false;}
             }
             return false;
         case MA_MS_BTN1_REG:
             if (record->event.pressed) {
                 if (isLpinkyLayerMouseStarted) {isMouseX4Started = true;}
                 else {register_code16(KC_MS_BTN1);}
             } else {
                 if (isLpinkyLayerMouseStarted) {isMouseX4Started = false;}
             }
             return false;
         case MA_MS_BTN1_TAP:
             if (record->event.pressed) {
                 tap_code16(KC_MS_BTN1);
             }
             return false;
         case MA_LTHUMBMS:
             if (record->event.pressed) {
                 isLpinkyLayerMouseStarted = true;
             } else {
                 isLpinkyLayerMouseStarted = false;
             }
             return false;
         case MA_MS_WH_DOWN:
             if (record->event.pressed) {
                 scrollDown = true;
             } else {
                 scrollDown = false;
             }
             return false;
         case MA_MS_WH_UP:
             if (record->event.pressed) {
                 scrollUp = true;
             } else {
                 scrollUp = false;
             }
             return false;
         case MA_DOWN:
             if (record->event.pressed) {
                 mouseDown = true;
             } else {
                 mouseDown = false;
             }
             return false;
         case MA_UP:
             if (record->event.pressed) {
                 mouseUp = true;
             } else {
                 mouseUp = false;
             }
             return false;
         case MA_LEFT:
             if (record->event.pressed) {
                 mouseLeft = true;
             } else {
                 mouseLeft = false;
             }
             return false;
         case MA_RIGHT:
             if (record->event.pressed) {
                 mouseRight = true;
             } else {
                 mouseRight = false;
             }
             return false;
     }

     return true;
 }
 bool processKeycodeIfLCapslock(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_CAPSLOCK:
             if (record->event.pressed) {
                 layer_off(LA_CAPSLOCK);
             }
             return false;
         case MA_CIRC:
 //            if (record->event.pressed) {
 //                if (!(isDeadKeyTremaStarted) && mod_state && MOD_MASK_SHIFT) {isDeadKeyTremaStarted=true;}
 //                else if (!isDeadKeyCircStarted) {isDeadKeyCircStarted=true;}
 //            }
             return false;
 //        case MA_CAPSE:
 //            if (record->event.pressed) {
 //                if (isDeadKeyTremaStarted) {
 //                    tap_code16(X(ETREMA));
 //                    isDeadKeyTremaStarted=false;
 //                } else if (isDeadKeyCircStarted) {
 //                    register_code16(KC_RALT);
 //                    tap_code16(S(X(ECIRC)));
 //                    unregister_code16(KC_RALT);
 //                    isDeadKeyCircStarted=false;
 //                } else {
 //                    register_code16(KC_RALT);
 //                    tap_code16(X(ECIRC));
 ////                    tap_code16(S(KC_E));
 //                    unregister_code16(KC_RALT);
 //                }
 //            }
 //            return false;
 //        case MA_CAPSA:
 //            if (record->event.pressed) {
 //                if (isDeadKeyTremaStarted) {
 //                    tap_code16(X(ATREMA));
 //                    isDeadKeyTremaStarted=false;
 //                }
 //                else if (isDeadKeyCircStarted) {
 //                    tap_code16(X(ACIRC));
 //                    isDeadKeyCircStarted=false;
 //                }
 //                else {tap_code16(S(KC_Q));}
 //            }
 //            return false;
 //        case MA_CAPSI:
 //            if (record->event.pressed) {
 //                if (isDeadKeyTremaStarted) {
 //                    tap_code16(X(ITREMA));
 //                    isDeadKeyTremaStarted=false;
 //                }
 //                else if (isDeadKeyCircStarted) {
 //                    tap_code16(X(ICIRC));
 //                    isDeadKeyCircStarted=false;
 //                }
 //                else {tap_code16(S(KC_I));}
 //            }
 //            return false;
 //        case MA_CAPSU:
 //            if (record->event.pressed) {
 //                if (isDeadKeyTremaStarted) {
 //                    tap_code16(X(UTREMA));
 //                    isDeadKeyTremaStarted=false;
 //                }
 //                else if (isDeadKeyCircStarted) {
 //                    tap_code16(X(UCIRC));
 //                    isDeadKeyCircStarted=false;
 //                }
 //                else {tap_code16(S(KC_U));}
 //            }
 //            return false;
     }
 //    if (isDeadKeyCircStarted) {isDeadKeyCircStarted=false;}
 //    if (isDeadKeyTremaStarted) {isDeadKeyTremaStarted=false;}
     return processKeycodeIfLMouse(keycode, record);
 }
 bool processKeycodeIfLPinky(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_LTHUMB:
             if (record->event.pressed) {
                 register_code16(KC_LCTL);
                 layer_on(LA_LTHUMB);
                 layer_off(LA_LPINKY);
             }
             return false;
         case MA_LPINKY:
             if (!(record->event.pressed)) {
                 layer_off(LA_LPINKY);
             }
             return false;
         case KC_UP:
             if (mod_state & MOD_MASK_CTRL) {
                 if (record->event.pressed) {
                     unregister_code16(KC_LCTL);
                     tap_code16(KC_UP);
                     register_code16(KC_LCTL);
                     return false;
                 }
             }
             return true;
         case KC_DOWN:
             if (mod_state & MOD_MASK_CTRL) {
                 if (record->event.pressed) {
                     unregister_code16(KC_LCTL);
                     tap_code16(KC_DOWN);
                     register_code16(KC_LCTL);
                     return false;
                 }
             }
             return true;
         case MA_DELLINE:
             if (record->event.pressed) {
                 tap_code16(KC_HOME);
                 tap_code16(KC_HOME);
                 register_code16(KC_LSFT);
                 tap_code16(KC_END);
                 tap_code16(KC_RGHT);
                 unregister_code16(KC_LSFT);
                 tap_code16(KC_DEL);
             }
             return false;
         case MA_DOUBLEARROW:
             if (record->event.pressed) {
                 tap_code16(FR_EQL);
                 tap_code16(FR_RABK);
                 tap_code16(KC_SPC);
             }
             return false;
         case MA_SIMPLEARROW:
             if (record->event.pressed) {
                 tap_code16(FR_MINS);
                 tap_code16(FR_RABK);
                 tap_code16(KC_SPC);
             }
             return false;
         case KC_ESC:
             if (IS_LAYER_ON(LA_LTHUMBEOSL) || IS_LAYER_ON(LA_LTHUMBDOSL)) {
                 if (!(record->event.pressed)) {
                     layer_off(LA_LTHUMB);
                     layer_off(LA_LTHUMBEOSL);
                     layer_off(LA_LTHUMBDOSL);
                 }
                 return false;
             }
             return true;
         case MA_CTLALTDEL:
             if (record->event.pressed) {
                 tap_code16(C(A(KC_DEL)));
             }
             return true;
     }
     return true;
 }
 bool processKeycodeIfRThumb(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_BACKTICK:
             if (record->event.pressed) {
                 tap_code16(FR_GRV);
                 // timer = timer_read();
                 tap_code16(KC_SPC);
             }
             return false;
         case MA_TILD:
             if (record->event.pressed) {
                 tap_code16(FR_TILD);
                 tap_code16(KC_SPC);
             }
             return false;
     }
     return true;
 }
 bool processKeycodeIfLThumb(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case KC_TAB:
             return true;
     }
     unregister_mods(MOD_MASK_CTRL);
     switch (keycode) {
         case MA_LTHUMBQ:
             if (record->event.pressed) {
                 if (IS_LAYER_ON(LA_MOUSE)) {isMouseX2Started = true;}
                 else {layer_on(LA_LTHUMBQ);}
             } else {
                 if (IS_LAYER_ON(LA_MOUSE)) {isMouseX2Started = false;}
                 else {layer_off(LA_LTHUMBQ);}
             }
             return false;
         case MA_LTHUMBW:
             if (record->event.pressed) {
                 if (IS_LAYER_ON(LA_MOUSE)) {isMouseX4Started = true;}
                 else {layer_on(LA_LTHUMBW);}
             } else {
                 if (IS_LAYER_ON(LA_MOUSE)) {isMouseX4Started = false;}
                 else {layer_off(LA_LTHUMBW);}
             }
             return false;
         case MA_LPINKY:
             if (!(record->event.pressed)) {
                 unregister_code16(KC_LCTL);
             }
             return false;
         case MA_LTHUMBE:
             if (record->event.pressed) {
                 layer_on(LA_LTHUMBEMO);
             }
             return false;
         case MA_LTHUMBD:
             if (record->event.pressed) {
                 layer_on(LA_LTHUMBDMO);
             }
             return false;
         case MA_LTHUMB1:
             if (record->event.pressed) {
                 layer_on(LA_LTHUMB1MO);
             }
             return false;
         case MA_LTHUMB2:
             if (record->event.pressed) {
                 layer_on(LA_LTHUMB2MO);
             }
             return false;
         case MA_LTHUMB3:
             if (record->event.pressed) {
                 layer_on(LA_LTHUMB3MO);
             }
             return false;
         case MA_0:
             if (record->event.pressed) {
                 tap_code16(FR_0);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_1:
             if (record->event.pressed) {
                 tap_code16(FR_1);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_2:
             if (record->event.pressed) {
                 tap_code16(FR_2);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_3:
             if (record->event.pressed) {
                 tap_code16(FR_3);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_4:
             if (record->event.pressed) {
                 tap_code16(FR_4);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_5:
             if (record->event.pressed) {
                 tap_code16(FR_5);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_6:
             if (record->event.pressed) {
                 tap_code16(FR_6);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_7:
             if (record->event.pressed) {
                 tap_code16(FR_7);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_8:
             if (record->event.pressed) {
                 tap_code16(FR_8);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_9:
             if (record->event.pressed) {
                 tap_code16(FR_9);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_EQL:
             if (record->event.pressed) {
                 tap_code16(FR_EQL);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_ASTR:
             if (record->event.pressed) {
                 tap_code16(FR_ASTR);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_DOT:
             if (record->event.pressed) {
                 tap_code16(FR_DOT);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_MINS:
             if (record->event.pressed) {
                 tap_code16(FR_MINS);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_PLUS:
             if (record->event.pressed) {
                 tap_code16(FR_PLUS);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_ENT:
             if (record->event.pressed) {
                 tap_code16(KC_ENT);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_SLSH:
             if (record->event.pressed) {
                 tap_code16(FR_SLSH);
             }
             register_mods(MOD_MASK_CTRL);
             return false;
         case MA_CAPSLOCK:
             if (record->event.pressed) {
                 if (IS_LAYER_ON(LA_CAPSLOCK)) {
                     layer_off(LA_CAPSLOCK);
                 } else {
                     layer_on(LA_CAPSLOCK);
                 }
             }
             register_mods(MOD_MASK_CTRL);
             return false;
     }
     register_mods(MOD_MASK_CTRL);
     return true;
 }
 bool processKeycodeIfLThumbEMo(uint16_t keycode, keyrecord_t* record) {
     if ((keycode != MA_LTHUMB) & (keycode != MA_LTHUMBE)) {
         isLeftThumbEMoStarted = true;
     }
     switch (keycode) {
         case MA_LTHUMB:
             if (!(record->event.pressed)) {
                 layer_off(LA_LTHUMBEMO);
                 if(!isLeftThumbEMoStarted) {
                     layer_on(LA_LTHUMBEOSL);
                 } else {
                     isLeftThumbEMoStarted = false;
                     layer_off(LA_LTHUMB);
                 }
             }
             return false;
         case MA_SELLINE:
             if (record->event.pressed) {
                 tap_code16(KC_HOME);
                 tap_code16(KC_HOME);
                 register_code16(KC_LSFT);
                 tap_code16(KC_END);
                 tap_code16(KC_RGHT);
                 unregister_code16(KC_LSFT);
             }
             return false;
     }
     return true;
 }
 bool processKeycodeIfLThumbDMo(uint16_t keycode, keyrecord_t* record) {
     if ((keycode != MA_LTHUMB) & (keycode != MA_LTHUMBD)) {
         isLeftThumbDMoStarted = true;
     }
     switch (keycode) {
         case MA_LTHUMB:
             if (!(record->event.pressed)) {
                 layer_off(LA_LTHUMBDMO);
                 if(!isLeftThumbDMoStarted) {
                     layer_on(LA_LTHUMBDOSL);
                 } else {
                     isLeftThumbDMoStarted = false;
                     layer_off(LA_LTHUMB);
                 }
             }
             return false;
         case MA_JUMPTAB:
             if (!(record->event.pressed)) {
                 tap_code16(KC_HOME);
                 tap_code16(KC_HOME);
                 tap_code16(KC_TAB);
                 tap_code16(KC_DOWN);
             }
             return false;
         case MA_JUMPDETAB:
             if (!(record->event.pressed)) {
                 tap_code16(KC_UP);
                 tap_code16(KC_HOME);
                 tap_code16(KC_HOME);
                 tap_code16(KC_DEL);
             }
             return false;
     }
     return true;
 }
 bool processKeycodeIfLThumbEOsl(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case KC_SPC:
             register_code16(KC_LCTL);
             editModeLthumbOslStarted = true;
             return false;
     }
     if (!(record->event.pressed)) {
         if (editModeLthumbOslStarted) {unregister_code16(KC_RCTL);}
         layer_off(LA_LTHUMB);
         layer_off(LA_LTHUMBEOSL);
     }
     return true;
 }
 bool processKeycodeIfLThumbDOsl(uint16_t keycode, keyrecord_t* record) {

     switch (keycode) {
         case KC_SPC:
             register_code16(KC_RCTL);
             editModeLthumbOslStarted = true;
             return false;
     }
     if (!(record->event.pressed)) {
         if (editModeLthumbOslStarted) {unregister_code16(KC_RCTL);}
         layer_off(LA_LTHUMB);
         layer_off(LA_LTHUMBDOSL);
     }
     return true;
 }
 bool processKeycodeIfLThumb1Mo(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_LTHUMB:
             if (!(record->event.pressed)) {
                 layer_off(LA_LTHUMB1MO);
                 layer_off(LA_LTHUMB);
             }
             return false;
     }
     return true;
 }
 bool processKeycodeIfLThumb2Mo(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_LTHUMB:
             if (!(record->event.pressed)) {
                 layer_off(LA_LTHUMB2MO);
                 layer_off(LA_LTHUMB);
             }
             return false;
     }
     return true;
 }
 bool processKeycodeIfLThumb3Mo(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_LTHUMB:
             if (!(record->event.pressed)) {
                 layer_off(LA_LTHUMB3MO);
                 layer_off(LA_LTHUMB);
             }
             return false;
     }
     return true;
 }
 bool processKeycodeIfLThumbQ(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_LTHUMBQ:
             if (!(record->event.pressed)) {
                 if (IS_LAYER_ON(LA_MOUSE)) {isMouseX2Started = false;}
                 else {layer_off(LA_LTHUMBQ);}
             }
             return false;
         case MA_UPX2:
             if (record->event.pressed) {
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
             }
             return false;
         case MA_DOWNX2:
             if (record->event.pressed) {
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
             }
             return false;
         case MA_LEFTX2:
             if (record->event.pressed) {
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
             }
             return false;
         case MA_RIGHTX2:
             if (record->event.pressed) {
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
             }
             return false;
         case MA_DELX2:
             if (record->event.pressed) {
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
             }
             return false;
         case MA_ENTX2:
             if (record->event.pressed) {
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
             }
             return false;
         case MA_BSPCX2:
             if (record->event.pressed) {
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
             }
             return false;
     }
     return processKeycodeIfLPinky(keycode, record);
 }
 bool processKeycodeIfLThumbW(uint16_t keycode, keyrecord_t* record) {
     switch (keycode) {
         case MA_LTHUMBW:
             if (!(record->event.pressed)) {
                 if (IS_LAYER_ON(LA_MOUSE)) {isMouseX4Started = false;}
                 else {layer_off(LA_LTHUMBW);}
             }
             return false;
         case MA_UPX4:
             if (record->event.pressed) {
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
                 tap_code16(KC_UP);
             }
             return false;
         case MA_DOWNX4:
             if (record->event.pressed) {
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
                 tap_code16(KC_DOWN);
             }
             return false;
         case MA_LEFTX4:
             if (record->event.pressed) {
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
                 tap_code16(KC_LEFT);
             }
             return false;
         case MA_RIGHTX4:
             if (record->event.pressed) {
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
                 tap_code16(KC_RIGHT);
             }
             return false;
         case MA_DELX4:
             if (record->event.pressed) {
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
                 tap_code16(KC_DEL);
             }
             return false;
         case MA_ENTX4:
             if (record->event.pressed) {
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
                 tap_code16(KC_ENT);
             }
             return false;
         case MA_BSPCX4:
             if (record->event.pressed) {
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
                 tap_code16(KC_BSPC);
             }
             return false;
     }
     return true;
 }

