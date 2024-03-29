// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: PWM_STM32F103C.ino
// Author: Fernando Martínez Santa - Julián Camilo Guzmán Zambrano - Juan Pablo Gonzalez Penagos
// Date: 2022-2024
// License: MIT
//
// // Description: Serial Port UART functions (Blue Pill_STM32F103C)
//              (PC port) 



void setup() {
    pinMode(PA4, INPUT_ANALOG);//Entrada analogica asociada al PWM
   
    pinMode(PA6, PWM);//Salida analogica del PWM    
}
void loop() {
    int sensorValue = analogRead(PA4);//Variacion del PWM
    int ledFadeValue = map(sensorValue, 4095, 0, 4095, 0);
    //Amplitud del PWM
    pwmWrite(PA6, PWM);//Salida del PWM
  
}