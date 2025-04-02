// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//	- Javier Leon
//	- Camilo Lucas
//	- Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate a PWM output in console.
//              (CY8CKIT-049-42XX)

#define pwm_duty(pwm_id, duty)  pwm##pwm_id##_WriteCompare(duty*655)
