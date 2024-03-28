// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTINDIG.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports analog (Blue Pill_AIR32F103C)
//              (PC port) 

const int ledPIN1 = PB2; 
const int ledPIN2 = PB10;
const int ledPIN3 = PB11;

void setup()
{
  pinMode(ledPIN1, OUTPUT);
  pinMode(ledPIN2, OUTPUT);
  pinMode(ledPIN3, OUTPUT);

}
void loop()
{

  digitalWrite(ledPIN1, HIGH);
  delay(1000);
  digitalWrite(ledPIN1, LOW);
  delay(1000);
  digitalWrite(ledPIN2, HIGH);
  delay(1000);
  digitalWrite(ledPIN2, LOW);
  delay(1000);
  digitalWrite(ledPIN3, HIGH);
  delay(1000);
  digitalWrite(ledPIN3, LOW);
  delay(1000);
  
}
