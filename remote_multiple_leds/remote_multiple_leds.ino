#include "IRremote.h"

int ser = 9;        // data (next entry 0 or 1)
int rclock = 8;     // latch (send data of shift register to output)
int srclock = 7;    // shift clock 

byte leds = 0;

void setup()  
{
  Serial.begin(9600);
  pinMode(ser,OUTPUT);     
  pinMode(rclock,OUTPUT);  
  pinMode(srclock,OUTPUT); 
}

void updateShiftRegister(){
  digitalWrite(rclock, LOW);
  shiftOut(ser, srclock, MSBFIRST, leds);
  digitalWrite(rclock, HIGH);
}

void loop()   
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);  
    if (results.value == 0xFFA857) {
        digitalWrite(led, HIGH); 
    }else { 
        digitalWrite(led, LOW); 
    }
    irrecv.resume(); 
  }  
//leds = 0;
//delay(100);
//for (int i = 0; i< 8; i++){
  //bitSet(leds,i);
  //updateShiftRegister();
  //delay(100);
}
}
