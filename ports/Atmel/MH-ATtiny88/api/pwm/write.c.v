// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Fernando M. Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT

module pwm

@[inline]
pub fn pwm.write(PIN, VALUE) {
	C.analogWrite(PIN, VALUE)
}