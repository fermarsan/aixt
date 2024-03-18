// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTINDIG.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports analog (Blue Pill_STM32F103C)
//              (PC port) 

int pinA = PA5;  // Pin para el LED A
int pinB = PA6;  // Pin para el LED B

void setup() {
  pinMode(pinA, OUTPUT); //Coniguracion salida pinA
  pinMode(pinB, OUTPUT); //Coniguracion salida pinB
}

void loop() {
 
  analogRead(pinA);//salida PA4 conectada a un LED 
  analogRead(pinB);//salida PA5 conectada a un LED 
  Serial.println(9600);//velocidad en baudios soportado   
 //por la tarjeta
}