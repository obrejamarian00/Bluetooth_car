
/*!
* @file QuadMotorDriverShield.ino
* @brief QuadMotorDriverShield.ino  Motor control program
*
* Every 2 seconds to control motor positive inversion
*
* @author linfeng(490289303@qq.com)
* @version  V1.0
* @date  2016-4-5
*/
#include "NewPing.h"
#define TRIGGER_PIN 4
#define ECHO_PIN 2
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

const int E1 = 3; ///<Motor1 Speed
const int E2 = 11;///<Motor2 Speed
const int E3 = 5; ///<Motor3 Speed
const int E4 = 6; ///<Motor4 Speed

const int M1 = 4; ///<Motor1 Direction
const int M2 = 12;///<Motor2 Direction
const int M3 = 8; ///<Motor3 Direction
const int M4 = 7; ///<Motor4 Direction

char incoming_value = 0;

float distance;

void M1_advance(char Speed) ///<Motor1 Advance
{
 digitalWrite(M1,LOW);
 analogWrite(E1,Speed);
}
void M2_advance(char Speed) ///<Motor2 Advance
{
 digitalWrite(M2,HIGH);
 analogWrite(E2,Speed);
}
void M3_advance(char Speed) ///<Motor3 Advance
{
 digitalWrite(M3,LOW);
 analogWrite(E3,Speed);
}
void M4_advance(char Speed) ///<Motor4 Advance
{
 digitalWrite(M4,HIGH);
 analogWrite(E4,Speed);
}

void M1_back(char Speed) ///<Motor1 Back off
{
 digitalWrite(M1,HIGH);
 analogWrite(E1,Speed);
}
void M2_back(char Speed) ///<Motor2 Back off
{
 digitalWrite(M2,LOW);
 analogWrite(E2,Speed);
}
void M3_back(char Speed) ///<Motor3 Back off
{
 digitalWrite(M3,HIGH);
 analogWrite(E3,Speed);
}
void M4_back(char Speed) ///<Motor4 Back off
{
 digitalWrite(M4,LOW);
 analogWrite(E4,Speed);
}



void setup() {
  Serial.begin(9600);
  for(int i=3;i<9;i++)
    pinMode(i,OUTPUT);
    
  for(int i=11;i<13;i++)
    pinMode(i,OUTPUT);
}



void loop() {
if (Serial.available() > 0 ) {
incoming_value = Serial.read();
Serial.println("INCOMING DATA:");
Serial.println(incoming_value);
  if (incoming_value == '1'){
    motors_forward();
  }
  else if (incoming_value == '2'){
    motors_back();
    }
  else if (incoming_value == '3'){
    motors_left();
    }
  else if (incoming_value == '4'){
    motors_right();
    }
  else if (incoming_value == '0'){
    motors_stop();
    }
  }
  }


void motors_forward(){
  Serial.println("Forward");
  while(incoming_value == '1'){
    Serial.println("Motors go brrrrr");
    Serial.println(incoming_value);
        M1_advance(100);
        M2_advance(100);
        M3_advance(100);
        M4_advance(100);
        incoming_value = Serial.read();
  }
}

void motors_right(){
  Serial.println("right");
  while(incoming_value == '4'){
    Serial.println("Motors go brrrrr to da right");
    Serial.println(incoming_value);
    M1_back(100);
    M2_back(100);
    M3_advance(100);
    M4_advance(100);
    incoming_value = Serial.read();
  }
}

void motors_left(){
  Serial.println("left");
  while(incoming_value == '3'){
    Serial.println("Motors go brrrrr to da left");
    Serial.println(incoming_value);
    M1_advance(100);
    M2_advance(100);
    M3_back(100);
    M4_back(100);
    incoming_value = Serial.read();
  }
}

void motors_back(){
  while(incoming_value == '2'){
    Serial.println("Motors go brrrrr to da back");
    Serial.println(incoming_value);
    M1_back(100);
    M2_back(100);
    M3_back(100);
    M4_back(100);
    incoming_value = Serial.read();
  }
}


void motors_stop(){
    Serial.println("Motors don't go brrrrr");
      Serial.println(incoming_value);
      M1_advance(0);
      M2_advance(0);
      M3_advance(0);
      M4_advance(0);
}
