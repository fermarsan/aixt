// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: WRITE functions (W801)
//              (PC port) 

module pin

// write puts a logic value to a specific pin
@[inline]
pub fn write(name int, val int) {  
    C.digitalWrite(name, val)
}