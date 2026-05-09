#ifndef DUAL_MOTOR_H
#define DUAL_MOTOR_H

#include <Arduino.h>

class DualMotor {
  public:
    DualMotor();

    // Call these in setup() to define pins
    // lpin(IN1, IN2, EN)  — left motor
    // rpin(IN1, IN2, EN)  — right motor
    void lpin(uint8_t in1, uint8_t in2, uint8_t en);
    void rpin(uint8_t in1, uint8_t in2, uint8_t en);

    // Main drive function — same as your motor(a, b) code
    // a : left motor  speed  (-250 to 250)
    // b : right motor speed  (-250 to 250)
    // positive = forward, negative = backward, 0 = coast
    void Motor(int a, int b);

    // Convenience helpers
    void forward(int speed = 200);   // Both motors forward
    void backward(int speed = 200);  // Both motors backward
    void turnLeft(int speed = 200);  // Left back, right forward
    void turnRight(int speed = 200); // Left forward, right back
    void stop();                     // Coast both motors

  private:
    // Left motor pins
    uint8_t _lmf;   // IN1 (forward)
    uint8_t _lmb;   // IN2 (backward)
    uint8_t _lms;   // ENA (PWM speed)

    // Right motor pins
    uint8_t _rmf;   // IN1 (forward)
    uint8_t _rmb;   // IN2 (backward)
    uint8_t _rms;   // ENB (PWM speed)

    bool _lpinSet;
    bool _rpinSet;
};

#endif
