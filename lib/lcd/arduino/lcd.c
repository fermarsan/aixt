#define LCD_PINS(rs,en, d4, d5, d6, d7)                     LiquidCrystal lcd(rs,en, d4, d5, d6, d7)
#define LCD_BEGIN(P1,P2)                                    lcd.begin(P1,P2)
#define LCD_PRINT(P1)                                       lcd.print(P1) 
#define LCD_PRINTLN(P1)                                      lcd.println(P1) 
#define LCD_SETCURSOR(P1,P2)                                lcd.setCursor(P1,P2)
#define LCD_CLEAR()                                         lcd.clear()
#define LCD_HOME()                                          lcd.home()
#define LCD_SCROLLDISPLAYLEFT()                             lcd.scrollDisplayLeft()    
#define LCD_SCROLLDISPLAYRIGHT()                            lcd.scrollDisplayRight()  
#define LCD_NODISPLAY()                                     lcd.noDisplay() 
#define LCD_DISPLAY()                                       lcd.display();
#define LCD_NOCURSOR()                                      lcd.noCursor();
#define LCD_CURSOR()                                        lcd.cursor();
#define LCD_BLINK()                                         lcd.blink();
#define LCD_NOBLINK()                                       lcd.noBlink();
#define LCD_CREATECHAR(P1,P2)                               lcd.createchar(P1,P2)
 


