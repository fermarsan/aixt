// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin.c.v
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)

module pin

#define pin__output 0   // pin mode direction
#define pin__input  1

#define a0      A, 0      // pin names
#define a1      A, 1 
#define a2      A, 2 
#define a3      A, 3 

#define b0      B, 0 
#define b1      B, 1 
#define b2      B, 2 
#define b3      B, 3 
#define b4      B, 4 
#define b5      B, 5 
#define b6      B, 6 
#define b7      B, 7 