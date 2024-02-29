// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: println_1.c.v
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: PRINTLN functions (Ai_Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

module uart

#define uart__println_1(MESSAGE)   Serial1.println(MESSAGE)