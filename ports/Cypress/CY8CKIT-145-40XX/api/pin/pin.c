// Project Name: Aixt https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
// License: MIT
//
// // Description: pin functions (CY8CKIT-145-40XX)

#define PIN_WRITE(PIN_NAME, VAL)    PIN_NAME##_Write(VAL)
#define PIN_HIGH(PIN_NAME)   PIN_NAME##_Write(1)
#define PIN_LOW(PIN_NAME)   PIN_NAME##_Write(0)
#define PIN_READ(PIN_NAME)    PIN_NAME##_Read()
