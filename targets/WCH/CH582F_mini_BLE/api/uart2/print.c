void print(char* msg){
    while(*msg != '\0'){
        uart2.write(*msg);
        msg++;
    }
}