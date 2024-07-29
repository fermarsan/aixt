void print(char* msg){
    while(*msg != '\0'){
        uart3__write(*msg);
        msg++;
    }
}