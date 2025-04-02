module irq

// global interrupts enable/disable

@[inline]
pub fn enable()	{
	C.INTCONbits.GIE = 1	
}

@[inline]
pub fn disable() {
	C.INTCONbits.GIE = 0
}	

// external interrupt

@[inline]
pub fn external_enable() {
	C.INTCONbits.GIE = 1
	C.INTCONbits.INTE = 1
}


@[inline]
pub fn external_clear()	{
	C.INTCONbits.INTF = 0
}

@[inline]
pub fn external_rising() {
	C.OPTION_REGbits.INTEDG = 1
}

@[inline]
pub fn external_falling() {
	C.OPTION_REGbits.INTEDG = 0
}

@[inline]
pub fn external(FN_NAME) {
	void isr_external(void)

// 
@[inline]
pub fn uart_rx(FN_NAME) {
	isr_external()
}
// timer 0 interrupt

@[inline]
pub fn timer0(FN_NAME) {
	isr_timer0()
}

fn C.global_isr()