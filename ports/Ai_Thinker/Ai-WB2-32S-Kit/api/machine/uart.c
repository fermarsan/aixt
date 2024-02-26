// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart.c
// Author: Fernando Martínez Santa - Stiven Cortazar Cortazar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: UART functions (Ai_Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

#define uart0_setup(baud_rate)   Serial.begin(baud_rate)
#define uart_setup(baud_rate)   Serial.begin(baud_rate)

#define uart0_ready()  Serial.available()
#define uart_ready()   Serial.available()

#define uart0_read()   Serial.read()
#define uart_read()   Serial.read()

#define println(message)   Serial.println(message)