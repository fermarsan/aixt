// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: Blinking_R.ino
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: Blinking led RED functions (Ai-Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

void setup() {
  pinMode(14, OUTPUT);
}

void loop() {
  digitalWrite(14, HIGH);
  delay(1000);

  digitalWrite(14, LOW);
  delay(1000);
}