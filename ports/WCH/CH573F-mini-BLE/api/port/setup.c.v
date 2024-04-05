// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port


//GPIOA_ModeCfg(GPIO_Pin_All, GPIO_ModeOut_PP_5mA);    Activa los pines del puerto A en el modo de salida o tambien se puede en modo de entrada 

#define port__setup(PORT, BITS, MODE) GPIO##PORT##_ModeCfg(BITS, MODE)

	