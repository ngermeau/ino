#include <Servo.h>

int VRx = A0;
int VRy = A1;
int SW = 2;
int SERVOPIN = 8;

Servo servo;
int angle = 10;  //represent a step for the servo

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  servo.attach(SERVOPIN);
}

void loop() {
  int xPosition = analogRead(VRx);
  int yPosition = analogRead(VRy);
  int SW_state = digitalRead(SW);
  int x =  map(xPosition, 0, 1023, -512, 512); //remap values for simplicity
  int y = map(yPosition, 0, 1023, -512, 512);
  
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" | Y: ");
  Serial.print(y);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  
  if (x < 0){
    for(angle = 10; angle < 180; angle++)  {                                  
      servo.write(angle);               
      delay(15);                   
     } 
  }

  if (x > 10){
     for(angle = 180; angle > 0; angle--) {                                  
       servo.write(angle);               
       delay(15);                   
     } 
  }
}
