//This example of programming is carried out by Sebastián Góngora and Brayan Gaitan 
//where it is part of the AIXT project in charge of the teacher Fernando Santa Martinez 
//derived from the NODE MCU microcontroller. 
//This example shows how to program the A0 pin of the microcontroller to make use of the ADC.


// Includes the necessary bibliography
#include <Arduino.h>

//Define the type of PIN variable
const int pinSalida = D2;  // Puedes ajustar el número del pin según la conexión física

void setup() {
  // Define the variable as output
  pinMode(pinSalida, OUTPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(pinSalida, HIGH);
  // Wait 1 second
  delay(1000);
  

  // Turns off LED
  digitalWrite(pinSalida, LOW);
  //Wait 1 second
  delay(1000);  
}
