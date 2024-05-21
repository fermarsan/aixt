// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Luis Alfredo Pinto Medina and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F886 port)
module pin

#define pin__output 0	// pin mode direction
#define pin__input  1

#define pin__a0      A, 0	// pin names
#define pin__a1      A, 1 
#define pin__a2      A, 2 
#define pin__a3      A, 3 
#define pin__a4      A, 4 
#define pin__a5      A, 5 
#define pin__a6      A, 6 
#define pin__a7      A, 7  

#define pin__b0      B, 0 
#define pin__b1      B, 1 
#define pin__b2      B, 2 
#define pin__b3      B, 3 
#define pin__b4      B, 4 
#define pin__b5      B, 5 
#define pin__b6      B, 6 
#define pin__b7      B, 7  

#define pin__c0      C, 0 
#define pin__c1      C, 1 
#define pin__c2      C, 2 
#define pin__c3      C, 3 
#define pin__c4      C, 4 
#define pin__c5      C, 5 
#define pin__c6      C, 6 
#define pin__c7      C, 7  

#define pin__e3      E, 3 