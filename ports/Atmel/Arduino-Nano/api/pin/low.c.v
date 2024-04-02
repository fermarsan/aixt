// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fabián A. Rojas Acosta, Alberto Pinzón Valero and Fernando Martínez Santa
// Date: 2024
// License: MIT
module pin

// pin_low puts a low value (logic 0) to a specific pin
#define pin__low(PIN_NAME)  digitalWrite(PIN_NAME, LOW)