// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTUART_RECEPTOR_AIR32F103C.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Serial Port UART functions (Blue Pill_STM32F103C)
//              (PC port) 


int LEDPinI=PA4;//LEDPinI asignado al pin PA4
int LEDPinII=PA6;//LEDPinI asignado al pin PA6
int LEDPinIII=PA5;//LEDPinI asignado al pin PA5
int RecibeDato;
void setup() {
pinMode(LEDPinI,OUTPUT);//LEDPinI asignado
//como salida
pinMode(LEDPinII,OUTPUT);//LEDPinII asignado
//como salida
pinMode(LEDPinIII,OUTPUT);//LEDPinIII asignado
//como salida
Serial.begin(9600);//Velocidad en Baudios
}
void loop() {
  if(Serial.available()>0){//Comparacion serial
  //Mayor a cero
    RecibeDato=Serial.read();//Recibe dato STM32
    delay(100); //Reset 100 ms
  }
  switch(RecibeDato){
    case '1':
    digitalWrite(LEDPinI,HIGH);//LEDPinI encendido
    digitalWrite(LEDPinII,LOW);//LEDPinII apagado
    digitalWrite(LEDPinIII,LOW);//LEDPinIII apagado
    break;
    case '2':
    digitalWrite(LEDPinI,LOW);//LEDPinI apagado
    digitalWrite(LEDPinII,HIGH);//LEDPinII encendido
    digitalWrite(LEDPinIII,LOW);//LEDPinIII apagado
    break;
    case '3':
    digitalWrite(LEDPinI,LOW);//LEDPinI apagado
    digitalWrite(LEDPinII,LOW);//LEDPinII apagado
    digitalWrite(LEDPinIII,HIGH);//LEDPinIII encendido
    break;
    case '0':
    digitalWrite(LEDPinI,LOW);//LEDPinI apagado
    digitalWrite(LEDPinII,LOW);//LEDPinII apagado
    digitalWrite(LEDPinIII,LOW);//LEDPinIII apagado
    break;
  }
}
