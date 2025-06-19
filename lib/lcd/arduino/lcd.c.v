// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: lcd module (Arduino Nano - ATmega328P port)
module lcd

#include "lcd.c"
#include <LiquidCrystal.h>


fn C.LCD_PINS(rs int,en int, d4 int, d5 int, d6 int, d7 int)
fn C.LCD_BEGIN(p1 u8,p2 u8)
fn C.LCD_PRINT(p1 f32) 
fn C.LCD_PRINTLN(p1 string) 
fn C.LCD_SETCURSOR(p1 int,p2 int) 
fn C.LCD_CLEAR() 
fn C.LCD_HOME() 
fn C.LCD_SCROLLDISPLAYLEFT() 
fn C.LCD_SCROLLDISPLAYRIGHT() 
fn C.LCD_NODISPLAY() 
fn C.LCD_DISPLAY() 
fn C.LCD_NOCURSOR() 
fn C.LCD_CURSOR() 
fn C.LCD_BLINK() 
fn C.LCD_NOBLINK() 
fn C.LCD_CREATECHAR(p1 u8,p2 u8) 


