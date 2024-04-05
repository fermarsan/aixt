// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH573F)

module pin

#include "CH57x_common.h"

//Existe el puerto A pines (4,5,8,9 10...15) y el puerto B pines (4,7,10...15,22,23)
#define a8 A, 8

// out macro defines the pin output mode
#define pin__output    GPIO_ModeOut_PP_5mA      
//Tambien esta el modo GPIO_ModeOut_PP_20mA

// in macro defines the pin input mode
#define pin__input     GPIO_ModeIN_PD 	     
//Tambien esta el modo GPIO_ModeIN_PU y GPIO_ModeIN_Floating
 
 fn init() {

}