
void setup() {
  Serial.begin(9600);               
  pinMode(13,OUTPUT);  

}

void loop() {
  int reading = analogRead(A0);
  int temp = reading;
  if (temp > 54){
    digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
  
  Serial.println(temp);
  
}
