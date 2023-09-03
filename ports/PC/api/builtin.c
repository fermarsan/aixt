// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Builtin definitions
//              (PC port). 
#include <stdio.h>
#include <string.h>

#define print(STR)      printf(STR)
#define println(STR)    printf(STR); printf("\n")

// #define string__assign(DEST, SOURCE)    strcpy(DEST, SOURCE) 

enum __pin_names {    // enumerated type for the pin names
    a = 0,    
    b,
    c,
    d,
    w,
    x,
    y,
    z
};