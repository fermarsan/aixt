// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PIN functions (WCH-CH582F)

module pin

#define pin__low_(port, ...) GPIO##port##_ResetBits(GPIO_Pin_##__VA_ARGS__)

#define pin__low(PIN_NAME)  pin__low_(PIN_NAME)
