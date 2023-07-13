#include <LedControl.h>
int INPUT_COLUMNS[] = {0B00000000,
0B00000000,
0B00000000,
0B00000000,
0B00000000,
0B00000000,
0B00000000,
0B00111110,
0B00001000,
0B00001000,
0B00111110,
0B00000000,
0B00111110,
0B00101010,
0B00101010,
0B00100010,
0B00000000,
0B00111110,
0B00000010,
0B00000010,
0B00000000,

0B00000000,
0B00111110,
0B00000010,
0B00000010,
0B00000000,
0B00000000,
0B00011100,
0B00100010,
0B00100010,
0B00011100};

int INPUT_LENGTH = sizeof(INPUT_COLUMNS) /  sizeof(INPUT_COLUMNS[0]);

void display(LedControl lc,int i){

    lc.setColumn(0, 0 , INPUT_COLUMNS[i+0]);
    lc.setColumn(0, 1 , INPUT_COLUMNS[i+1]);
    lc.setColumn(0, 2 , INPUT_COLUMNS[i+2]);
    lc.setColumn(0, 3 , INPUT_COLUMNS[i+3]);
    lc.setColumn(0, 4 , INPUT_COLUMNS[i+4]);
    lc.setColumn(0, 5 , INPUT_COLUMNS[i+5]);
    lc.setColumn(0, 6 , INPUT_COLUMNS[i+6]);
    lc.setColumn(0, 7 , INPUT_COLUMNS[i+7]); 
}

LedControl lc1=LedControl(11,13,10,1);
LedControl lc2=LedControl(8,13,7,1);
LedControl lc3=LedControl(5,13,4,1);
LedControl lc4=LedControl(2,13,1,1);

int p1 = 0;
void tick(){



display(lc1, p1);

if(p1 > 7){
  int p2 = p1 - 8;
  display(lc2, p2);
}

if(p1 > 15){
   int p3 = p1 - 16;
    display(lc3, p3);
}
if(p1 > 23){
   int p4 = p1 - 24;
    display(lc4, p4);
}

if (p1 > INPUT_LENGTH*2){
  p1 = 0;
}
p1= p1 + 1;

}
void setup()
{

  lc4.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc4.setIntensity(0,8);       // Set the brightness to default value
  lc4.clearDisplay(0);         // and clear the display
  lc1.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc1.setIntensity(0,8);       // Set the brightness to default value
  lc1.clearDisplay(0); 
  lc2.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc2.setIntensity(0,8);       // Set the brightness to default value
  lc2.clearDisplay(0); 
  lc3.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc3.setIntensity(0,8);       // Set the brightness to default value
  lc3.clearDisplay(0); 

}
void loop(){
  tick();
  delay(200);
}