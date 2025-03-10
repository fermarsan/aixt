
@[as_macro]
fn irq_enable() {
	C.SPCR |= (1<<C.SPIE)   // Enable SPI Interrupt
}