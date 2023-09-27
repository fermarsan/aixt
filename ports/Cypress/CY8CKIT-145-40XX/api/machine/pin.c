// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: sleep_us.c
// Author: Fernando Martínez Santa
// Date: 2022-2023
// License: MIT
//
// Description: Pin management functions
//              (Explorer16-PIC24 port)

#define pin_high(PIN)   pin_write(PIN, 0)
#define pin_low(PIN)    pin_write(PIN, 1)

void pin_write(int pin_name, int value) {  
    switch (pin_name)
    {
    case led1:
        led1_Write(!value);
        break;
    case led4:
        led4_Write(!value);
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
    default:
        break;
    }
}