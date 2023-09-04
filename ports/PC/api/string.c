// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: string.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: String managment functions
//              (PC port)
#include <string.h>

char __temp_str[30];

#define __string_assign(DEST, SOURCE)   strcpy(DEST, SOURCE)

#define __string_append(DEST, SOURCE)   strcat(DEST, SOURCE)  

char *__string_add(char *str1, char *str2) {
    strcpy(__temp_str, str1);
    strcat(__temp_str, str2);
    return __temp_str;
}