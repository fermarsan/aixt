uint8_t read(void){
    while(!(U1STAbits.URXDA == 1)){}

    if ((U1STAbits.OERR == 1)){
        U1STAbits.OERR = 0;
    }

    return U1RXREG;
}