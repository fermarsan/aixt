// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module time

// sleep_us is a delay function in microseconds for the Aixt Explorer16-PIC24 port. 
#define time__sleep_cycles(CYCLES)    __delay32(CYCLES)