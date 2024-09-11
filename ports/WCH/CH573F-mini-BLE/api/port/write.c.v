// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port

#define port.write_(PORT, BITS) GPIO##PORT##_SetBits(BITS)

#define port.write(PORT, BITS)  port.write_(PORT, BITS)
