#include <DualMotor.h>

DualMotor motor;

void setup() {
  // lpin(IN1, IN2, ENA)  — left motor direction + speed pins
  // rpin(IN1, IN2, ENB)  — right motor direction + speed pins
  motor.lpin(8, 7, 9);   // change pin numbers to match your wiring
  motor.rpin(5, 4, 6);
}

void loop() {
  // ── Using Motor() directly ──────────────────────────────
  // motor.Motor(leftSpeed, rightSpeed)
  // Range: -250 to 250  |  positive = forward, negative = backward

  motor.Motor(200, 200);   // Both forward at speed 200
  delay(2000);

  motor.Motor(-150, -150); // Both backward at speed 150
  delay(2000);

  motor.Motor(200, -200);  // Spin right (left fwd, right back)
  delay(1000);

  motor.Motor(-200, 200);  // Spin left (left back, right fwd)
  delay(1000);

  motor.Motor(0, 0);       // Coast stop
  delay(1000);

  // ── Using convenience helpers ───────────────────────────
  motor.forward(180);
  delay(2000);

  motor.turnRight(150);
  delay(800);

  motor.backward(150);
  delay(2000);

  motor.turnLeft(150);
  delay(800);

  motor.stop();
  delay(2000);
}
