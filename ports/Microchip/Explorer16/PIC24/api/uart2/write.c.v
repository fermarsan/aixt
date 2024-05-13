module uart2

#define	uart2__write(DATA)  while(U2STAbits.UTXBF == 1){}  U2TXREG = DATA;