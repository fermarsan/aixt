// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: builtin.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Builtin definitions
//              (PC port) 

#define led     gp25
#define boton   gp11
#define led1    gp13
#define led2    gp14
#define led3    gp15
#define led4    gp16
#define led5    gp10
#define pot     gp27
#define POT1    gp28

enum __pin_names {    // enumerated type for the pin names
    gp0,    
    gp1,
    gp2,
    gp3,
    gp4,
    gp5,
    gp6,
    gp7,
    gp8,
    gp9,
    gp10,
    gp11,
    gp12,
    gp13,
    gp14,
    gp15,
    gp16,
    gp17,
    gp18,
    gp19,
    gp20,
    gp21,
    gp22,
    gp23,
    gp24,
    gp25,
    gp26,
    gp27,
    gp28,
    gp29,
};