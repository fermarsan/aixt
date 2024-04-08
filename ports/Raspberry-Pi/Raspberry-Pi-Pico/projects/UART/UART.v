import uart

  Serial.begin(9600)

for {
  
  if(Serial.available())
  {
    a = Serial.read()
    Serial.println(a)
  }
}
