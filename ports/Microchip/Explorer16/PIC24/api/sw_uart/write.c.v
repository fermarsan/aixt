module sw_uart

fn write(data u8) {
    mask := u8(0x00)
    pin.low(sw_uart__tx)
    time.sleep_us(sw_uart__bitperiod)
    //"for" expends 14 clock cycles
    for mask=0x01; mask!=0; mask=mask<<1 {
        if data & mask {
			pin.high(sw_uart__tx)
		} else {
			pin.low(sw_uart__tx)
		}
        time.sleep_us(sw_uart__bitperiod_for)  //para mayor precision acorde al cristal   porque son 14 cilcos de reloj
    }
    pin.high(sw_uart__tx)
    time.sleep_us(sw_uart__bitperiod)
}