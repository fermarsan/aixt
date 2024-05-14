module uart

#define	uart__write(DATA)  while(U1STAbits.UTXBF == 1){}  U1TXREG = DATA;