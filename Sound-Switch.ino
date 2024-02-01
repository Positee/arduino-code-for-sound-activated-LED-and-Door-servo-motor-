#include <Servo.h>

const int soundSensorPin = 2;
const int ledPin = 3;
const int servoPin = 9;

Servo myservo;

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  myservo.attach(servoPin);

  Serial.begin(9600);
}

void loop() {
  int soundValue = digitalRead(soundSensorPin);

  if (soundValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Clap detected! LED turned on.");

    // Rotate the servo motor 180 degrees
    for (int angle = 0; angle <= 180; angle += 1) { 
      myservo.write(angle);
      delay(15);
    }
    delay(1000);  // Delay for better visualization
    // Return the servo motor to the initial position
    for (int angle = 180; angle >= 0; angle -= 1) {
      myservo.write(angle);
      delay(15);
    }
    digitalWrite(ledPin, LOW);
  }
}
