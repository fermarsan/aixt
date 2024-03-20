// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTINDIG.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports analog (Blue Pill_AIR32F103C)
//              (PC port) 



const int ledPIN1 = PA3; //salida digital al led PA3
const int ledPIN2 = PB0; //salida digital al led PB0
const int intPIN = PA0; //entrada digital al led PA0

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPIN1, OUTPUT);//led conectado a salida PA3
  pinMode(ledPIN2, OUTPUT);//led conectado a salida PB0
  pinMode(intPIN, INPUT);//interruptor conectado a entrada PA0
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(intPIN)==LOW){
    //INTERRUPTOR PRESIONADO
  digitalWrite(ledPIN1, LOW); //LED conectado a PA3  
  digitalWrite(ledPIN2, HIGH);  //LED conectado a PB0
  }
  else{
    //interruptor suelto
  digitalWrite(ledPIN1, HIGH); //LED conectado a PBA3
  digitalWrite(ledPIN2, LOW);  //LED conectado a PB0
  
  }  
 delay (1);
}

