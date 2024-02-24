/*
        TARJETA DE PROGRAMACIÓN Ai-WB2-32S-Kit

                  DESCRIPCIÓN:

     Ouput_Digital_Blink_Leds_RED_GREEN_and_BLUE.                              

*/
void setup() {
  pinMode(14, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  digitalWrite(14, HIGH);
  delay(1000);

  digitalWrite(14, LOW);
  delay(1000);

  digitalWrite(17, HIGH);
  delay(2000);

  digitalWrite(17, LOW);
  delay(2000);

  digitalWrite(3, HIGH);
  delay(3000);

  digitalWrite(3, LOW);
  delay(3000);
}