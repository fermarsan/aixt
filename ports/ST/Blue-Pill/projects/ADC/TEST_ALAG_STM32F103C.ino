<<<<<<< HEAD
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
=======

int pinA = PA5;  // Pin para el LED A
int pinB = PA6;  // Pin para el LED B
int pinc = PA4;  // Pin para el LED C
>>>>>>> d4993b91b137dd499e1bd8c91cce3c82d74f8e77

void setup() {
  pinMode(pinA, OUTPUT); //Coniguracion salida pinA
  pinMode(pinB, OUTPUT); //Coniguracion salida pinB
<<<<<<< HEAD
=======
  pinMode(pinc, INPUT); //Coniguracion salida pinC
>>>>>>> d4993b91b137dd499e1bd8c91cce3c82d74f8e77
}

void loop() {
 
<<<<<<< HEAD
  analogRead(pinA);//salida PA4 conectada a un LED 
  analogRead(pinB);//salida PA5 conectada a un LED 
  Serial.println(9600);//velocidad en baudios soportado   
 //por la tarjeta
}
=======
  if (500<=analogRead(pinc)) {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  delay (100);
  }
 else{
  digitalWrite(pinB, HIGH);
  digitalWrite(pinA, LOW);
  delay (100);
 }
  Serial.println(9600);//velocidad en baudios soportado   
 //por la tarjeta
}


>>>>>>> d4993b91b137dd499e1bd8c91cce3c82d74f8e77
