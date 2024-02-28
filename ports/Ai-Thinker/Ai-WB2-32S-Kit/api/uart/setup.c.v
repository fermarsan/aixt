// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup.c.v
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: SETUP functions (Ai_Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

module uart

#define uart__setup(BAUD_RATE)   Serial.begin(BAUD_RATE)