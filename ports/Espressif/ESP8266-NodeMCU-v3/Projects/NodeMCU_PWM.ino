//This example of programming is carried out by Sebastián Góngora and Brayan Gaitan 
//where it is part of the AIXT project in charge of the teacher Fernando Santa Martinez 
//derived from the NODE MCU microcontroller. 

void setup() {
  //Program the physical output pin
    pinMode(D2, OUTPUT);
}

void loop() {

  //for loop condition to increase 1-in-1  
    for (int PWM_duty = 0; PWM_duty < 1023; PWM_duty++) 
    {
  // Assigning the Loop Result to the Output Pin    
      analogWrite(D2, PWM_duty);
      delay(1);
    }
  // Wait 2 seconds  
    delay(2000);
  // Condition for exiting the loop  
    for (int PWM_duty = 1023; PWM_duty >= 0; PWM_duty--) 
    {
   // Assigning the Loop Result to the Output Pin
      analogWrite(D2, PWM_duty);
      delay(1);
    }
    delay(2000);

}