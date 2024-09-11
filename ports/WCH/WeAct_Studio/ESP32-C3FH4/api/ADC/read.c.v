// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Farith Ochoa León, Delipe Cardozo and Fernando M. Santa 
// License : MIT

module adc 

@[inline]
pub fn read(PIN_NAME) {
C.analogRead(PIN_NAME)
}
