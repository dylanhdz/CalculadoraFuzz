// calculadora.h
#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <stdexcept>

class Calculadora {
public:
    double sumar(double a, double b) {
        return a + b;
    }

    double restar(double a, double b) {
        return a - b;
    }

    double multiplicar(double a, double b) {
        return a * b;
    }

    double dividir(double a, double b) {
        if (b == 0) {
            throw std::invalid_argument("División por cero");
        }
        return a / b;
    }
};

#endif // CALCULADORA_H