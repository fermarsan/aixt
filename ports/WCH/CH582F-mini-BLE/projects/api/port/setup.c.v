// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH582F)

module port

#define port.setup_(PORT, BITS, MODE) GPIO##PORT##_ModeCfg(BITS, MODE)

#define port.setup(PORT, BITS, MODE)  port.setup_(PORT, BITS, MODE)

	