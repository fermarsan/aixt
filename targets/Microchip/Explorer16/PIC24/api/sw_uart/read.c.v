module sw_uart

import time
import pin

fn read() u8 {
    mask := u8(0x00)
    data := u8(0x00) 
    for pin.read(sw_uart.rx) == 1 {}	//sino llega el bit de star se queda a esperarlo
    time.sleep_cycles(sw_uart.halfbitperiod)
    for mask=0x01; mask!=0; mask=mask<<1 {
        time.sleep_cycles(sw_uart.bitperiod) //_for_read)    //retardo teniendo en cuenta os del for y el if es de 4 ciclos de reloj
        if pin.read(sw_uart.rx) {
			data = data | mask
		} 
    }
    time.sleep_cycles(sw_uart.bitperiod)
    return data 
}