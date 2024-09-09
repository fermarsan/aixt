// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// File Name: adc.c
// Author: Javier Leon, Camilo Lucas and Fernando M. Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
//              (CY8CKIT-049-42XX)

#define pin.high(pin_name)   pin.write(pin_name, 1)
#define pin.low(pin_name)    pin.write(pin_name, 0)

#define pin.write(pin_name, value)  pin_name##_Write(value)
#define pin.read(pin_name)  pin_name##_Read()
