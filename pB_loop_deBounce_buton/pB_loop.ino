
const int pBpin=5;
const int ledpin=13;

int ButtonState=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pBpin,INPUT);
pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
ButtonState= digitalRead(pBpin);
if (ButtonState==1){
  Serial.println("pB Out");
}
else {
  Serial.println("pB In");
}
delay(500);
}
