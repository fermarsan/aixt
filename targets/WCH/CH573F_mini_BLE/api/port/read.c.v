// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cristian Garzón
// Date: 2023 - 2024
// Description: PORT functions (WCH-CH573F)

module port

@[inline]
pub fn read(PORT) {
C.GPIO##PORT##_ReadPort()
}


