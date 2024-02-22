// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2022-2024
// License: MIT
//
// Description: Pin management functions (Explorer16-PIC24 port)
module pin

#include <p24FJ128GA010.h>

// out macro defines the pin output mode
#define pin__out	0

// in macro defines the pin input mode
#define pin__in		1