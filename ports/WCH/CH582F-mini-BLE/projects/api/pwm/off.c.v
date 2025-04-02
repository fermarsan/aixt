// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PWM functions (WCH-CH582F)

module pwm

// There are two types of PWM ---> High_Level or Low_Level 
// There are two state of PWM ---> ENABLE or DISABLE 

@[inline]
pub fn off(channel, ...) {
	C.PWMX_ACTOUT(CH_PWM##channel, 0, High_Level, DISABLE)
}

