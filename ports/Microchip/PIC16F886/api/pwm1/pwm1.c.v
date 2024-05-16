// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: PWM management functions (PIC16F886 port)
module pwm1

// PWM1 frequencies (fosc=20Mhz)
#define	pwm1__6250hz_20mhz		1
#define	pwm1__1562hz_20mhz		2

// PWM1 frequencies (fosc=16Mhz)
#define	pwm1__20khz_16mhz		0
#define	pwm1__5khz_16mhz		1
#define	pwm1__1250hz_16mhz		2

// PWM1 frequencies (fosc=12Mhz)
#define	pwm1__15khz_12mhz		0
#define	pwm1__3125hz_12mhz		1
#define	pwm1__781hz_12mhz		2

// PWM1 frequencies (fosc=10Mhz)
#define	pwm1__12500hz_10mhz		0
#define	pwm1__3125hz_10mhz		1
#define	pwm1__781hz_10mhz		2

// PWM1 frequencies (fosc=8Mhz)
#define	pwm1__10khz_8mhz		0
#define	pwm1__2500hz_8mhz		1
#define	pwm1__625hz_8mhz		2

// PWM1 frequencies (fosc=4Mhz)
#define	pwm1__5khz_4mhz			0
#define	pwm1__1250hz_4mhz		1
#define	pwm1__312hz_4mhz		2