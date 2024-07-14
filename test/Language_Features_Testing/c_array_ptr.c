#include <stdio.h>

int A[] = {2,3,4,5};

int main() {

    int *ptr = &A[0];
    for(int i = 1; i<=4; i++) {
        (*ptr)++;
        ptr++;
    }
    
    ptr = &A[0];
    for(int j = 0; j<=3; j++) {
        printf("A[%d] = %d\n", j, *ptr);
        ptr++;
    }

    return 0;
}