// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa & Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH573F)

module pin

#define pin__high_(port, ...) GPIO##port##_SetBits(GPIO_Pin_##__VA_ARGS__)

#define pin__high(PIN_NAME)  pin__high_(PIN_NAME)
