// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: read functions (Ai_Thinker_Ai-WB2-32S-Kit)

module pin

@[inline]
pub fn pin.read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}