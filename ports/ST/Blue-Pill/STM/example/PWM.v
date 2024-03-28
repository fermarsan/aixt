#define uart__println_1(MESSAGE)   Serial1.println(MESSAGE)
#define uart__println(MESSAGE)   Serial.println(MESSAGE)
#define uart__read_1   Serial1.read
#define uart__read   Serial.read
#define uart__ready_1   Serial1.available
#define uart__read   Serial.read
#define uart__setup_1(BAUD_RATE)   Serial1.begin(BAUD_RATE)
#define uart__setup(BAUD_RATE)   Serial.begin(BAUD_RATE)



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