void write(uint8_t data){
    while(U2STAbits.UTXBF == 1){}
    U2TXREG = data;    // Write the data byte to the USART.
}