// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP functions (W801)
//              (PC port) 

module time

#define time__sleep(S)    delay(S*1000)