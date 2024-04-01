// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH582F)

module pin

#define a8 A, 8

#define pin__read_(port, ...) GPIO##port##_ReadPortPin(GPIO_Pin_##__VA_ARGS__)

#define pin__read(PIN_NAME)  pin__read_(PIN_NAME)
