const int pin1 = PB21;
const int pin2 = PB22;

void setup() {
  Serial.begin(115200);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}
void loop() {
 	Serial.println("\r\n Comunicacion UART tarjeta W801-PC:");
	Serial.println("\r\n Oprimiendo la letra Q, activa la salida  del pin1.");

  if (Serial.available() > 0) {
    char command = Serial.read();

    switch(command) {  
       case 'Q':
         digitalWrite(pin1, HIGH);
         delay(4000); 
         digitalWrite(pin1, LOW);
         delay(1000);
	break;

       default:
          digitalWrite(pin2, HIGH);
          delay(4000);
          digitalWrite(pin2, LOW);
          delay(1000); 
        break;
    }
  }
}
