// Project Name: Aixt, https://github.com/fermarsan/aixt.git

// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Port management functions
//              (PIC16F873A port)

module port

@[inline]
pub fn port.read(PORT_NAME) {
C.PORT ## PORT_NAME
}