// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP functions (W801)
//              (PC port) 

module time

#define time.sleep(S)    delay(S*1000)