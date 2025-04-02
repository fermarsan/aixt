void print(char* msg){
    while(*msg != '\0'){
        uart.write(*msg);
        msg++;
    }
}