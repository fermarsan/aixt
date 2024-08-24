// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: high.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzman - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: HIGH functions (W801)
//              (PC port) 

module pin

// pin_high puts a high value (logic 1) to a specific pin
@[inline]
pub fn high(name int) {   
    C.digitalWrite(name, C.HIGH)
}