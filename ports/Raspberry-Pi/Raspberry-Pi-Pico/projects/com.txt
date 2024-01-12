void setup() {
  
  Serial.begin(9600);



}

void loop() {
  
  if(Serial.available()){
    char a = Serial.read();
    Serial.println(a);

  }

}