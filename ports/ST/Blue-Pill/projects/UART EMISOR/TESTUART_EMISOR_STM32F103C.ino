// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTUART_EMISOR_STM32F103C.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Serial Port UART functions (Blue Pill_STM32F103C)
//              (PC port) 


long Dato; //Dato como entero
char EnviaDato; //creacion enviar dato como Char

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);//velocidad en Baudios
Serial.println("Inicio de sketch - valores del potenciometro");
}

void loop() {
  Dato=analogRead(PA4);//velocidad en Baudios
  delay(100);
  Serial.println(Dato);
  if(Dato <=400){//Valor menor a 400
  Serial.write('1');//Envia dato 1 a AIR32
  }
  else if(Dato >=400 && Dato<=700){ //valores entre 400 y 700
  Serial.write('2');//Envia dato 2 a AIR32
  }
  // put your main code here, to run repeatedly:
 else {//valores mayores a  700
  Serial.write('3');//Envia dato 3 a AIR32
  }
}