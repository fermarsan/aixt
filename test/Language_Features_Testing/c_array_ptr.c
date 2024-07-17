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

#define MY_MACRO(...) MY_MACRO_SELECT(__VA_ARGS__, _)

#define MY_MACRO_SELECT(_1, _2, ...) MY_MACRO_IMPL(_1, _2)

#define MY_MACRO_IMPL(name, greeting) \
    _Generic((greeting), \
        char*: MY_MACRO_TWO, \
        default: MY_MACRO_ONE \
    )(name, greeting)

void MY_MACRO_ONE(char* name, char* greeting) {
    printf("Calling function with one parameter: %s\n", name);
}

void MY_MACRO_TWO(char* name, char* greeting) {
    printf("Calling function with two parameters: %s, %s\n", greeting, name);
}

int main() {
    MY_MACRO("Alice");
    MY_MACRO("Bob", "Hello");

    return 0;
}