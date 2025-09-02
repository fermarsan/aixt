uint8_t read(void){
    while(!(R8_UART2_RFC == 1)){}
    return R8_UART2_RBR; 
}