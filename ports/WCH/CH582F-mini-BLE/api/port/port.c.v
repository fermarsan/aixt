// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH582F)

module port

#include "CH58x_common.h"

// out macro defines the pin output mode --> Se podria cambiar por port__output y port__input ?
#define pin__output    GPIO_ModeOut_PP_5mA      
//Tambien esta el modo GPIO_ModeOut_PP_20mA

// in macro defines the pin input mode --> Se podria cambiar por port__output y port__input ?
#define pin__input     GPIO_ModeIN_PD 	     
//Tambien esta el modo GPIO_ModeIN_PU y GPIO_ModeIN_Floating