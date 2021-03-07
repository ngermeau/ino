#include <LiquidCrystal.h> // includes the LiquidCrystal Library 


LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object (rs, enable, d4, d5, d6, d7) 


void setup() { 
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
}

void loop() { 
 lcd.print("Arduino"); // Prints "Arduino" on the LCD 
 delay(1000); // 3 seconds delay 
}
