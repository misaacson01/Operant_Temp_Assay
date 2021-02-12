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
int testChoice = 0;
int testN = 0;
int testLeft = 0;
int testRight = 0;
int refChoice = 0;
int refN = 0;
int refLeft = 0;
int refRight = 0;
long refDelay = 0;
long testDelay = 0;
long randNumber;
long delayTime = 0;
long successRate = 0.5;
int decideTime = 0;
int leftSens = 1;
int rightSens = 1;
int Choice = 0;
int Pick = 0;
int N = 0;
int testAir = 0;
int Drinking = 0;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
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
  digitalWrite(sensorAct, LOW);
  digitalWrite(testValves, HIGH);
  digitalWrite(refValves, HIGH);
  delay(15000);
  digitalWrite(testValves, LOW);
  digitalWrite(refValves, LOW);
  delay(30000);
}
void loop() {
  digitalWrite(refValves, LOW);
  digitalWrite(testValves, LOW);
  digitalWrite(sensorAct, LOW);
  delay(8500);
  digitalWrite(sensorAct, HIGH);
  delay(1500);
  Choice = 0;
  testChoice = 0;
  refChoice = 0;
  delayTime = 0;
  while (Choice < 1){
    delay(1);
    delayTime = delayTime + 1;
    leftSens = digitalRead(leftSensor);
    if (leftSens < 0.5){
      delay(500);
      delayTime = delayTime + 500;
      leftSens = digitalRead(leftSensor);
      if (leftSens < 0.5){
        Choice = 1;
        delayTime = delayTime/1000;
        delayTime = 0;
        randNumber = random(1000);
        N = N + 1;
        if (randNumber > 499){
          Serial.print(" Test ");
          testN = testN + 1;
          digitalWrite(testValves, HIGH);
          delay(50);
          digitalWrite(refValves, HIGH);
          digitalWrite(spareValves, HIGH);
          delay(50);
          digitalWrite(spareValves, LOW);
          delay(500);
          digitalWrite(leftfeedValve, HIGH);
          delay(500);
          digitalWrite(leftfeedValve, LOW);
          delay(3000);
          Drinking = Drinking + 1;
          while (delayTime < 10000){
            delay(1);
            delayTime = delayTime + 1;
            leftSens = digitalRead(leftSensor);
            rightSens = digitalRead(rightSensor);
            if (leftSens < 0.5){
              delay(500);
              delayTime = delayTime + 500;
              leftSens = digitalRead(leftSensor);
              if (leftSens < 0.5){
                Serial.println("Left (Incorrect)"); 
                digitalWrite(leftAir, HIGH);
                delay(500);
                digitalWrite(leftAir, LOW);
                delay(500);
                if (testChoice < 1){
                  testLeft = testLeft + 1;
                  testChoice = 1;
                } 
                delayTime = 10000;
              }
            }
            if (rightSens < 0.5){
              delay(500);
              delayTime = delayTime + 500;
              rightSens = digitalRead(rightSensor);
              if (rightSens < 0.5){
                Serial.println("Right (Correct)");
                if (testChoice < 1){
                  testRight = testRight + 1;
                  testChoice = 1;
                } 
                digitalWrite(rightfeedValve, HIGH);
                delay(500);
                digitalWrite(rightfeedValve, LOW);
                delay(1500);
                Drinking = Drinking + 1;
                delayTime = 10000;
              }
            }
          }
        }  
        if (randNumber < 500){
          Serial.print(" Ref ");
          refN = refN + 1;
          digitalWrite(refValves, HIGH);
          delay(50);
          digitalWrite(refValves, LOW);
          digitalWrite(spareValves, HIGH);
          delay(50);
          digitalWrite(spareValves, LOW);
          delay(500);
          digitalWrite(leftfeedValve, HIGH);
          delay(500);
          digitalWrite(leftfeedValve, LOW);
          delay(3000);
          Drinking = Drinking + 1;
          while (delayTime < 10000){
            delay(1);
            delayTime = delayTime + 1;
            leftSens = digitalRead(leftSensor);
            rightSens = digitalRead(rightSensor);
            if (leftSens < 0.5){
              delay(500);
              delayTime = delayTime + 500;
              leftSens = digitalRead(leftSensor);
              if (leftSens < 0.5){
                Serial.println("Left (Correct)");
                if (refChoice < 1){
                  refLeft = refLeft + 1;
                  refChoice = 1;
                } 
                digitalWrite(leftfeedValve, HIGH);
                delay(500);
                digitalWrite(leftfeedValve, LOW);
                delay(1500);
                Drinking = Drinking + 1;
                delayTime = 10000;
              }
            }
            if (rightSens < 0.5){
              delay(500);
              delayTime = delayTime + 500;
              rightSens = digitalRead(rightSensor);
              if (rightSens < 0.5){
                Serial.println("Right (Incorrect)");
                if (refChoice < 1){
                  refRight = refRight + 1;
                  refChoice = 1;
                }
                digitalWrite(rightAir, HIGH);
                delay(500);
                digitalWrite(rightAir, LOW);
                delay(500);
                delayTime = 10000;
              }
            }
          }
        } 
      }
    } 
  }
  if (N > 29){
    refN = refLeft + refRight;
    testN = testLeft + testRight;
    successRate = ((refLeft/refN)/2) + ((testRight/testN)/2);
    Serial.print("Ref Trials: ");
    Serial.println(refN);
    Serial.print("Ref Correct: ");
    Serial.println(refLeft);
    Serial.print("Test Trials: ");
    Serial.println(testN);
    Serial.print("Test Correct: ");
    Serial.println(testRight);
    Serial.print("Success Rate: ");
    Serial.println(successRate);
    while(1){
    }
  }  
}
  
