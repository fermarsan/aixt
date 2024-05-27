// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: low.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán- Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: LOW functions (W801)
//              (PC port) 

module pin

#define pin__low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)