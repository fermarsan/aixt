module sw_uart

import time
import pin

fn write(data u8) {
    // sw_uart.bitperiod = 1e6 / sw_uart.baudrate
    mask := u8(0x00)
    pin.low(sw_uart.tx)
    time.sleep_cycles(sw_uart.bitperiod)
    //"for" expends 14 clock cycles
    for mask=0x01; mask!=0; mask=mask<<1 {
        if data & mask {
			pin.high(sw_uart.tx)
		} else {
			pin.low(sw_uart.tx)
		}
        time.sleep_cycles(sw_uart.bitperiod)//_for)  //para mayor precision acorde al cristal   porque son 14 cilcos de reloj
    }
    pin.high(sw_uart.tx)
    time.sleep_cycles(sw_uart.bitperiod)
}