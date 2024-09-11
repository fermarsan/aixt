// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Farith Ochoa León, Delipe Cardozo and Fernando M. Santa 
// License : MIT

module pin 

@[inline]
pub fn pin.high(PIN_NAME) {
	C.digitalWrite(PIN_NAME, HIGH)
}