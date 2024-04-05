// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH573F)

module pin

#define pin__read_(port, ...) GPIO##port##_ReadPortPin(GPIO_Pin_##__VA_ARGS__)

#define pin__read(PIN_NAME)  pin__read_(PIN_NAME)