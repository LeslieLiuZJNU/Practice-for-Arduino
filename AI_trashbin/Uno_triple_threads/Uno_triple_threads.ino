#include<SCoop.h>
#define t1 2
#define e1 3
#define t2 4
#define e2 5
#define in1 10
#define in2 11
#define s1 8
#define s2 9

defineTask(BT1);
void BT1::setup() {
  Serial.begin(9600);
  pinMode(t1, OUTPUT);
  pinMode(e1, INPUT);
  pinMode(s1, OUTPUT);
  pinMode(in1, INPUT); 
}
void BT1::loop() {
  int duration, cm = 0;
  int angle, t;
    Serial.println("input1: ");
    Serial.println(digitalRead(in1));
    Serial.println();
  if (digitalRead(in1)==0) {
    for (int i = 1; i <= 3; i++) {
      digitalWrite(t1, LOW);
      sleep(1);
      digitalWrite(t1, HIGH);
      sleep(1);
      digitalWrite(t1, LOW);
      duration = pulseIn(e1, HIGH);
      cm += (duration / 2) / 29.1;
    }
    cm /= 3;
    //    Serial.println("1: ");
    //    Serial.println(cm);
    //    Serial.println();
    if (cm < 20) {
      //angle = 0;
      for (int i = 0; i <= 50; i++)
      {
        //t = map(angle, 0, 180, 500, 2500);
        t = 1;
        digitalWrite(s1, HIGH);
        sleep(t);
        digitalWrite(s1, LOW);
        sleep(20 - t);
      }
      sleep(2000);
      //angle = 90;
      for (int i = 0; i <= 50; i++)
      {
        t = 2;
        digitalWrite(s1, HIGH);
        sleep(t);
        digitalWrite(s1, LOW);
        sleep(20 - t);
      }
    }
  }
  else if (digitalRead(in1)==1) {
    for (int i = 0; i <= 10; i++)
    {
      t = 1;
      digitalWrite(s1, HIGH);
      sleep(t);
      digitalWrite(s1, LOW);
      sleep(20 - t);
    }
    sleep(2000);
    for (int i = 0; i <= 10; i++)
    {
      t = 2;
      digitalWrite(s1, HIGH);
      sleep(t);
      digitalWrite(s1, LOW);
      sleep(20 - t);
    }
  }
  sleep(50);
}

defineTask(BT2);
void BT2::setup() {
  pinMode(t2, OUTPUT);
  pinMode(e2, INPUT);
  pinMode(s2, OUTPUT);
  pinMode(in2, INPUT);
}
void BT2::loop() {
  int duration, cm = 0;
  int angle, t;
  Serial.println("input2: ");
  Serial.println(digitalRead(in2));
  Serial.println();
  if (digitalRead(in2) ==0) {
    for (int i = 1; i <= 3; i++) {
      digitalWrite(t2, LOW);
      sleep(1);
      digitalWrite(t2, HIGH);
      sleep(1);
      digitalWrite(t2, LOW);
      duration = pulseIn(e2, HIGH);
      cm += (duration / 2) / 29.1;
    }
    cm /= 3;
    //    Serial.println("2: ");
    //    Serial.println(cm);
    //    Serial.println();
    if (cm < 20) {
      //angle = 0;
      for (int i = 0; i <= 50; i++)
      {
        //t = map(angle, 0, 180, 500, 2500);
        t = 1;
        digitalWrite(s2, HIGH);
        sleep(t);
        digitalWrite(s2, LOW);
        sleep(20 - t);
      }
      sleep(2000);
      //angle = 90;
      for (int i = 0; i <= 50; i++)
      {
        t = 2;
        digitalWrite(s2, HIGH);
        sleep(t);
        digitalWrite(s2, LOW);
        sleep(20 - t);
      }
    }
  }
  else if (digitalRead(in2) ==1) {
    for (int i = 0; i <= 10; i++)
    {
      t = 1;
      digitalWrite(s2, HIGH);
      sleep(t);
      digitalWrite(s2, LOW);
      sleep(20 - t);
    }
    sleep(2000);
    for (int i = 0; i <= 10; i++)
    {
      t = 2;
      digitalWrite(s2, HIGH);
      sleep(t);
      digitalWrite(s2, LOW);
      sleep(20 - t);
    }
  }
  sleep(50);
}

void setup() {
  mySCoop.start();
}
void loop() {
  yield();
}
