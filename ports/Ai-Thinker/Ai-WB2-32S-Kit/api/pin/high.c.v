// Project name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: high functions (Ai_Thinker_Ai-WB2-32S-Kit)

module pin

@[inline]
pub fn high(PIN_NAME) {
	C.digitalWrite(PIN_NAME, HIGH)
}