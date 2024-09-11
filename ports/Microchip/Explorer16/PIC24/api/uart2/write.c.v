module uart2

@[inline]
pub fn uart2.write(DATA) {
C.while(U2STAbits.UTXBF == 1){}  U2TXREG = DATA;
}