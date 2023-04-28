#include "os__input.h"

char *os__input(char *msg) {
    printf(msg);
    scanf("%s",&in_str);
    return in_str
}