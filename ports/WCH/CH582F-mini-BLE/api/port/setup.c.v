// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port

// Existe el puerto A y el puerto B
#define a A  

//GPIOA_ModeCfg(GPIO_Pin_All, GPIO_ModeOut_PP_5mA);    Activa los pines del puerto A en el modo de salida o tambien se puede en modo de entrada 

#define port__setup_(port, pin, ...) GPIO##port##_ModeCfg(GPIO_Pin_All,##__VA_ARGS__)

#define port__setup(PORT_NAME, PIN_MODE)  port__setup_(PORT_NAME, PIN_MODE)
	