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
fn C.LCD_CLEAR() void
fn C.LCD_HOME() void
fn C.LCD_SCROLLDISPLAYLEFT() void
fn C.LCD_SCROLLDISPLAYRIGTH() void
fn C.LCD_NODISPLAY() void
fn C.LCD_DISPLAY() void
fn C.LCD_NOCURSOR() void
fn C.LCD_CURSOR() void
fn C.LCD_BLINK() void
fn C.LCD_NOBLINK() void
fn C.LCD_CREATECHAR(P1 u8,P2 u8) 


