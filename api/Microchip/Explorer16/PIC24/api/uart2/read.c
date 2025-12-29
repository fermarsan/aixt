uint8_t read(void){
    while(!(U2STAbits.URXDA == 1)){}

    if ((U2STAbits.OERR == 1)){
        U2STAbits.OERR = 0;
    }

    return U2RXREG;
}