
int trigPin = 3;
int echoPin = 4;

int ledBluePin = 5;
int ledGreenPin = 6;
int ledRedPin = 7;

long duration; // duration of sound wave travel
int distance; // distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  pinMode(ledRedPin, OUTPUT); 
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledBluePin, OUTPUT);
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10){
    //cool green
    analogWrite(ledGreenPin,255); 
    analogWrite(ledRedPin,128);
    analogWrite(ledBluePin,0);
  }
  if (distance > 10 && distance < 30){
    //cool blue
    analogWrite(ledGreenPin,128); 
    analogWrite(ledRedPin,0);
    analogWrite(ledBluePin,255);
  }
  if (distance > 30){
    //cool red
    analogWrite(ledGreenPin,51); 
    analogWrite(ledRedPin,255);
    analogWrite(ledBluePin,51);
  }
}
