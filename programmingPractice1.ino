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

#define pB1 1
#define pB2 2
#define led1 9
#define led2 10
#define led3 11
#define led4 12


int temp=0;


void setup() {

  pinMode(pB1,INPUT_PULLUP);
  pinMode(pB1,INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);  

  digitalWrite(led2,1);
  digitalWrite(led3,1);
  digitalWrite(led4,1);
}

void loop() {

  if(!digitalRead(pB1)){
    digitalWrite(led1,0);
    temp=temp^1;   //exlusive or reverses the state of that bit.  
    digitalWrite(led2,temp);

    while(!digitalRead(pB1));
    
  }
  else digitalWrite(led1,1);


  
}
