// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: setup_1.c.v
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: SETUP_1 functions (Ai_Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

module uart

#define uart__setup_1(BAUD_RATE)   Serial1.begin(BAUD_RATE)