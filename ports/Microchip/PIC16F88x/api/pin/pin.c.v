// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F88x port)
module pin

#define output 0	// pin mode direction
#define input  1

#define a0      A, 0	// pin names
#define a1      A, 1 
#define a2      A, 2 
#define a3      A, 3 
#define a4      A, 4 
#define a5      A, 5 
#define a6      A, 6 
#define a7      A, 7  

#define b0      B, 0 
#define b1      B, 1 
#define b2      B, 2 
#define b3      B, 3 
#define b4      B, 4 
#define b5      B, 5 
#define b6      B, 6 
#define b7      B, 7  

#define c0      C, 0 
#define c1      C, 1 
#define c2      C, 2 
#define c3      C, 3 
#define c4      C, 4 
#define c5      C, 5 
#define c6      C, 6 
#define c7      C, 7  

#define e3      E, 3 