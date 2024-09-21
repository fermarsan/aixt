// Project Name : Aixt: http://github.com/fermansan/aixt.git
// Author: Farith Ochoa León, Delipe Cardozo and Fernando M. Santa 
// License : MIT

module pwm 

@[inline]
pub fn write(PIN, VALUE) {
	C.analogWrite(PIN, VALUE)
}