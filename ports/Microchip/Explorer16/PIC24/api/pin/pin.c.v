// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: Pin management functions (Explorer16-PIC24 port)
module pin

#include <p24FJ128GA010.h>

// out macro defines the pin output mode
#define pin__output		0

// in macro defines the pin input mode
#define pin__input		1

#define a0      A, 0      // pin names
#define a1      A, 1 
#define a2      A, 2 
#define a3      A, 3 
#define a4      A, 4 
#define a5      A, 5 
#define a6      A, 6 
#define a7      A, 7 
// #define a8      A, 8 
#define a9      A, 9 
#define a10     A, 10
// #define a11     A, 11
// #define a12     A, 12
// #define a13     A, 13
#define a14     A, 14
#define a15     A, 15

#define b0      B, 0 
#define b1      B, 1 
#define b2      B, 2 
#define b3      B, 3 
#define b4      B, 4 
#define b5      B, 5 
#define b6      B, 6 
#define b7      B, 7 
#define b8      B, 8 
#define b9      B, 9 
#define b10     B, 10
#define b11     B, 11
#define b12     B, 12
#define b13     B, 13
#define b14     B, 14
#define b15     B, 15

// #define c0      C, 0 
#define c1      C, 1 
#define c2      C, 2 
#define c3      C, 3 
#define c4      C, 4 
// #define c5      C, 5 
// #define c6      C, 6 
// #define c7      C, 7 
// #define c8      C, 8 
// #define c9      C, 9 
// #define c10     C, 10
// #define c11     C, 11
#define c12     C, 12
#define c13     C, 13
#define c14     C, 14
#define c15     C, 15

#define d0      D, 0 
#define d1      D, 1 
#define d2      D, 2 
#define d3      D, 3 
#define d4      D, 4 
#define d5      D, 5 
#define d6      D, 6 
#define d7      D, 7 
#define d8      D, 8 
#define d9      D, 9 
#define d10     D, 10
#define d11     D, 11
#define d12     D, 12
#define d13     D, 13
#define d14     D, 14
#define d15     D, 15

#define e0      E, 0 
#define e1      E, 1 
#define e2      E, 2 
#define e3      E, 3 
#define e4      E, 4 
#define e5      E, 5 
#define e6      E, 6 
#define e7      E, 7 
#define e8      E, 8 
#define e9      E, 9 
// #define e10     E, 10
// #define e11     E, 11
// #define e12     E, 12
// #define e13     E, 13
// #define e14     E, 14
// #define e15     E, 15

#define f0      F, 0 
#define f1      F, 1 
#define f2      F, 2 
#define f3      F, 3 
#define f4      F, 4 
#define f5      F, 5 
#define f6      F, 6 
#define f7      F, 7 
#define f8      F, 8 
// #define f9      F, 9 
// #define f10     F, 10
// #define f11     F, 11
#define f12     F, 12
#define f13     F, 13
// #define f14     F, 14
// #define f15     F, 15

#define g0      G, 0 
#define g1      G, 1 
#define g2      G, 2 
#define g3      G, 3 
// #define g4      G, 4 
// #define g5      G, 5 
#define g6      G, 6 
#define g7      G, 7 
#define g8      G, 8 
#define g9      G, 9 
// #define g10     G, 10
// #define g11     G, 11
#define g12     G, 12
#define g13     G, 13
#define g14     G, 14
#define g15     G, 15

fn init() {
	
}