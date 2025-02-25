#define LIQUIDCRYSTALLCD(P1,P2,P3,P4,P5,P6)                 LiquidCrystal lcd(P1,P2, P3, P4, P5, P6)
#define LCD_BEGIN(P1,P2)                                    lcd.begin(P1,P2)
#define LCD_PRINTF(P1)                                      lcd.printf(P1) 
#define LCD_SETCURSOR(P1,P2)                                lcd.setCursor(P1,P2)
#define LCD_CLEAR()                                         lcd.clear()
#define LCD_HOME()                                          lcd.home()
#define LCD_SCROLLDISPLAYLEFT()                             lcd.scrollDisplayleft()    
#define LCD_SCROLLDISPLAYRIGHT()                            lcd.scrollDisplayright()  
#define LCD_NODISPLAY()                                     lcd.noDisplay() 
#define LCD_DISPLAY()                                       lcd.display();
#define LCD_NOCURSOR()                                      lcd.noCursor();
#define LCD_CURSOR()                                        lcd.cursor();
#define LCD_BLINK()                                         lcd.blink();
#define LCD_NOBLINK()                                       lcd.noBlink();
#define LCD_CREATECHAR(P1,P2)                               lcd.createchar(P1,P2);

