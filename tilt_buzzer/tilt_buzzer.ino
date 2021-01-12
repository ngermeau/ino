long tilt = 2; 
long active_buzzer = 4;
long passive_buzzer = 5;

void setup() {
  Serial.begin(9600);
  pinMode(tilt, INPUT); 
  pinMode(active_buzzer, OUTPUT);
  pinMode(passive_buzzer, OUTPUT);
}

void loop() {
  long state = digitalRead(tilt);
  Serial.println(state);
  if (state == LOW){  //when arduino is flipped on the side

    //with active buzzer use a internal oscillator to produce sound
    tone(active_buzzer, 500, 50); 
    delay(2000);

    //with passive buzzer it is the signal changes which produces the sound
    for (int i=0; i< 1000; i++){ 
      digitalWrite(passive_buzzer,LOW);
      delay(1);
      digitalWrite(passive_buzzer,HIGH);
    }
  }
}
