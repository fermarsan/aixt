@[inline]
pub fn println_1(MESSAGE) {
	C.Serial1.println(MESSAGE)
}
@[inline]
pub fn println(MESSAGE) {
	C.Serial.println(MESSAGE)
}
@[inline]
pub fn read_1() {
	C.Serial1.read()
}
@[inline]
pub fn read() {
	C.Serial.read()
}
@[inline]
pub fn ready_1() {
	C.Serial1.available()
}
@[inline]
pub fn read() {
	C.Serial.read()
}
@[inline]
pub fn setup_1(BAUD_RATE) {
	C.Serial1.begin(BAUD_RATE)
}
@[inline]
pub fn setup(BAUD_RATE) {
	C.Serial.begin(BAUD_RATE)
}



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