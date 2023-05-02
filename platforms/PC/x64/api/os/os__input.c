#include "os__input.h"

char *os__input(char *msg) {
    printf("%s", msg);
    scanf("%s", &in_str[0]);
    return in_str;
}