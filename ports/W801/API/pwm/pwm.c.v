// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: pwm.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: PWM functions (W801)
//              (PC port) 

module pwm

pub const ( // enumerated type for digital pin names
	led1 = C.LED_BUILTIN_1
	led2 = C.LED_BUILTIN_2
	led3 = C.LED_BUILTIN_3
	led4 = C.LED_BUILTIN_4
	led5 = C.LED_BUILTIN_5
	led6 = C.LED_BUILTIN_6
	led7 = C.LED_BUILTIN_7
	a1 = C.PB21
	a2 = C.PB22
	a3 = C.PB23
	a4 = C.PB24
	a5 = C.PB0
	a6 = C.PB1
	pin1 = C.PB21
	pin2 = C.	PB22
)

pub const (
	output  = C.OUTPUT  
    input   = C.INPUT  
)