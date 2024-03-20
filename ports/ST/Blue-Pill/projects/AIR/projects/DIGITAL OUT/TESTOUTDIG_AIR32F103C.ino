// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTINDIG.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports analog (Blue Pill_AIR32F103C)
//              (PC port) 


int const ledPIN1=PA0;//salida digital LED PA0
int const ledPIN2=PA1;//salida digital LED PA1
int const ledPIN3=PB9;//salida digital LED PB9 
int const ledPIN4=PB8;//salida digital LED PB8
int const ledPIN5=PA2;//salida digital LED PA2
int const ledPIN6=PA3;//salida digital LED PA3
int const ledPIN7=PA4;//salida digital LED PA4
int const ledPIN8=PA6;//salida digital LED PA6
int const ledPIN9=PA7;//salida digital LED PA7
int const ledPIN10=PA5;//salida digital LED PA5
int const ledPIN11=PB0;//salida digital LED PB0
int const ledPIN12=PB1;//salida digital LED PB1
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPIN1, OUTPUT);//ASIGNACION ledPIN1 como salida
  pinMode(ledPIN2, OUTPUT);//ASIGNACION ledPIN2 como salida
  pinMode(ledPIN3, OUTPUT);//ASIGNACION ledPIN3 como salida
  pinMode(ledPIN4, OUTPUT);//ASIGNACION ledPIN4 como salida
  pinMode(ledPIN5, OUTPUT);//ASIGNACION ledPIN5 como salida
  pinMode(ledPIN6, OUTPUT);//ASIGNACION ledPIN6 como salida
  pinMode(ledPIN7, OUTPUT);//ASIGNACION ledPIN7 como salida
  pinMode(ledPIN8, OUTPUT);//ASIGNACION ledPIN8 como salida
  pinMode(ledPIN9, OUTPUT);//ASIGNACION ledPIN9 como salida
  pinMode(ledPIN10, OUTPUT);//ASIGNACION ledPIN10 como salida
  pinMode(ledPIN11, OUTPUT);//ASIGNACION ledPIN11 como salida
  pinMode(ledPIN12, OUTPUT);//ASIGNACION ledPIN12 como salida
  
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPIN1, HIGH);//enciende ledPIN1 
  digitalWrite(ledPIN2, HIGH);//enciende ledPIN2
  digitalWrite(ledPIN3, HIGH);//enciende ledPIN3
  digitalWrite(ledPIN4, HIGH);//enciende ledPIN4
  digitalWrite(ledPIN5, HIGH);//enciende ledPIN5
  digitalWrite(ledPIN6, HIGH);//enciende ledPIN6
  digitalWrite(ledPIN7, HIGH);//enciende ledPIN7
  digitalWrite(ledPIN8, HIGH);//enciende ledPIN8
  digitalWrite(ledPIN9, HIGH);//enciende ledPIN9
  digitalWrite(ledPIN10, HIGH);//enciende ledPIN10
  digitalWrite(ledPIN11, HIGH);//enciende ledPIN11
  digitalWrite(ledPIN12, HIGH);//enciende ledPIN12
}