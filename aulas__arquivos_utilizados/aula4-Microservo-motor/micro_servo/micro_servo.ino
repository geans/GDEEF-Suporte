#include <Servo.h>

#define SERVO 6 // Porta Digital 6 PWM

Servo s; // Variável Servo

void setup () {
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
}

void loop() {
  if (Serial.available() > 0) {
    s.write(Serial.readString().toInt());
    delay(15);
  }
}
