// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c.v
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_us functions (W801)
//              (PC port) 

module time

#define time__sleep_us(US)    delayMicroseconds(US)