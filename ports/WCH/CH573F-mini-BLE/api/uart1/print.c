void print(char* msg){
    while(*msg != '\0'){
        uart1__write(*msg);
        msg++;
    }
}