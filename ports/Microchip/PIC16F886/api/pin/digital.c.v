// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: digital.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F886 port)


#define pin__digital()  ANSELH = 0; ANSEL = 0;
//#define pin__digital1 ANSEL = 0; // configura las entradas o salidas como digitales desde AN0 hatas AN7