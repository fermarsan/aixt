// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: strings/add.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: String managment functions
//              (PC port)
#include <string.h>

char __temp_str[30];

char *__string_add(char *str1, char *str2) {
    strcpy(__temp_str, str1);
    strcat(__temp_str, str2);
    return __temp_str;
}