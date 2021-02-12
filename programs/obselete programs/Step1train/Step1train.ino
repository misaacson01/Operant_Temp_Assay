const int spareValves = 2;
const int refValves = 3;
const int testValves = 4;
const int leftfeedValve = 5;
const int rightfeedValve = 6;
const int sensorAct = 7;
const int leftAir = 8;
const int rightAir = 9;
const int leftSensor = 10;
const int rightSensor = 11;
int coldN = 0;
int hotN = 0;
int refChoice = 0;
int testChoice = 0;
int refTimeout = 0;
int testTimeout = 0;
long refDelay = 0;
long testDelay = 0;
long randNumber;
int delayTime = 0;
int decideTime = 0;
int leftSens = 1;
int rightSens = 1;
int Choice = 0;
int N = 0;
int Drinking = 0;
void setup() {
  Serial.begin(9600);
  pinMode(spareValves, OUTPUT);
  pinMode(refValves, OUTPUT);
  pinMode(testValves, OUTPUT);
  pinMode(sensorAct, OUTPUT);
  pinMode(leftfeedValve, OUTPUT);
  pinMode(rightfeedValve, OUTPUT);
  pinMode(leftAir, OUTPUT);
  pinMode(rightAir, OUTPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  Serial.println("Insert mouse now");
}
void loop() {
  digitalWrite(spareValves, LOW);
  digitalWrite(refValves, LOW);
  digitalWrite(testValves, LOW);
  delay(1);
  delayTime = delayTime + 1;
  leftSens = digitalRead(leftSensor);
  rightSens = digitalRead(rightSensor);
  if (leftSens < 0.5){
    Serial.print("Left ");
    delay(200);
    delayTime = delayTime + 200;
    leftSens = digitalRead(leftSensor);
    if (leftSens < 0.5){
      Serial.print("Drinking ");
      Drinking = Drinking + 1;
      Serial.println(Drinking);
      digitalWrite(leftfeedValve, HIGH);
      delay(500);
      digitalWrite(leftfeedValve, LOW);
      delay(2000);
      delayTime = delayTime + 3000;
    }
  }
  if (rightSens < 0.5){
    Serial.print("Right ");
    delay(200);
    delayTime = delayTime + 200;
    rightSens = digitalRead(rightSensor);
    if (rightSens < 0.5){
      Serial.print("Drinking ");
      Drinking = Drinking + 1;
      Serial.println(Drinking);
      digitalWrite(rightfeedValve, HIGH);
      delay(500);
      digitalWrite(rightfeedValve, LOW);
      delay(2000);
      delayTime = delayTime + 3000;
    }
  }
}
