
int pinA = PB10;  // Pin para el LED A
int pinB = PB1;  // Pin para el LED B
int pinc = PA4;  // Pin para el LED C

void setup() {
  pinMode(pinA, OUTPUT); //Coniguracion salida pinA
  pinMode(pinB, OUTPUT); //Coniguracion salida pinB
  pinMode(pinc, INPUT); //Coniguracion salida pinC
}

void loop() {
 
  if (400<=analogRead(pinc)) {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  delay (100);
  }
 else{
  digitalWrite(pinB, HIGH);
  digitalWrite(pinA, LOW);
  delay (100);
 }
 
}


