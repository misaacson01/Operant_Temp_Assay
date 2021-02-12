 const int coldValves = 2;
const int normValves = 3;
const int hotValves = 4;
const int leftfeedValve = 5;
const int rightfeedValve = 6;
const int sensorAct = 7;
const int leftAir = 8;
const int rightAir = 9;
const int leftSensor = 10;
const int rightSensor = 11;
const int midSensor = 12;
int leftSens = 1;
int rightSens = 1;
int midSens = 1;
void setup() {
  Serial.begin(9600);
  pinMode(coldValves, OUTPUT);
  pinMode(normValves, OUTPUT);
  pinMode(hotValves, OUTPUT);
  pinMode(sensorAct, OUTPUT);
  pinMode(leftfeedValve, OUTPUT);
  pinMode(rightfeedValve, OUTPUT);
  pinMode(leftAir, OUTPUT);
  pinMode(rightAir, OUTPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(midSensor, INPUT);
  Serial.println("Ready to test");
}
void loop() {
  digitalWrite(normValves, LOW);
  digitalWrite(hotValves, LOW);
  leftSens = digitalRead(leftSensor);
  midSens = digitalRead(midSensor);
  rightSens = digitalRead(rightSensor);
  
  if (leftSens < 0.5){
   Serial.print("Left ");
   digitalWrite(leftAir, HIGH);
   while (rightSens < 0.5){
     digitalWrite(normValves, HIGH);
     digitalWrite(hotValves, HIGH);
     delay(1000);
     rightSens = digitalRead(rightSensor);
  }
  else{
    Serial.print("     ");
    digitalWrite(leftAir, LOW);
  }
  
  if (rightSens < 0.5){
    Serial.print("Right");
    digitalWrite(rightAir, HIGH);
    while (leftSens < 0.5){
     digitalWrite(normValves, HIGH);
     digitalWrite(hotValves, HIGH);
     delay(1000);
     leftSens = digitalRead(leftSensor);
  }
  }
  else{
    digitalWrite(rightAir, LOW);
  }
  
  Serial.println("");
    delay(100);
}
  
