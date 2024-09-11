#define uart.println_1(MESSAGE)   Serial1.println(MESSAGE)
#define uart.println(MESSAGE)   Serial.println(MESSAGE)
#define uart.read_1   Serial1.read
#define uart.read   Serial.read
#define uart.ready_1   Serial1.available
#define uart.read   Serial.read
#define uart.setup_1(BAUD_RATE)   Serial1.begin(BAUD_RATE)
#define uart.setup(BAUD_RATE)   Serial.begin(BAUD_RATE)



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