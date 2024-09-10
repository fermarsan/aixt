// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: READ functions (W801)
//              (PC port) 

module adc

#define adc__read(PIN_NAME)   analogRead(PIN_NAME)