// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
//
// Description: 
module time

#include <libpic30.h>	//(PIC24, dsPIC33)

// sleep is a delay function in seconds (aproximation) 
// for the Aixt Exp16-PIC24 port. 
#define time.sleep(TIME)    __delay_ms(TIME*1000)

// sleep_ms is a delay function in milliseconds for the Aixt Exp16-PIC24 port. 
#define time.sleep_ms(TIME)    __delay_ms(TIME)

// sleep_us is a delay function in microseconds for the Aixt Exp16-PIC24 port. 
#define time.sleep_us(TIME)    __delay_us(TIME)