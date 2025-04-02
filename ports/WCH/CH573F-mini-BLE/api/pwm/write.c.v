// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PWM functions (WCH-CH573F)

module pwm

// There are two types of PWM ---> High_Level or Low_Level 
// There are two state of PWM ---> ENABLE or DISABLE 

@[inline]
pub fn write(channel, value, ...) {
	C.PWMX_ACTOUT(CH_PWM##channel, value, High_Level, ENABLE)
}
