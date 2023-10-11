// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Javier Leon, Camilo Lucas and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Pin management functions
//              (CY8CKIT-049-42XX)

#define pin_high(PIN)   pin_write(PIN, 1)
#define pin_low(PIN)    pin_write(PIN, 0)

void pin_write(int pin_name, int value) {  
    switch (pin_name)
    {
    case led1:
        led1_Write(value);
        break;
    case do1:
        do1_Write(value);
        break;
    case do2:
        do2_Write(value);
        break;
    case do3:
        do3_Write(value);
        break;
    case do4:
        do4_Write(value);
        break;
    case do5:
        do5_Write(value);
        break;
    case do6:
        do6_Write(value);
        break;
    case do7:
        do7_Write(value);
        break;
    case do8:
        do8_Write(value);
        break;
    case do9:
        do9_Write(value);
        break;
    case do10:
        do10_Write(value);
        break;
    default:
        break;
    }
}

int pin_read(int pin_name) {   
    switch (pin_name)
    {
    case sw1:
        return sw1_Read();
        break;
    case di0:
        return di0_Read();
        break;
    case di1:
        return di1_Read();
        break;
    case di2:
        return di2_Read();
        break;
    case di3:
        return di3_Read();
        break;
    case di4:
        return di4_Read();
        break;
    case di5:
        return di5_Read();
        break;
    case di6:
        return di6_Read();
        break;
    case di7:
        return di7_Read();
        break;
    case di8:
        return di8_Read();
        break;
    case di9:
        return di9_Read();
        break;
    case di10:
        return di10_Read();
        break;
    default:
        break;
    }
}