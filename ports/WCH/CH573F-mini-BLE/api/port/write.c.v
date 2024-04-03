// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2024
// Description: PORT functions (WCH-CH573F)

module port


//GPIOB_ModeCfg(GPIO_Pin_All, GPIO_ModeOut_PP_5mA);    Activa los pines del puerto A en el modo de salida o tambien se puede en modo de entrada 

#define port__write(PORT, BITS) GPIO##PORT##_SetBits(BITS)