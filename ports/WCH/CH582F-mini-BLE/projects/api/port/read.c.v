// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH582F)

module port

#define port.read(PORT) GPIO##PORT##_ReadPort()


