// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: ONOFF_STM32F103C.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: TEST LEDS(Blue Pill_STM32F103C)
//              (PC port) 

const int ledPIN = PC13;  // Enciende apaga LED
//TARJETA STM32C103
void setup()
{
  pinMode(ledPIN, OUTPUT);
}
void loop()
{
  digitalWrite(ledPIN, HIGH);//ENCIENDE EL LED PC13
  delay(1000);//PRENDE 1 s
  digitalWrite(ledPIN, LOW);//APAGA LED PC13
  delay(1000);//APAGA 1s
}