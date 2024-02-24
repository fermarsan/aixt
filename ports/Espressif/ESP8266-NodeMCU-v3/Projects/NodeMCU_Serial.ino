

//This example of programming is carried out by Sebastián Góngora and Brayan Gaitan 
//where it is part of the AIXT project in charge of the teacher Fernando Santa Martinez 
//derived from the NODE MCU microcontroller. 
//

//This example of programming is carried out by Sebastián Góngora and Brayan Gaitan 
//where it is part of the AIXT project in charge of the teacher Fernando Santa Martinez 
//derived from the NODE MCU microcontroller. 
//This example shows how to program the microcontroller's serial communication

// Include the necessary library
#include <Arduino.h>

// Define the type of variable
const int pinEntrada = D1;  
const int pinSalida = D2;  


void setup() {
  // Attach the variable as an input pin
  pinMode(pinEntrada,INPUT); 
  pinMode(pinSalida, OUTPUT);
  //Performs serial communication to be observed on the serial monitor
  Serial.begin(115200);  
}

void loop() {
  // Input PIN Status
  int estadoPin = digitalRead(pinEntrada); 
  
  //Input PIN Condition
  if(estadoPin == 0){
  // Print the input pin on the serial monitor 
    Serial.print("Estado del Pin de Entrada: LED ON \n");
  //Turn on the LED  
    digitalWrite(pinSalida, HIGH);
    //Starts rereading in 1 second
    delay(1000);  
    // Turn off the LED
    digitalWrite(pinSalida, LOW);
    ////Starts rereading in 1 second
    delay(1000);  
  }
}
