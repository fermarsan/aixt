// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart.c.v
// Author: Fernando Martínez Santa - Johann Escobar Guzmán - Daniel Andrés Vásquez Gómez
// Date: 2023-2024
// License: MIT
//
// // Description: SLEEP_ms functions (W801)
//              (PC port) 

module uart

#include <stdio.h>
#include <string.h>

__global (
	uart__buffer = ''
)

fn init() {
	C.printf('\033[1;32m')	// print in green
	C.printf(' Aixt virtual UART\n')
}