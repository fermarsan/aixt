// Project Nme : Aixt project : http://gitlab.com/fermansan/aixt-project.git

// Author: Fernando M. Santa - Arley Junco - Luis Quevedo 
// Date: 2024
// License : MIT


module adc 

@[inline]
pub fn read(PIN_NAME) {
C.analogRead(PIN_NAME)
}