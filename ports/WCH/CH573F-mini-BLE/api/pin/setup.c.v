// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH573F)

module pin

#define pin.setup_(port, pin, ...) GPIO##port##_ModeCfg(GPIO_Pin_##pin, ##__VA_ARGS__)

#define pin.setup(PIN_NAME, PIN_MODE)  pin.setup_(PIN_NAME, PIN_MODE)
