// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Farith Ochoa León, Delipe Cardozo and Fernando M. Santa 
// License : MIT

module pin 

@[inline]
pub fn pwm.setup(PIN_NAME, MODE) {
	C.pinMode(PIN_NAME, MODE)
}