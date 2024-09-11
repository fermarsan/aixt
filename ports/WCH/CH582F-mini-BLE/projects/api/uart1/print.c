void print(char* msg){
    while(*msg != '\0'){
        uart1.write(*msg);
        msg++;
    }
}