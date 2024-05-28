module sw_uart

import time
import pin

#include	<stdlib.h>		// for itoa()

 // define serial pins tx and rx
#define sw_uart__tx	B, 0	// Tx : PORTB0
#define sw_uart__rx 	B, 1	// Rx : PORTB1

#define sw_uart__delay_for (2*16/FCY)		//extra delay on 14us write
#define sw_uart__delay_for_read (2*18/FCY) //extra delay on read 10us

#define sw_uart__bitperiod ((1000000/sw_uart__baudrate))	// duration of 1 bit in microseconds

#define sw_uart__bitperiod_for (sw_uart__bitperiod - sw_uart__delay_for)	// actual delay on write
#define sw_uart__bitperiod_for_read (sw_uart__bitperiod - sw_uart__delay_for_read)	// actual read delay
#define sw_uart__halfbitperiod (sw_uart__bitperiod/2)		// half bit duration


__global (
	sw_uart__baudrate = 19_200
)

fn init() {
    pin.high(sw_uart.tx);
    pin.high(sw_uart.rx);
    pin.setup(sw_uart.tx, pin.output);
    pin.setup(sw_uart.rx, pin.input);
    pin.high(sw_uart.tx);
    time.sleep_us(sw_uart.bitperiod);
}