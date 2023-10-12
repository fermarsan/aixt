// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: adc.c
// Author: Javier Leon, Camilo Lucas and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: This is a module to emulate ADC inputs in console.
//              (CY8CKIT-049-42XX)

#define pin_high(pin_name)   pin_write(pin_name, 1)
#define pin_low(pin_name)    pin_write(pin_name, 0)

#define pin_write(pin_name, value)  pin_name##_Write(value)
#define pin_read(pin_name)  pin_name##_Read()
