// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: input.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: input function for the Aixt PC port.
#include <stdio.h>
#include <string.h>

// #define OUT = os__input(IN) 

char __in_str[30];

char *osinput(char *msg) {
    printf("%s", msg);
    scanf("%s", &__in_str[0]);
    return __in_str;
}