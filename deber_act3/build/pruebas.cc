#include <cstdint>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <cstring> // Add this line to include the <cstring> header

#include "main.cpp" // Incluye la implementación de la calculadora

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size < 2 * sizeof(double)) {
        return 0; // No hay suficiente datos para dos números dobles
    }

    double a, b;
    std::memcpy(&a, data, sizeof(double));
    std::memcpy(&b, data + sizeof(double), sizeof(double));

    Calculadora calc;

    try {
        calc.sumar(a, b);
        calc.restar(a, b);
        calc.multiplicar(a, b);
        calc.dividir(a, b);
    } catch (const std::invalid_argument& e) {
        // Captura la excepción de división por cero
    }

    return 0;
}