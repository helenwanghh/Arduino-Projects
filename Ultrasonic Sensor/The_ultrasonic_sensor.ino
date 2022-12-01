#include <NewPing.h>

#define TRIGGER_PIN 12 // pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 11 // pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int ledpin = 4;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

char unit;

void setup() {
pinMode(ledpin, OUTPUT);
Serial.begin(9600); // set baud rate at 9600 baud to see ping results
}
void loop()
{
int dist = sonar.ping_median(5); //median off 5 values


if (Serial.available()) {
unit = Serial.read();
} 
Serial.println(unit);

switch (unit) {
case 'i':
dist = sonar.convert_in(dist); //convert that to cm, replace "cm" with "in" for inches
Serial.print("Ping: ");
Serial.print(dist); // //print value to screen so we can see it.
Serial.println(" inches");
break;

case 'm':
dist = sonar.convert_cm(dist); //convert that to cm, replace "cm" with "in" for inches
Serial.print("Ping: ");
Serial.print(dist); // //print value to screen so we can see it.
Serial.println(" cm");
break;


default: 
break;
}
}
