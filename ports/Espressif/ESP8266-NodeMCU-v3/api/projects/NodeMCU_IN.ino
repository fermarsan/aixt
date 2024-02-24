//This example of programming is carried out by Sebastián Góngora and Brayan Gaitan 
//where it is part of the AIXT project in charge of the teacher Fernando Santa Martinez 
//derived from the NODE MCU microcontroller. 

// Include the necessary library
#include <Arduino.h>

//Defines the type of input variable fitted to the physical connection of the microcontroller

const int pinEntrada = D1;  

void setup() {
  // Attach the variable as an input pin
  pinMode(pinEntrada, INPUT);
  //Performs serial communication to be observed on the serial monitor
  Serial.begin(115200); 
}

void loop() {
  // Reading the input pin
  int estadoPin = digitalRead(pinEntrada);

  // Print the input pin on the serial monitor
  Serial.print("Estado del Pin de Entrada: ");
  Serial.println(estadoPin);
  //Starts rereading in 1 second
  delay(1000);  
}
