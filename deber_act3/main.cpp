#include <iostream>
#include <stdexcept>
#include "calculadora.h"

int main() {
    double a, b;

    std::cout << "Ingrese el primer número: ";
    std::cin >> a;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> b;

    Calculadora calc;

    try {
        double suma = calc.sumar(a, b);
        double resta = calc.restar(a, b);
        double multiplicacion = calc.multiplicar(a, b);
        double division = calc.dividir(a, b);

        std::cout << "Suma: " << suma << std::endl;
        std::cout << "Resta: " << resta << std::endl;
        std::cout << "Multiplicación: " << multiplicacion << std::endl;
        std::cout << "División: " << division << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}