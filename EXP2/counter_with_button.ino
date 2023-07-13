int ledPin[] = {3,4,5,6};
const int buttonPin = 2;
int buttonState = 0;
byte counter = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0;i<4;i++){
    pinMode(ledPin[i],OUTPUT);
  
  }
  pinMode(buttonPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  buttonState = digitalRead(buttonPin);
  //when click the button we go to the next number
  if (buttonState == LOW) {
    displayBinary(counter);
    counter++;
    delay(300);
  } else {
    displayBinary(counter);
  } 
}
//function that choose which leds should be on base on the number
void displayBinary(byte number)
{
  for (int i =0;i<4;i++)
  {
    if (bitRead(number, i)==1)
    {
      digitalWrite(ledPin[i], HIGH);
    }
    else
    {
      digitalWrite(ledPin[i], LOW);
    }
  }
}  
