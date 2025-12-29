module uart2

@[inline]
pub fn write(data u8) {
C.while(U2STAbits.UTXBF == 1){}  U2TXREG = DATA;
}
