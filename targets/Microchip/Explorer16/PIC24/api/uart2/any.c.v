module uart2

@[inline]
pub fn any() {
	C.U2STAbits.URXDA
}
