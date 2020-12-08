long analog_input = A0;
long led1 = 7;
long led2 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}


void loop() {
  long new_state = analogRead(analog_input);
  Serial.println(new_state);
  delay(1); //for more stable reading 

  if (new_state < 600){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    
  }else {
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }
}

