// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP functions (W801)
//              (PC port) 

module time

// sleep is a delay function in seconds for the Aixt PC port. 
@[inline]
pub fn sleep(ts int) {
    C.delay(ts*1000)
}