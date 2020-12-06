long state = LOW;
long button = 7;
long led = 10; 

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT); 
  pinMode(led,OUTPUT);
}

void loop() {
  long new_state = digitalRead(button);
  Serial.println(new_state);

  if (new_state == HIGH ){
    state = !state;     
  }
  digitalWrite(led, state);
}
