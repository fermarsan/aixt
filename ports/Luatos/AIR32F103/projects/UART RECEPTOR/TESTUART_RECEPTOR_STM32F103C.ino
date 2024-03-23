// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTINDIG.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports analog (Blue Pill_AIR32F103C)
//              (PC port) 

int LEDPinI=PB13;//LEDPinI asignado al pin PB13
int LEDPinII=PB14;//LEDPinII asignado al pin PB14
int LEDPinIII=PB15;//LEDPinIII asignado al pin PB15
int RecibeDato;

void setup() {
  // put your setup code here, to run once:
pinMode(LEDPinI,OUTPUT);//LEDPinI asignado
//como salida
pinMode(LEDPinII,OUTPUT);/LEDPinII asignado
//como salida
pinMode(LEDPinIII,OUTPUT);//LEDPinIII asignado
//como salida
Serial.begin(9600);//Velocidad en Baudios
}
void loop() {
  if(Serial.available()>0){//Comparacion serial
  //Mayor a cero
    RecibeDato=Serial.read();//Recibe dato AIR32
    delay(100);//Reset 100 ms
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
  // put your main code here, to run repeatedly:

}
