//This example of programming is carried out by Sebastián Góngora and Brayan Gaitan 
//where it is part of the AIXT project in charge of the teacher Fernando Santa Martinez 
//derived from the NODE MCU microcontroller. 
//This example shows how to program the A0 pin of the microcontroller to make use of the ADC.

void setup() {
  // starts with Serial communication at 9600 baud
  Serial.begin(9600);
}

void loop() {
  //Define Variable Types
  int sensorValue
  float voltage
    //pin reading to program the ADC 
   sensorValue = analogRead(A0); 
    //Converting Pin Value A0 to Digital Value
  voltage = sensorValue * (3.3 / 1023.0);  

  
 //Prints the serial port value on the screen
  Serial.print("ADC= ");
  Serial.print(sensorValue);
  Serial.print("  Voltage= ");
  Serial.println(voltage); 
  //Text Printing Speed
  delay(100);  
}
