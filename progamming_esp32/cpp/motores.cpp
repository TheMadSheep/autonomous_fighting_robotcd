#include "hpp/motores.hpp"

Motores::Motores(int pino_in1, int pino_in2, int pino_in3, int pino_in4, int pino_pwma, int pino_pwmb) {
  _pino_in1 = pino_in1;
  _pino_in2 = pino_in2;
  _pino_pwma = pino_pwma;
  _pino_in1 = pino_in3;
  _pino_in2 = pino_in4;
  _pino_pwmb = pino_pwmb;
}

void Motores::inicializa() {
  pinMode(_pino_in1, OUTPUT);
  pinMode(_pino_in2, OUTPUT);
  pinMode(_pino_pwma, OUTPUT);
  pinMode(_pino_in3, OUTPUT);
  pinMode(_pino_in4, OUTPUT);
  pinMode(_pino_pwmb, OUTPUT);
}

void Motores::velocidade_motor_a(int velocidade) {
    if velocidade >= 0 {
        digitalWrite(_pino_in1, HIGH);
        digitalWrite(_pino_in2, LOW);
    } else {
        digitalWrite(_pino_in1, LOW);
        digitalWrite(_pino_in2, HIGH);
        velocidade = -velocidade;
    }
    analogWrite(_pino_pwma, velocidade);
}

void Motores::velocidade_motor_b(int velocidade) {
    if velocidade >= 0 {
        digitalWrite(_pino_in3, HIGH);
        digitalWrite(_pino_in4, LOW);
    } else {
        digitalWrite(_pino_in3, LOW);
        digitalWrite(_pino_in4, HIGH);
        velocidade = -velocidade;
    }
    analogWrite(_pino_pwmb, velocidade);
}