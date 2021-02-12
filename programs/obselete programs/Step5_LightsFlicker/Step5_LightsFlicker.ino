const int spareValves = 2;
const int redLight = 3;
const int blueLight = 4;
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
int decideTime = 0;
int leftSens = 1;
int rightSens = 1;
int Choice = 0;
int Pick = 0;
int N = 0;
int testAir = 0;
int Drinking = 0;
int NLights = 0;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(spareValves, OUTPUT);
  pinMode(redLight, OUTPUT);
  pinMode(blueLight, OUTPUT);
  pinMode(sensorAct, OUTPUT);
  pinMode(leftfeedValve, OUTPUT);
  pinMode(rightfeedValve, OUTPUT);
  pinMode(leftAir, OUTPUT);
  pinMode(rightAir, OUTPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  Serial.println("[Lag] [ref/test] [left/right] [testN] [testLeft] [testRight] [refN] [refLeft] [refRight]");
  digitalWrite(sensorAct, LOW);
  Serial.println("Insert mouse now");
  delay(18000);
}
void loop() {
  Serial.println("");
  digitalWrite(redLight, LOW);
  digitalWrite(blueLight, LOW);
  digitalWrite(sensorAct, LOW);
  delay(10500);
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
        Serial.print(delayTime);
        delayTime = 0;
        randNumber = random(1000);
        N = N + 1;
        if (randNumber > 499){
          Serial.print(" Test ");
          testN = testN + 1;
          while (NLights < 10){
            digitalWrite(blueLight, HIGH);
            delay(25);
            digitalWrite(blueLight, LOW);
            delay(25);
            NLights = NLights + 1;
          }
          NLights = 0;
          digitalWrite(leftfeedValve, HIGH);
          while (NLights < 10){
            digitalWrite(blueLight, HIGH);
            delay(25);
            digitalWrite(blueLight, LOW);
            delay(25);
            NLights = NLights + 1;
          }
          NLights = 0;
          digitalWrite(leftfeedValve, LOW);
          while (NLights < 60){
            digitalWrite(blueLight, HIGH);
            delay(25);
            digitalWrite(blueLight, LOW);
            delay(25);
            NLights = NLights + 1;
          }
          NLights = 0;
          Drinking = Drinking + 1;
          while (delayTime < 10000){
            digitalWrite(blueLight, HIGH);
            delay(25);
            digitalWrite(blueLight, LOW);
            delay(25);
            delayTime = delayTime + 50;
            leftSens = digitalRead(leftSensor);
            rightSens = digitalRead(rightSensor);
            if (leftSens < 0.5){
              while (NLights < 10){
                digitalWrite(blueLight, HIGH);
                delay(25);
                digitalWrite(blueLight, LOW);
                delay(25);
                NLights = NLights + 1;
              }
              NLights = 0;
              delayTime = delayTime + 500;
              leftSens = digitalRead(leftSensor);
              if (leftSens < 0.5){
                Serial.print("Left "); 
                digitalWrite(leftAir, HIGH);
                while (NLights < 10){
                  digitalWrite(blueLight, HIGH);
                  delay(25);
                  digitalWrite(blueLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                digitalWrite(leftAir, LOW);
                while (NLights < 10){
                  digitalWrite(blueLight, HIGH);
                  delay(25);
                  digitalWrite(blueLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                if (testChoice < 1){
                  testLeft = testLeft + 1;
                  testChoice = 1;
                } 
                delayTime = 10000;
              }
            }
            if (rightSens < 0.5){
              while (NLights < 10){
                digitalWrite(blueLight, HIGH);
                delay(25);
                digitalWrite(blueLight, LOW);
                delay(25);
                NLights = NLights + 1;
              }
              NLights = 0;
              delayTime = delayTime + 500;
              rightSens = digitalRead(rightSensor);
              if (rightSens < 0.5){
                Serial.print("Right ");
                if (testChoice < 1){
                  testRight = testRight + 1;
                  testChoice = 1;
                } 
                digitalWrite(rightfeedValve, HIGH);
                while (NLights < 10){
                  digitalWrite(blueLight, HIGH);
                  delay(25);
                  digitalWrite(blueLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                digitalWrite(rightfeedValve, LOW);
                while (NLights < 30){
                  digitalWrite(blueLight, HIGH);
                  delay(25);
                  digitalWrite(blueLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                Drinking = Drinking + 1;
                delayTime = 10000;
              }
            }
          }
        }  
        if (randNumber < 500){
          Serial.print(" Ref ");
          refN = refN + 1;
          while (NLights < 10){
            digitalWrite(redLight, HIGH);
            delay(25);
            digitalWrite(redLight, LOW);
            delay(25);
            NLights = NLights + 1;
          }
          NLights = 0;
          digitalWrite(leftfeedValve, HIGH);
          while (NLights < 10){
            digitalWrite(redLight, HIGH);
            delay(25);
            digitalWrite(redLight, LOW);
            delay(25);
            NLights = NLights + 1;
          }
          NLights = 0;
          digitalWrite(leftfeedValve, LOW);
          while (NLights < 60){
            digitalWrite(redLight, HIGH);
            delay(25);
            digitalWrite(redLight, LOW);
            delay(25);
            NLights = NLights + 1;
          }
          NLights = 0;
          Drinking = Drinking + 1;
          while (delayTime < 10000){
            digitalWrite(redLight, HIGH);
            delay(25);
            digitalWrite(redLight, LOW);
            delay(25);
            delayTime = delayTime + 50;
            leftSens = digitalRead(leftSensor);
            rightSens = digitalRead(rightSensor);
            if (leftSens < 0.5){
              while (NLights < 10){
                digitalWrite(redLight, HIGH);
                delay(25);
                digitalWrite(redLight, LOW);
                delay(25);
                NLights = NLights + 1;
              }
              NLights = 0;
              delayTime = delayTime + 500;
              leftSens = digitalRead(leftSensor);
              if (leftSens < 0.5){
                Serial.print("Left ");
                if (refChoice < 1){
                  refLeft = refLeft + 1;
                  refChoice = 1;
                } 
                digitalWrite(leftfeedValve, HIGH);
                while (NLights < 10){
                  digitalWrite(redLight, HIGH);
                  delay(25);
                  digitalWrite(redLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                digitalWrite(leftfeedValve, LOW);
                while (NLights < 30){
                  digitalWrite(redLight, HIGH);
                  delay(25);
                  digitalWrite(redLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                Drinking = Drinking + 1;
                delayTime = 10000;
              }
            }
            if (rightSens < 0.5){
              while (NLights < 10){
                digitalWrite(redLight, HIGH);
                delay(25);
                digitalWrite(redLight, LOW);
                delay(25);
                NLights = NLights + 1;
              }
              NLights = 0;
              delayTime = delayTime + 500;
              rightSens = digitalRead(rightSensor);
              if (rightSens < 0.5){
                Serial.print("Right ");
                if (refChoice < 1){
                  refRight = refRight + 1;
                  refChoice = 1;
                }
                digitalWrite(rightAir, HIGH);
                while (NLights < 10){
                  digitalWrite(redLight, HIGH);
                  delay(25);
                  digitalWrite(redLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                digitalWrite(rightAir, LOW);
                while (NLights < 10){
                  digitalWrite(redLight, HIGH);
                  delay(25);
                  digitalWrite(redLight, LOW);
                  delay(25);
                  NLights = NLights + 1;
                }
                NLights = 0;
                delayTime = 10000;
              }
            }
          }
        } 
      }
    }
    if (delayTime > 180000){
      Serial.println("3 mins");
      delayTime = 0;
    }  
  }
  Serial.print(testN);
  Serial.print(" ");
  Serial.print(testLeft);
  Serial.print(" ");
  Serial.print(testRight);
  Serial.print(" ");
  Serial.print(refN);
  Serial.print(" ");
  Serial.print(refLeft);
  Serial.print(" ");
  Serial.print(refRight);
}
  
