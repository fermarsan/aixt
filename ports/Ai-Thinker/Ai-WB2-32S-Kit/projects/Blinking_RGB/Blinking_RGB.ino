// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: Blinking_RGB.ino
// Author: Fernando Martínez Santa - Stiven Cortázar Cortázar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: Blinking leds RED, Green and Blue functions (Ai-Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

void setup() {
  pinMode(14, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  digitalWrite(14, HIGH);
  delay(1000);

  digitalWrite(14, LOW);
  delay(1000);

  digitalWrite(17, HIGH);
  delay(2000);

  digitalWrite(17, LOW);
  delay(2000);

  digitalWrite(3, HIGH);
  delay(3000);

  digitalWrite(3, LOW);
  delay(3000);
}