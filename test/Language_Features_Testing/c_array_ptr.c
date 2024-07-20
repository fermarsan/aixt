// #include <stdio.h>

// int A[] = {2,3,4,5};

// int main() {

//     int *ptr = &A[0];
//     for(int i = 1; i<=4; i++) {
//         (*ptr)++;
//         ptr++;
//     }
    
//     ptr = &A[0];
//     for(int j = 0; j<=3; j++) {
//         printf("A[%d] = %d\n", j, *ptr);
//         ptr++;
//     }

//     return 0;
// }

#include <stdio.h>

// #define DEBUG  // Define DEBUG para habilitar la asignación condicional

int main() {
    #ifdef DEBUG
        int x = 100;
    #else
        int x = 200;
    #endif

    printf("El valor de x es: %d\n", x);

    return 0;
}