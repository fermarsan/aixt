// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: TESTINDIG.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Test ports analog (Blue Pill_AIR32F103C)
//              (PC port) 


void setup() {
    pinMode(PA10, INPUT_ANALOG);//Entrada analogica asociada al PWM
   
    pinMode(PB9, PWM);//Salida analogica del PWM    
}
void loop() {
    int sensorValue = analogRead(PA10);//Variacion del PWM
    int ledFadeValue = map(sensorValue, 4095, 0, 4095, 0);
    //Amplitud del PWM
    pwmWrite(PB9, PWM);//Salida del PWM
  
}
