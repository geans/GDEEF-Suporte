#include <Servo.h>

#define SERVO 6 // Porta Digital 6 PWM

Servo s; // Variável Servo
int pos; // Posição Servo

void setup ()
{
  s.attach(SERVO);
  Serial.begin(9600);
  Serial.println("Motor Ligado");
  //s.write(0); // Inicia motor posição zero
}

void loop()
{
  if (Serial.available()) {
    Serial.print(pos);
    Serial.print(" -> ");
    pos = Serial.readString().toInt();
    s.write(pos);
    Serial.println(pos);
  }
}
