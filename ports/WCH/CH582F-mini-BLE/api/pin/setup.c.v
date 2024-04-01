// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH582F)

module pin

#define a8 A, 8

#define pin__setup_(port, pin, ...) GPIO##port##_ModeCfg(GPIO_Pin_##pin, ##__VA_ARGS__)

#define pin__setup(PIN_NAME, PIN_MODE)  pin__setup_(PIN_NAME, PIN_MODE)
