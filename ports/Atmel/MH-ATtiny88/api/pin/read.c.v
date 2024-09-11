// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Fernando M. Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT

module pin 

@[inline]
pub fn read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}