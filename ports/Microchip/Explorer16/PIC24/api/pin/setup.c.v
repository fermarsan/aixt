// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: Pin management functions (Explorer16-PIC24 port)
module pin

#define pin__setup(PIN_NAME, MODE)   PIN_NAME = MODE
