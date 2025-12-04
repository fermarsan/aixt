uint8_t read(void){
    while(!(R8_UART0_RFC == 1)){}
    return R8_UART0_RBR; 
}