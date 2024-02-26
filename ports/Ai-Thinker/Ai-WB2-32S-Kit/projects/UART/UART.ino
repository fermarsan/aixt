/*
        TARJETA DE PROGRAMACIÓN Ai-WB2-32S-Kit

                  DESCRIPCIÓN:

              Serial_Port_(UART)                              

*/

void setup() {
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  Serial.println("\r\n Este programa realiza unas funciones establecidas:");
  Serial.println("\r\n Oprimiendo la letra A, activa la salida  del pin GPIO4.");
  Serial.println("\r\n Oprimiendo la letra B, activa la salida  del pin GPIO5.");
  Serial.println("\r\n El piloto (led) Rojo indica que esta esperando instrucciones.");
  Serial.println("\r\n Esperando instrucciones: \r\n");

  digitalWrite(12, HIGH);
  delay(500);

  digitalWrite(12, LOW);
  delay(500);
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch(command) {

      case 'A':
        Serial.println("\r\n Comando A recibido. \r\n");
        Serial.println("\r\n Realizando acción A. \r\n");
        digitalWrite(4, HIGH);
        delay(5000);

        digitalWrite(4, LOW);
        delay(1000);
        Serial.println("\r\n Proceso A finalizado. \r\n");
      break;

      case 'B':
        Serial.println("\r\n Comando B recibido. \r\n");
        Serial.println("\r\n Realizando acción B. \r\n");
        digitalWrite(5, HIGH);
        delay(5000);

        digitalWrite(5, LOW);
        delay(1000);
        Serial.println("\r\n Proceso B finalizado. \r\n");
      break;

      default:
        digitalWrite(12, HIGH);
        delay(1000);

        digitalWrite(12, LOW);
        delay(1000);
      break;
    }
  }
}