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

#define __string_add(SOURCE1, SOURCE2) {\
    strcpy(__temp_str, SOURCE1); \
    strcat(__temp_str, SOURCE2); \
    __temp_str; \
}