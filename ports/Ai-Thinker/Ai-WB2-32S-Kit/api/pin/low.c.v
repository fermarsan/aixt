// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: low.c.v
// Author: Fernando Martínez Santa - Stiven Cortazar Cortazar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: LOW functions (Ai_Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

module pin

#define pin__low(PIN_NAME)   digitalWrite(PIN_NAME, LOW)