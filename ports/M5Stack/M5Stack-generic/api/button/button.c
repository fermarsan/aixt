#define btn_a   BtnA
#define btn_b   BtnB
#define btn_c   BtnC

#define M5_BTN_READ(BUTTON)             M5.##BUTTON##.read(); // Must be called in loop(), or via update()                                      // Must be called in loop(), or via update()
#define M5_BTN_ISPRESSED(BUTTON)        M5.##BUTTON##.isPressed();                        
#define M5_BTN_ISRELEASED(BUTTON)       M5.##BUTTON##.isReleased();                        
#define M5_BTN_WASPRESSED(BUTTON)       M5.##BUTTON##.wasPressed();                        
#define M5_BTN_WASRELEASED(BUTTON)      M5.##BUTTON##.wasReleased();                        
#define M5_BTN_WASRELEASEDFOR(BUTTON)   M5.##BUTTON##.wasreleasedFor()    
#define M5_BTN_PRESSEDFOR(BUTTON, ms)   M5.##BUTTON##.pressedFor(ms);                                    
#define M5_BTN_RELEASEDFOR(BUTTON, ms)  M5.##BUTTON##.releasedFor(ms);                                    
#define M5_BTN_LASTCHANGE(BUTTON)       M5.##BUTTON##.lastChange();                        