// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT
//
// Description: lcd module (Arduino Nano - ATmega328P port)
module button1

#include "button1.c"


pub const btn_right = u8(0)
pub const btn_up = u8(1)
pub const btn_down = u8(2)
pub const btn_left = u8(3)
pub const btn_select = u8(4)
pub const btn_none = u8(5)



fn C.LCD_BUTTON1() i8 {
 valor_adc := adc.read(adc.ch0)


return match valor_adc {
        0..50    { 0 }  // Botón DERECHA (RIGHT)
        51..200  { 1 }  // Botón ARRIBA (UP)
        201..400 { 2 }  // Botón ABAJO (DOWN)
        401..600 { 3 }  // Botón IZQUIERDA (LEFT)
        601..850 { 4 }  // Botón SELECT
        else     { 5 }  // Ningún botón presionado (NONE)
    }
}