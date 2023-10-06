// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Javier Leon, Camilo Lucas and Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Pin management functions
//              (CY8CKIT-145-40XX)

#define pin_high(PIN)   pin_write(PIN, 1)
#define pin_low(PIN)    pin_write(PIN, 0)

void pin_write(int pin_name, int value) {  
    switch (pin_name)
    {
    case led1:
        led1_Write(!value);
        break;
    case led4:
        led4_Write(!value);
        break;
    case led5:
        led5_Write(!value);
        break;
    case led6:
        led6_Write(!value);
        break;
    case led7:
        led7_Write(!value);
        break;
    case led8:
        led8_Write(!value);
        break;
    case led9:
        led9_Write(!value);
        break;
    case led10:
        led10_Write(!value);
        break;
    case led11:
        led11_Write(!value);
        break;
    case do0:
        do0_Write(!value);
        break;
    case do1:
        do1_Write(!value);
        break;
    case do2:
        do2_Write(!value);
        break;
    default:
        break;
    }
}

int pin_read(int pin_name) {   
    switch (pin_name)
    {
    case sw2:
        return sw2_Read();
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
    default:
        break;
    }
}