module uart

@[inline]
pub fn any() {
	C.U1STAbits.URXDA
}