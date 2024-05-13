int a1 = PB21;
int a2 = PB22;
int a3 = PB23;
int a4 = PB24;


void setup() {
  // put your setup code here, to run once:
pinMode(a1,INPUT);  
pinMode(a2,OUTPUT);
pinMode(a3,OUTPUT);
pinMode(a4,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(a1)==1){
  digitalWrite(a2,LOW);
  digitalWrite(a3,HIGH);
  digitalWrite(a4,LOW);
  delay (100);
}
if (digitalRead(a1)==0){
  digitalWrite(a2,HIGH);
  digitalWrite(a3,LOW);
  digitalWrite(a4,HIGH);
  delay (100); 
}
}
