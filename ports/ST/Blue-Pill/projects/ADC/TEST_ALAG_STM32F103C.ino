
int pinA = PA5;  // Pin para el LED A
int pinB = PA6;  // Pin para el LED B
int pinc = PA4;  // Pin para el LED C

void setup() {
  pinMode(pinA, OUTPUT); //Coniguracion salida pinA
  pinMode(pinB, OUTPUT); //Coniguracion salida pinB
  pinMode(pinc, INPUT); //Coniguracion salida pinC
}

void loop() {
 
  if (500<=analogRead(pinc)) {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  delay (100);
  }
 else{
  digitalWrite(pinB, HIGH);
  digitalWrite(pinA, LOW);
  delay (100);
 }
  Serial.println(9600);//velocidad en baudios soportado   
 //por la tarjeta
}


