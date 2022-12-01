byte array[]={
B10000000,
B01000000,
B00100000,
B00010000,
B00001000,
B00000100,
B00000010,
B00000001,
B00000010,
B00000100,
B00001000,
B00010000,
B00100000,
B01000000,
B10000000,
};

int counter =0;
int size_=15;
void setup() {
  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
}


void loop(){

digitalWrite(9, LOW);
shiftOut(8, 10,MSBFIRST, array[counter]);
digitalWrite(9,HIGH);
delay(50);
counter++;

if (counter > size_){
  counter = 0;
}
}
