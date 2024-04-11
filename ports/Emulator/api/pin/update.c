void update() {
    system(CLEAR_SCREEN);
    printf(" Aixt virtual pins     [#] = ON   [ ] = OFF\n");
    printf(" _____ _____ _____ _____ _____ _____ _____ _____\n");
    printf("|  a  |  b  |  c  |  d  |  w  |  x  |  y  |  z  |\n");
    for(int i__ = 0; i__<=7; i__++) {
        printf("| [");
        if(i__ <= 3) {
            printf("\033[1;32m");    // green
        } else {
            printf("\033[1;31m");    // red
        }
        if(pins__[i__] == 0) {
            printf(" ");
        } else {
            printf("#");
        }
        printf("\033[1;37m");    // white
        printf("] ");
    }
    printf("|\n");
    printf("'-----'-----'-----'-----'-----'-----'-----'-----'\n");
}