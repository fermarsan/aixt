// Project Name : Aixt: http://github.com/fermansan/aixt.git
// Author: Farith Ochoa León, Delipe Cardozo and Fernando M. Santa 
// License : MIT

module pin 

@[inline]
pub fn read(PIN_NAME) {
	C.digitalRead(PIN_NAME)
}