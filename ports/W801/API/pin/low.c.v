// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: low.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán- Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: LOW functions (W801)
//              (PC port) 

module pin

// pin_high puts a low value (logic 0) to a specific pin
@[inline]
pub fn low(name int) {   
    C.digitalWrite(name, C.LOW)
}