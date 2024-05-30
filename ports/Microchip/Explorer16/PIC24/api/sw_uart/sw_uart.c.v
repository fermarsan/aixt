module sw_uart

import time
import pin

#define sw_uart__baudrate   19200   //74880   //57600   //38400   //19200

#include	<stdlib.h>		// for itoa()

 // define serial pins tx and rx
#define sw_uart__tx     F, 6    //F, 5	// Tx : PORTB0
#define sw_uart__rx 	F, 8    //F, 4	// Rx : PORTB1

// __global (
//     sw_uart__baudrate = 5
// )

// enum baud {
//     sw_uart__baud_300     = 0     
//     sw_uart__baud_1200    
//     sw_uart__baud_2400    
//     sw_uart__baud_4800    
//     sw_uart__baud_9600    
//     sw_uart__baud_19200   
//     sw_uart__baud_38400   
//     sw_uart__baud_57600   
//     sw_uart__baud_74880   
//     sw_uart__baud_115200  
//     sw_uart__baud_230400  
//     sw_uart__baud_250000  
// }

// const bitperiod = [ 53333, 13333, 6667, 3333, 1667, 833, 417, 278, 214, 139, 69, 64 ]

// #define sw_uart__delay_for (2*16/FCY)		//extra delay on 14us write
// #define sw_uart__delay_for_read (2*18/FCY) //extra delay on read 10us

// #define sw_uart__bitperiod ((1000000/sw_uart__baudrate))	// duration of 1 bit in microseconds

// #define sw_uart__bitperiod_for (sw_uart__bitperiod - sw_uart__delay_for)	// actual delay on write
// #define sw_uart__bitperiod_for_read (sw_uart__bitperiod - sw_uart__delay_for_read)	// actual read delay
// #define sw_uart__halfbitperiod (sw_uart__bitperiod/2)		// half bit duration

#define sw_uart__bitperiod (FCY/sw_uart__baudrate)	// duration of 1 bit in microseconds
#define sw_uart__halfbitperiod (sw_uart__bitperiod/2)		// half bit duration


fn init() {
    pin.setup(sw_uart.tx, pin.output)
    pin.setup(sw_uart.rx, pin.input)
    pin.high(sw_uart.tx)
    time.sleep_cycles(sw_uart.bitperiod)
}

// fn C.bitperiod()

// fn C.halfbitperiod()