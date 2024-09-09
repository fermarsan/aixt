// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: available.c.v
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

#define uart__available(MESSAGE)	Serial.available(MESSAGE)