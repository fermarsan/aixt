// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando M. Santa
// Date: 2024
// License: MIT
module uart

// Sets the data rate in bits per second (baud) for serial data transmission
#define uart.setup(BAUD_RATE)  Serial.begin(BAUD_RATE)