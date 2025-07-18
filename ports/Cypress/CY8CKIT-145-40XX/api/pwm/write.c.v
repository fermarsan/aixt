// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: pwm write (CY8CKIT-145-40XX)

module pwm

// @[as_macro]
// pub fn write(channel any, val any) {
// 	C.PWM_WRITE(channel, val)
// }

@[as_macro]
pub fn write(channel int, val any) {
	match channel {
		pwm.ch0 {
			C.pwm0_WriteCompare(val)
		}
		pwm.ch1 {
			C.pwm1_WriteCompare(val)
		}
		pwm.ch2 {
			C.pwm2_WriteCompare(val)
		}
		else { }
	}
}