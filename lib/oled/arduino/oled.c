
#include <Wire.h>  //Incluye libreria para comunicación ADDRESS
#include <Adafruit_GFX.h>  //Incluye libreria de interfaz grafica
#include <Adafruit_SSD1306.h>  //Incluye libreria para display OLED SSD1306

#define DISPLAY_BEGIN(TYPE, ADDRESS)                                display.begin(TYPE, ADDRESS)
#define DISPLAY_CLEARDISPLAY()                                      display.clearDisplay()
#define DISPLAY_SETTEXTSIZE(NUMBER)                                 display.setTextSize(NUMBER) 
#define DISPLAY_TEXTCOLOR(CHARACTER)                                display.setTextColor(CHARACTER)
#define DISPLAY_SETCURSOR(X,Y)                                      display.setCursor(X,Y)      
#define DISPLAY_PRINTLN(MESSAGE)                                    display.println(MESSAGE)
#define DISPLAY_DISPLAY()                                           display.display()     
#define DISPLAY_DRAWPIXEL(X,Y,COLOR)                                display.drawPixel(X,Y,COLOR) 
#define DISPLAY_DRAWRECT(X,Y,WIDTH,HEIGHT,COLOR)                    display.drawRect(X,Y,WIDTH,HEIGHT,COLOR)
#define DISPLAY_FILLRECT(X,Y,WIDTH,HEIGHT,COLOR)                    display.fillRect(X,Y,WIDTH,HEIGHT,COLOR)
#define DISPLAY_DRAWCICRLE(X,Y,RADIO,COLOR)                         display.drawCircle(X,Y,RADIO,COLOR)
#define DISPLAY_FILLCIRCLE(X,Y,RADIO,COLOR)                         display.fillCircle(X,Y,RADIO,COLOR)
#define DISPLAY_DRAWBITMAP(X,Y,ARRAY_IMAGE,WIDTH,HEIGHT,COLOR)      display.drawBitmap(X,Y,ARRAY_IMAGE,WIDTH,HEIGHT,COLOR)