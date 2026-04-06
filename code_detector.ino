#include <Arduino.h>
#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5
#define buzzer 6

long time1 = 0;
long time2 = 0;

float distance_between_sensors = 0.20; // meters (20 cm)

void setup() {
  Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(buzzer, OUTPUT);
}

long getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

void loop() {
  long d1 = getDistance(trig1, echo1);
  long d2 = getDistance(trig2, echo2);

  // Object detected at sensor 1
  if (d1 < 10 && time1 == 0) {
    time1 = millis();
    Serial.println("Object detected at Sensor 1");
  }

  // Object detected at sensor 2
  if (d2 < 10 && time1 != 0 && time2 == 0) {
    time2 = millis();

    float time_taken = (time2 - time1) / 1000.0; // seconds
    float speed = distance_between_sensors / time_taken; // m/s

    Serial.print("Speed: ");
    Serial.print(speed);
    Serial.println(" m/s");

    // Speed limit check
    if (speed > 2.0) { // change limit
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }

    // Reset
    time1 = 0;
    time2 = 0;
  }
}
