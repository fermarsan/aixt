// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port


//GPIOB_ModeCfg(GPIO_Pin_All, GPIO_ModeOut_PP_5mA);    Activa los pines del puerto A en el modo de salida o tambien se puede en modo de entrada 

#define port__read(PORT) GPIO##port##_ReadPort()


