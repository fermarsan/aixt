// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC16F886 port)
module pwm

#define	pwm__ch1		1
#define	pwm__ch2		2

// PWM1 frequencies (fosc=20Mhz)
#define	pwm__f_6250hz_20mhz		1
#define	pwm__f_1562hz_20mhz		2

// PWM1 frequencies (fosc=16Mhz)
#define	pwm__f_20khz_16mhz		0
#define	pwm__f_5khz_16mhz		1
#define	pwm__f_1250hz_16mhz		2

// PWM1 frequencies (fosc=12Mhz)
#define	pwm__f_15khz_12mhz		0
#define	pwm__f_3125hz_12mhz		1
#define	pwm__f_781hz_12mhz		2

// PWM1 frequencies (fosc=10Mhz)
#define	pwm__f_12500hz_10mhz	0
#define	pwm__f_3125hz_10mhz		1
#define	pwm__f_781hz_10mhz		2

// PWM1 frequencies (fosc=8Mhz)
#define	pwm__f_10khz_8mhz		0
#define	pwm__f_2500hz_8mhz		1
#define	pwm__f_625hz_8mhz		2

// PWM1 frequencies (fosc=4Mhz)
#define	pwm__f_5khz_4mhz		0
#define	pwm__f_1250hz_4mhz		1
#define	pwm__f_312hz_4mhz		2