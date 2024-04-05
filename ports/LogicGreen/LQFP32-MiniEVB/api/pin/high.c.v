// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// pin_high puts a high value (logic 1) to a specific pin
#define pin__high(PIN_NAME)  digitalWrite(PIN_NAME, HIGH)