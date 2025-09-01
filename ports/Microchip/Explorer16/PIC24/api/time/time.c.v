// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2022-2024
// License: MIT
//
// Description: Milliseconds delay function
//              (Exp16-PIC24 port)
module time

#include <libpic30.h> 

fn C.__delay_ms(time int)
fn C.__delay_us(time int)
fn C.__delay32(cycles u32)

// sleep is a delay function in seconds (aproximation) 
// for the Aixt Exp16-PIC24 port. 
#define time.sleep(TIME)    __delay_ms(TIME*1000)

// sleep_ms is a delay function in milliseconds for the Aixt Exp16-PIC24 port. 
#define time.sleep_ms(TIME)    __delay_ms(TIME)

// sleep_us is a delay function in microseconds for the Aixt Exp16-PIC24 port. 
#define time.sleep_us(TIME)    __delay_us(TIME)

// sleep_us is a delay function in microseconds for the Aixt Exp16-PIC24 port. 
#define time.sleep_cycles(CYCLES)    __delay32(CYCLES)