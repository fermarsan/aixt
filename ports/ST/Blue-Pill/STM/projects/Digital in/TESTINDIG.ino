// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTINDIG.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports digital in (Blue Pill_STM32F103C)
//              (PC port) 

int  intPIN=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PB8, OUTPUT);//led conectado a salida PB8
  pinMode(PB9, OUTPUT);//led conectado a salida PB9
  pinMode(PA0, INPUT);//interruptor conectado a entrada PB9
}
void loop() {
  
  // put your main code here, to run repeatedly:
  if (digitalRead(PA0)==1){
    //INTERRUPTOR PRESIONADO
  digitalWrite(PB8, HIGH); //LED conectado a PB8 encendido
  digitalWrite(PB9, HIGH);  //LED conectado a PB9 apagado
  }
  else{
    //interruptor suelto
  digitalWrite(PB8, LOW); //LED conectado a PB9 encendedido
  digitalWrite(PB9,LOW); //LED conectado a PB8 apagado
  }  
}