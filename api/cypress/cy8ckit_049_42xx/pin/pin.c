// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
//
// ## Description
// pin functions (CY8CKIT-049-42XX)

#define PIN_WRITE(PIN_NAME, VAL)    PIN_NAME##_Write(VAL)
#define PIN_HIGH(id u8)   PIN_NAME##_Write(1)
#define PIN_LOW(id u8)   PIN_NAME##_Write(0)
#define PIN_READ(id u8)    PIN_NAME##_Read()
