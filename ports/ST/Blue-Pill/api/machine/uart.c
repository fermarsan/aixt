// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart.c
// Author: Fernando Martínez Santa - Julian Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
<<<<<<< HEAD
// // Description: UART functions (Blue Pill_STM32F103C)
//              (PC port) 

#define uart0_setup(baud_rate)   Serial.begin(baud_rate)
#define uart_setup(baud_rate)   Serial.begin(baud_rate)

#define uart0_ready()  Serial.available()
#define uart_ready()   Serial.available()

#define uart0_read()   Serial.read()
#define uart_read()   Serial.read()
=======
// // Description: UART functions (Blue-Pill)
//              (PC port) 

#define uart0__setup(baud_rate)   Serial.begin(baud_rate)
#define uart__setup(baud_rate)   Serial.begin(baud_rate)

#define uart0__ready()  Serial.available()
#define uart__ready()   Serial.available()

#define uart0__read()   Serial.read()
#define uart__read()   Serial.read()

#define uart__Write(VALUE)    Serial.write(VALUE)
>>>>>>> d4993b91b137dd499e1bd8c91cce3c82d74f8e77

#define println(message)   Serial.println(message)