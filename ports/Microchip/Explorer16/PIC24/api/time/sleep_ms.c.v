// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
module time

// sleep_ms is a delay function in milliseconds for the Aixt Explorer16-PIC24 port. 
#define time__sleep_ms(TIME)    __delay_ms(TIME)

// void sleep_ms(int time)  // equivalent using a function
// {
//     __delay_ms(time);
// }