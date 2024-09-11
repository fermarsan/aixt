// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH582F)

module pin

#define pin.read_(port, ...) GPIO##port##_ReadPortPin(GPIO_Pin_##__VA_ARGS__)

#define pin.read(PIN_NAME)  pin.read_(PIN_NAME)