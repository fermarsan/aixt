// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando Martínez Santa
// Date: 2024
// License: MIT
//
// Description: Seconds delay function
//              (PIC16F676 port)
module time

#define time__sleep(TIME)    __delay_ms(TIME*1024)