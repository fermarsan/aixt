void print(char* msg){
    while(*msg != '\0'){
        uart__write(*msg);
        msg++;
    }
}