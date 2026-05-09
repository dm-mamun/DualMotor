# DualMotor Arduino Library

Control two DC motors independently using any H-bridge driver (L298N, L293D, DRV8833, etc.)

## Installation

1. Download / clone this folder as `DualMotor`
2. Place it in `~/Documents/Arduino/libraries/DualMotor/`
3. Restart the Arduino IDE
4. Include with `#include <DualMotor.h>`

## Wiring (L298N example)

| L298N | Arduino |
|-------|---------|
| IN1   | D8      |
| IN2   | D7      |
| ENA   | D9 ← must be PWM |
| IN3   | D5      |
| IN4   | D4      |
| ENB   | D6 ← must be PWM |
| GND   | GND     |
| +12V  | Motor power supply |

> **PWM pins on Uno:** 3, 5, 6, 9, 10, 11

## Quick start

```cpp
#include <DualMotor.h>

DualMotor motor;

void setup() {
  motor.lpin(8, 7, 9);  // IN1, IN2, ENA  (left motor)
  motor.rpin(5, 4, 6);  // IN1, IN2, ENB  (right motor)
}

void loop() {
  motor.Motor(200, 200);   // Both forward
  delay(2000);
  motor.Motor(0, 0);       // Coast stop
  delay(1000);
}
```

## API reference

### Setup (call in `setup()`)
```cpp
motor.lpin(in1, in2, en);  // Left motor: direction pins + PWM enable
motor.rpin(in1, in2, en);  // Right motor: direction pins + PWM enable
```

### Core function
```cpp
motor.Motor(int a, int b);
// a = left motor speed  (-250 to 250)
// b = right motor speed (-250 to 250)
// positive → forward, negative → backward, 0 → coast
```

### Convenience helpers
```cpp
motor.forward(speed);   // Both motors forward  (default speed = 200)
motor.backward(speed);  // Both motors backward
motor.turnLeft(speed);  // Left back, right forward
motor.turnRight(speed); // Left forward, right back
motor.stop();           // Coast both to stop
```

## Speed range

Values are clamped to **-250 / +250** internally (not 255) to leave headroom for the PWM signal and avoid stressing the driver at maximum duty cycle continuously. You can change the clamp value in `DualMotor.cpp` if needed.
