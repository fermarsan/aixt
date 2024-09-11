module uart

@[inline]
pub fn uart.write(DATA) {
	C.while(U1STAbits.UTXBF == 1){}  U1TXREG = DATA;
}