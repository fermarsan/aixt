// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
module uart

// Get the number of bytes (characters) available for reading from the serial port
#define uart.any()  Serial.available()  