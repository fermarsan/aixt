void print(int duty) {
    for(int i__ = 1; i__ <= 50; i__++) {
        if(i__ <= duty/2) {
            printf("|");
        } else {
            printf("_");
        }
    }
    printf("\n");
}