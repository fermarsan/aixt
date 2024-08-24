// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// Description: ADC functions (W801 port)
//              
module adc

pub const (
	led1 = u8(C.LED_BUILTIN_1)
    led2 = u8(C.LED_BUILTIN_2)
    led3 = u8(C.LED_BUILTIN_3)
    led4 = u8(C.LED_BUILTIN_4)
    led5 = u8(C.LED_BUILTIN_5)
    led6 = u8(C.LED_BUILTIN_6)
    led7 = u8(C.LED_BUILTIN_7)
    a1   = u8(C.PB21)
    a2   = u8(C.PB22)
    a3   = u8(C.PB23)
    a4   = u8(C.PB24)
    a5   = u8(C.PB0)
    a6   = u8(C.PB1)
    pin1 = u8(C.PB21)
    pin2 = u8(C.PB22)
)