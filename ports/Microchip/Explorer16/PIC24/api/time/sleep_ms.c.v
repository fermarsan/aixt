// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
module time

// sleep_ms is a delay function in milliseconds for the Aixt Explorer16-PIC24 port. 
#define time.sleep_ms(TIME)    __delay_ms(TIME)
