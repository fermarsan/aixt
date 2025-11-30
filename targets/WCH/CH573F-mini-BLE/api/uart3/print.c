void print(char* msg){
    while(*msg != '\0'){
        uart3.write(*msg);
        msg++;
    }
}