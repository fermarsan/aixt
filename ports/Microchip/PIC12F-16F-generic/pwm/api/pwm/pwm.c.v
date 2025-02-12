// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC16F88x port)
module pwm

// PWM channels
@[as_macro] pub const ch1	= 1
@[as_macro] pub const ch2	= 2


// PWM frecuency
// PWM1 frequencies (fosc=20Mhz)
@[as_macro] pub const f_6250hz_20mhz	1
@[as_macro] pub const f_1562hz_20mhz	2

// PWM1 frequencies (fosc=16Mhz)
@[as_macro] pub const f_20khz_16mhz		0
@[as_macro] pub const f_5khz_16mhz		1
@[as_macro] pub const f_1250hz_16mhz	2

// PWM1 frequencies (fosc=12Mhz)
@[as_macro] pub const f_15khz_12mhz		0
@[as_macro] pub const f_3125hz_12mhz	1
@[as_macro] pub const f_781hz_12mhz		2

// PWM1 frequencies (fosc=10Mhz)
@[as_macro] pub const f_12500hz_10mhz	0
@[as_macro] pub const f_3125hz_10mhz	1
@[as_macro] pub const f_781hz_10mhz		2

// PWM1 frequencies (fosc=8Mhz)
@[as_macro] pub const f_10khz_8mhz		0
@[as_macro] pub const f_2500hz_8mhz		1
@[as_macro] pub const f_625hz_8mhz		2

// PWM1 frequencies (fosc=4Mhz)
@[as_macro] pub const f_5khz_4mhz		0
@[as_macro] pub const f_1250hz_4mhz		1
@[as_macro] pub const f_312hz_4mhz		2