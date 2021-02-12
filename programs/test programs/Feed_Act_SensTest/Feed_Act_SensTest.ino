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
int leftSens = 1;
int rightSens = 1;
int delayTime = 0;
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
  digitalWrite(sensorAct, HIGH);
  delay(1500);
  Serial.println("Ready to test");
}
void loop() {
  while (delayTime < 10000){
  leftSens = digitalRead(leftSensor);
  rightSens = digitalRead(rightSensor);
  if (leftSens < 0.5){
   Serial.print("Left ");
   digitalWrite(leftfeedValve, HIGH);
  }
  else{
    Serial.print("     ");
    digitalWrite(leftfeedValve, LOW);
  }
  if (rightSens < 0.5){
    Serial.print("Right");
    digitalWrite(rightfeedValve, HIGH);
  }
  else{
    digitalWrite(rightfeedValve, LOW);
  }
  Serial.println("");
    delay(100);
    delayTime = delayTime + 100;
  }
  delayTime = 0;
  digitalWrite(sensorAct, LOW);
  while (delayTime < 10000){
  leftSens = digitalRead(leftSensor);
  rightSens = digitalRead(rightSensor);
  if (leftSens < 0.5){
   Serial.print("Left ");
   digitalWrite(leftfeedValve, HIGH);
  }
  else{
    Serial.print("     ");
    digitalWrite(leftfeedValve, LOW);
  }
  if (rightSens < 0.5){
    Serial.print("Right");
    digitalWrite(rightfeedValve, HIGH);
  }
  else{
    digitalWrite(rightfeedValve, LOW);
  }
  Serial.println("");
    delay(100);
    delayTime = delayTime + 100;
  }
  delayTime = 0;
  digitalWrite(sensorAct, HIGH);
}


  
