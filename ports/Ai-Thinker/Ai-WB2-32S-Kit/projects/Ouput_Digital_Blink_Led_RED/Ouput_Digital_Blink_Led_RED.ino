/*
        TARJETA DE PROGRAMACIÓN Ai-WB2-32S-Kit

                  DESCRIPCIÓN:

          Ouput_Digital_Blink_Led_RED                             

*/
void setup() {
  pinMode(14, OUTPUT);
}

void loop() {
  digitalWrite(14, HIGH);
  delay(1000);

  digitalWrite(14, LOW);
  delay(1000);
}