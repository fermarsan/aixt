// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera
// Date: 2022-2025
// License: MIT
//
// // Description: pwm functions (CY8CKIT-145-40XX)

module pwm

// @[as_macro]
// pub fn write(channel any, val any) {
// 	C.PWM_WRITE(channel, val)
// }

@[as_macro]
pub fn write(channel int, val any) {
	match channel {
		pwm.ch0 {
			C.pwm_0_WriteCompare(val)
		}
		pwm.ch1 {
			C.pwm_1_WriteCompare(val)
		}
		pwm.ch2 {
			C.pwm_2_WriteCompare(val)
		}
		else { }
	}
}