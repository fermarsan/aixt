module uart

@[inline]
pub fn uart.any() {
	C.U1STAbits.URXDA
}