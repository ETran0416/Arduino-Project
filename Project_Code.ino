#include "SR04.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


int TRIG_PIN = 6;
int ECHO_PIN = 5;
int LED1_PIN = 4;
int LED2_PIN = 3;
int LED3_PIN = 2;
int LED4_PIN = 1;

SR04 ultrasonic_sensor1 = SR04(ECHO_PIN, TRIG_PIN);

long distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = ultrasonic_sensor1.Distance();
  Serial.print(distance);
  Serial.println("cm");
  delay(1000);

  if (distance < 20){
  digitalWrite(LED1_PIN, HIGH);
  lcd.print("Stop!!!");
  }
  else if (distance < 40 && distance > 20) {
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    lcd.print("Caution!!!");
  }
  else if (distance > 40) {
    digitalWrite(LED4_PIN, HIGH);
    lcd.print("Good to go!");
  }
  else {
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    digitalWrite(LED3_PIN, LOW);
    digitalWrite(LED4_PIN, LOW);
  }
}

