
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
int Steps = 0;
int Direction = 0;
int number_steps=512;//= 2048/4


void setup(){
  Serial.begin(9600);
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  // delay(1000);
}


void loop(){
  //1 rotation counter clockwise
  stepper(number_steps);
  delay(1000);
  //1 rotation clockwise
  stepper(-number_steps);
  delay(1000);
  //Keep track of step number
 }






void stepper(double nbStep){
  if(nbStep>=0){
    Direction=1;
  }
  else{
    Direction=0;
    nbStep=-nbStep;
  }

  for (int x=0;x<nbStep*8;x++){

      delayMicroseconds(1000);
    
      if(Direction==1){ Steps++;}
      if(Direction==0){ Steps--; }
      if(Steps>7){Steps=0;}
      if(Steps<0){Steps=7; }

    
    switch(Steps){
      case 0:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      break; 
      case 1:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
      break; 
      case 2:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      break; 
      case 3:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      break; 
      case 4:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
      case 5:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
      case 6:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
      case 7:
        digitalWrite(IN1, HIGH); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      break; 
      default:
        digitalWrite(IN1, LOW); 
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
      break; 
  }

  } 
}
