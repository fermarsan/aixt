// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
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

#define pin__a0      A, 0      // pin names
#define pin__a1      A, 1 
#define pin__a2      A, 2 
#define pin__a3      A, 3 
#define pin__a4      A, 4 
#define pin__a5      A, 5 
#define pin__a6      A, 6 
#define pin__a7      A, 7 
// #define pin__a8      A, 8 
#define pin__a9      A, 9 
#define pin__a10     A, 10
// #define pin__a11     A, 11
// #define pin__a12     A, 12
// #define pin__a13     A, 13
#define pin__a14     A, 14
#define pin__a15     A, 15

#define pin__b0      B, 0 
#define pin__b1      B, 1 
#define pin__b2      B, 2 
#define pin__b3      B, 3 
#define pin__b4      B, 4 
#define pin__b5      B, 5 
#define pin__b6      B, 6 
#define pin__b7      B, 7 
#define pin__b8      B, 8 
#define pin__b9      B, 9 
#define pin__b10     B, 10
#define pin__b11     B, 11
#define pin__b12     B, 12
#define pin__b13     B, 13
#define pin__b14     B, 14
#define pin__b15     B, 15

// #define pin__c0      C, 0 
#define pin__c1      C, 1 
#define pin__c2      C, 2 
#define pin__c3      C, 3 
#define pin__c4      C, 4 
// #define pin__c5      C, 5 
// #define pin__c6      C, 6 
// #define pin__c7      C, 7 
// #define pin__c8      C, 8 
// #define pin__c9      C, 9 
// #define pin__c10     C, 10
// #define pin__c11     C, 11
#define pin__c12     C, 12
#define pin__c13     C, 13
#define pin__c14     C, 14
#define pin__c15     C, 15

#define pin__d0      D, 0 
#define pin__d1      D, 1 
#define pin__d2      D, 2 
#define pin__d3      D, 3 
#define pin__d4      D, 4 
#define pin__d5      D, 5 
#define pin__d6      D, 6 
#define pin__d7      D, 7 
#define pin__d8      D, 8 
#define pin__d9      D, 9 
#define pin__d10     D, 10
#define pin__d11     D, 11
#define pin__d12     D, 12
#define pin__d13     D, 13
#define pin__d14     D, 14
#define pin__d15     D, 15

#define pin__e0      E, 0 
#define pin__e1      E, 1 
#define pin__e2      E, 2 
#define pin__e3      E, 3 
#define pin__e4      E, 4 
#define pin__e5      E, 5 
#define pin__e6      E, 6 
#define pin__e7      E, 7 
#define pin__e8      E, 8 
#define pin__e9      E, 9 
// #define pin__e10     E, 10
// #define pin__e11     E, 11
// #define pin__e12     E, 12
// #define pin__e13     E, 13
// #define pin__e14     E, 14
// #define pin__e15     E, 15

#define pin__f0      F, 0 
#define pin__f1      F, 1 
#define pin__f2      F, 2 
#define pin__f3      F, 3 
#define pin__f4      F, 4 
#define pin__f5      F, 5 
#define pin__f6      F, 6 
#define pin__f7      F, 7 
#define pin__f8      F, 8 
// #define pin__f9      F, 9 
// #define pin__f10     F, 10
// #define pin__f11     F, 11
#define pin__f12     F, 12
#define pin__f13     F, 13
// #define pin__f14     F, 14
// #define pin__f15     F, 15

#define pin__g0      G, 0 
#define pin__g1      G, 1 
#define pin__g2      G, 2 
#define pin__g3      G, 3 
// #define pin__g4      G, 4 
// #define pin__g5      G, 5 
#define pin__g6      G, 6 
#define pin__g7      G, 7 
#define pin__g8      G, 8 
#define pin__g9      G, 9 
// #define pin__g10     G, 10
// #define pin__g11     G, 11
#define pin__g12     G, 12
#define pin__g13     G, 13
#define pin__g14     G, 14
#define pin__g15     G, 15
