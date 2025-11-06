#ifndef MOTORES_HPP
#define MOTORES_HPP

#include <Arduino.h>

class Motores {
  public:
    Motor(int pino_in1, int pino_in2, int pino_in3, int pino_in4, int pino_pwma, int pino_pwmb);
    void inicializa();

    void velocidade_motor_a (int velocidade);
    void velocidade_motor_b (int velocidade);

  private:
    int _pino_in1;
    int _pino_in2;
    int _pino_pwma;
    int _pino_in3;
    int _pino_in4;
    int _pino_pwma;
};

#endif
