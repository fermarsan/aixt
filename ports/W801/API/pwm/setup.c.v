// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SETUP functions (W801)
//              (PC port) 

module pin

// setup configures a pin's input/output mode
@[inline]
pub fn setup(name int, mode int) {   
    C.pinMode(name, mode)
}