module uart2

@[inline]
pub fn uart2.any() {
	C.U2STAbits.URXDA
}