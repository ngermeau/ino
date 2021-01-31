#include "IRremote.h"

int data = 9; 
int rclock = 8; 
int srclock = 7; 

void setup()  
{
  Serial.begin(9600);
  pinMode(data,OUTPUT);     //next entry is a 0 or a 1
  pinMode(rclock,OUTPUT);   //push data register to output
  pinMode(srclock,OUTPUT);  //shift the register
}

void loop()   
{
digitalWrite(data, HIGH);
digitalWrite(rclock, HIGH);
delay(1000);
digitalWrite(srclock, HIGH);
delay(1000);
}
