// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH582F)

module pin

#define a4  A, 4
#define a5  A, 5
#define a8  A, 8
#define a9  A, 9
#define a10 A, 10
#define a11 A, 11
#define a12 A, 12
#define a13 A, 13
#define a14 A, 14
#define a15 A, 15
#define b4  B, 4
#define b7  B, 7
#define b10 B, 10
#define b11 B, 11
#define b12 B, 12
#define b13 B, 13
#define b14 B, 14
#define b15 B, 15
#define b22 B, 22
#define b23 B, 23

// out macro defines the pin output mode
#define output    		GPIO_ModeOut_PP_5mA      
//Tambien esta el modo GPIO_ModeOut_PP_20mA

// in macro defines the pin input mode
#define input     		GPIO_ModeIN_Floating
#define in_pullup		GPIO_ModeIN_PU
const in_pulldown = C.GPIO_ModeIN_PD
