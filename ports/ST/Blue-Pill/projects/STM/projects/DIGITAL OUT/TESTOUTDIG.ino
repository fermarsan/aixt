// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTOUTDIG.ino
// Author: Fernando Martínez Santa - Julian Camilo Guzman Zambrano- Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports digital in (Blue Pill_STM32F103C)
//              (PC port) 

int const ledPIN1=PB12; 
int const ledPIN2=PB13; 
int const ledPIN3=PB14; 
int const ledPIN4=PB15; 
int const ledPIN5=PA8; 
int const ledPIN6=PA9; 
int const ledPIN7=PA10; 
int const ledPIN8=PA11; 
int const ledPIN9=PA12; 
int const ledPIN10=PA13; 
int const ledPIN11=PA14;
int const ledPIN12=PA15; 
int const ledPIN13=PB3; 
int const ledPIN14=PB4; 
int const ledPIN15=PB5; 
int const ledPIN16=PB6; 
int const ledPIN17=PB7; 
int const ledPIN18=PB8; 
int const ledPIN19=PB9; 
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPIN1, OUTPUT);
  pinMode(ledPIN2, OUTPUT);
  pinMode(ledPIN3, OUTPUT);
  pinMode(ledPIN4, OUTPUT);
  pinMode(ledPIN5, OUTPUT);
  pinMode(ledPIN6, OUTPUT);
  pinMode(ledPIN7, OUTPUT);
  pinMode(ledPIN8, OUTPUT);
  pinMode(ledPIN9, OUTPUT);
  pinMode(ledPIN10, OUTPUT);
  pinMode(ledPIN11, OUTPUT);
  pinMode(ledPIN12, OUTPUT);
   pinMode(ledPIN3, OUTPUT);
  pinMode(ledPIN14, OUTPUT);
  pinMode(ledPIN15, OUTPUT);
  pinMode(ledPIN16, OUTPUT);
  pinMode(ledPIN17, OUTPUT);
  pinMode(ledPIN18, OUTPUT);
  pinMode(ledPIN19, OUTPUT);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPIN1, HIGH);
  digitalWrite(ledPIN2, HIGH);
  digitalWrite(ledPIN3, HIGH);
  digitalWrite(ledPIN4, HIGH);
  digitalWrite(ledPIN5, HIGH);
  digitalWrite(ledPIN6, HIGH);
  digitalWrite(ledPIN7, HIGH);
  digitalWrite(ledPIN8, HIGH);
  digitalWrite(ledPIN9, HIGH);
  digitalWrite(ledPIN10, HIGH);
  digitalWrite(ledPIN11, HIGH);
  digitalWrite(ledPIN12, HIGH);
  digitalWrite(ledPIN13, HIGH);
  digitalWrite(ledPIN14, HIGH);
  digitalWrite(ledPIN15, HIGH);
  digitalWrite(ledPIN16, HIGH);
  digitalWrite(ledPIN17, HIGH);
  digitalWrite(ledPIN18, HIGH);
  digitalWrite(ledPIN19, HIGH);
}