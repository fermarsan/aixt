// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: write.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: WRITE functions (W801)
//              (PC port) 

module pin

#define pin__write(PIN_NAME, VALUE)   digitalWrite(PIN_NAME, VALUE)