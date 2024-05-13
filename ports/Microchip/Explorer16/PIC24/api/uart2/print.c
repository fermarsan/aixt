void print(char* msg){
    while(*msg != NULL){
        uart2__write(*msg);
        msg++;
    }
}