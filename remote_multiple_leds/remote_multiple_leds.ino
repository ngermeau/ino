#include "IRremote.h"

int receiver = 3;   // pin 1 of IR receiver to Arduino digital pin 3

int ser = 9;        // data (next entry 0 or 1)
int rclock = 8;     // latch (send data of shift register to output)
int srclock = 7;    // shift clock 

byte leds = 0;      // leds needed to be lighten


IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results

void setup()  
{
  Serial.begin(9600);     
  irrecv.enableIRIn(); 
  updateShiftRegister();
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
    int value = results.value;
     
     
    Serial.println("here");  
    Serial.println(results.value);  
    switch(value){
      case 3238126971:
        bitSet(leds,0);
        break;
      case 2534850111: 
        bitSet(leds,1);
        break;
      case 1033561079:
        bitSet(leds,2);
        break;
      case 1635910171:
        bitSet(leds,3);
        break;
      case 2351064443:
        bitSet(leds,4);
        break;
      case 1217346747:
        bitSet(leds,5);
        break;
      case 71952287:
        bitSet(leds,6);
        break;
      case 851901943:
        bitSet(leds,7);
        break;
      default:
        leds=0;
    }
    updateShiftRegister();
    irrecv.resume(); 
  }  
}
