// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

// sleep is a delay function in seconds (aproximation) 
// for the Aixt Explorer16-PIC24 port. 
#define time__sleep(TIME)    __delay_ms(TIME*1000)
