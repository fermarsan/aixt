// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: high.c.v
// Author: Fernando M. Santa - Johann Escobar Guzman - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: HIGH functions (W801)
//              (PC port) 

module pin

#define pin__high(PIN_NAME)   digitalWrite(PIN_NAME, HIGH)