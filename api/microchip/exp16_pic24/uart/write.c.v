module uart

@[inline]
pub fn write(data u8) {
	C.while(U1STAbits.UTXBF == 1){}  U1TXREG = DATA;
}
