void print(char* msg){
    while(*msg != '\0'){
        uart2__write(*msg);
        msg++;
    }
}