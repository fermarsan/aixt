// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: write functions (Ai_Thinker_Ai-WB2-32S-Kit)

module pwm

@[inline]
pub fn write(PIN_NAME, MODE) {
	C.analogWrite(PIN_NAME, MODE)
}