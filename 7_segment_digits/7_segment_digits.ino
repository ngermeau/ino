long analog_input = A0;
long A = 9; //9 instead of because for some reason 1 is always HIGH
long B = 2;
long C = 3;
long D = 4;
long E = 5;
long F = 6;
long G = 7;
long DP = 8;

long DIGIT_ONE = 10;
long DIGIT_TWO = 11;
long DIGIT_THREE = 12;
long DIGIT_FOUR = 13;

long FREQU = 150;

void setup() {
  Serial.begin(9600);
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(DP,OUTPUT);
  pinMode(DIGIT_ONE,OUTPUT);
  pinMode(DIGIT_TWO,OUTPUT);
  pinMode(DIGIT_THREE,OUTPUT);
  pinMode(DIGIT_FOUR,OUTPUT);
}

void display_one(long digit) {
    reset();
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(digit,LOW);
}

void display_two(long digit) {
    reset();
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(E,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(digit,LOW);
}

void display_three(long digit) {
    reset();
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(digit,LOW);
}

void display_four(long digit) {
    reset();
    digitalWrite(F,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(digit,LOW);
}

void loop() {
  display_one(DIGIT_ONE);
  delay(FREQU);
  display_two(DIGIT_TWO);
  delay(FREQU);
  display_three(DIGIT_THREE);
  delay(FREQU);
  display_four(DIGIT_FOUR);
  delay(FREQU);
}

void reset() {
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    digitalWrite(E,LOW);
    digitalWrite(F,LOW);
    digitalWrite(G,LOW);
    digitalWrite(DP,LOW);
    digitalWrite(DIGIT_ONE,HIGH);
    digitalWrite(DIGIT_TWO,HIGH);
    digitalWrite(DIGIT_THREE,HIGH);
    digitalWrite(DIGIT_FOUR,HIGH);
}
