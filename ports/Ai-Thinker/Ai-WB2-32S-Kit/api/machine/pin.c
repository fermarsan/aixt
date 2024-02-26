// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin.c
// Author: Fernando Martínez Santa - Stiven Cortazar Cortazar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: PIN functions (Ai_Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

#define pin_setup(PIN_NAME, MODE)    pinMode(PIN_NAME, MODE)

#define pin_high(PIN_NAME)   digitalWrite(PIN_NAME, HIGH)

#define pin_low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)

#define out OUTPUT

#define in INPUT_PULLUP

#define pin_read(PIN_NAME)   digitalRead(PIN_NAME)