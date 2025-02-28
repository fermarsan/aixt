// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: lcd module (Arduino Nano - ATmega328P port)
module lcd

#include "lcd.c"

fn C.LIQUIDCRYSTALLCD(P1 int,P2 int, P3 int, P4 int, P5 int, P6 int)
fn C.LCD_BEGIN(P1 int,P2 int)
fn C.LCD_PRINTF(P1 string) 
fn C.LCD_SETCURSOR(P1 int,P2 int) 
fn C.LCD_CLEAR() 
fn C.LCD_HOME() 
fn C.LCD_SCROLLDISPLAYLEFT() 
fn C.LCD_SCROLLDISPLAYRIGTH() 
fn C.LCD_NODISPLAY() 
fn C.LCD_DISPLAY() 
fn C.LCD_NOCURSOR() 
fn C.LCD_CURSOR() 
fn C.LCD_BLINK() 
fn C.LCD_NOBLINK() 
fn C.LCD_CREATECHAR(P1 u8,P2 u8[8]) 


