/*
  MG 2/26/2021  
This program will drive a DC motor based on the input from a photo detector and on serial
input. 

It will collect the sensor data which should vary from 0 to 5V
The ADC now should be 10 bit or 0-1023
Scale the output to 0 to 255 for the outpur PWM
Or between 255 and 0 to reverse the direction

**************************************************
Inputs / Outputs
Pin 8 PWM outpur to   B-IB   // These two control the motor 
Pin 9 digtial control B-IA

Pin A0 Input analog 0-5V

Power motor and detector circuit with 
GND
5V
**************************************************

  
*/

// These constants won't change. They're used to give names to the pins used:

#define pB1 0
#define pB2 1
#define led1 9
#define led2 10
#define led3 11
#define led4 12

    int count=0;

void blink_n_T(int,int);    // prototype

void setup() {

  pinMode(pB1,INPUT_PULLUP);
  pinMode(pB2,INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);  

  digitalWrite(led2,1);
  digitalWrite(led3,1);
  digitalWrite(led4,1);
  Serial.begin(9600);



}

void loop() {
     Serial.println(digitalRead(pB2));
     //Serial.println(digitalRead(pB2));
    if((!digitalRead(pB1))&&(!digitalRead(pB2)))count=0;
    else {
      if(!digitalRead(pB1)){
        count++;
        while(!digitalRead(pB1));

      }
      if(!digitalRead(pB2))blink_n_T(count,200);
   }
  
}

void blink_n_T(int n, int T){
  int i=0;
  for(i=0;i<n;i++){
    digitalWrite(led3,0);
    delay(T/2);
    digitalWrite(led3,1);
    delay(T/2);    
  }
}
