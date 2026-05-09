#include "DualMotor.h"

DualMotor::DualMotor()
  : _lmf(0), _lmb(0), _lms(0),
    _rmf(0), _rmb(0), _rms(0),
    _lpinSet(false), _rpinSet(false) {}

// ─── Pin setup ────────────────────────────────────────────────────────────────

void DualMotor::lpin(uint8_t in1, uint8_t in2, uint8_t en) {
  _lmf = in1;
  _lmb = in2;
  _lms = en;
  pinMode(_lmf, OUTPUT);
  pinMode(_lmb, OUTPUT);
  pinMode(_lms, OUTPUT);
  _lpinSet = true;
}

void DualMotor::rpin(uint8_t in1, uint8_t in2, uint8_t en) {
  _rmf = in1;
  _rmb = in2;
  _rms = en;
  pinMode(_rmf, OUTPUT);
  pinMode(_rmb, OUTPUT);
  pinMode(_rms, OUTPUT);
  _rpinSet = true;
}

// ─── Core motor function (your original logic, unchanged) ────────────────────

void DualMotor::Motor(int a, int b) {
  if (!_lpinSet || !_rpinSet) return; // Safety: pins must be set first

  // ── Left motor ──
  if (a > 0) {
    digitalWrite(_lmf, 1);
    digitalWrite(_lmb, 0);
  } else {
    a = -(a);
    digitalWrite(_lmf, 0);
    digitalWrite(_lmb, 1);
  }

  // ── Right motor ──
  if (b > 0) {
    digitalWrite(_rmf, 1);
    digitalWrite(_rmb, 0);
  } else {
    b = -b;
    digitalWrite(_rmf, 0);
    digitalWrite(_rmb, 1);
  }

  // ── Clamp to safe PWM range ──
  if (a > 250) a = 250;
  if (b > 250) b = 250;

  analogWrite(_lms, a);
  analogWrite(_rms, b);
}

// ─── Convenience helpers (all call Motor internally) ─────────────────────────

void DualMotor::forward(int speed) {
  Motor(speed, speed);
}

void DualMotor::backward(int speed) {
  Motor(-speed, -speed);
}

void DualMotor::turnLeft(int speed) {
  Motor(-speed, speed);
}

void DualMotor::turnRight(int speed) {
  Motor(speed, -speed);
}

void DualMotor::stop() {
  Motor(0, 0);
}
