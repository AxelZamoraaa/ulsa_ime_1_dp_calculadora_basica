// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

#include <iostream>

#include "utilerias.h"

int main() {
    int opcion = 0;
    double a = 0;
    double b = 0;

    std::cout << "Bienvenido a la calculadora básica" << std::endl;
    std::cout << "1) Suma" << std::endl;
    std::cout << "2) Resta" << std::endl;
    std::cout << "3) Multiplicacion" << std::endl;
    std::cout << "4) Division" << std::endl;
    std::cout << "5) Salir" << std::endl;

    opcion = leerEntero("Elige una opcion (1-5): ");
    while (opcion < 1 || opcion > 5) {
        std::cout << "Opcion no valid, elige un numero del 1 al 5 " << std:: endl;
        opcion = leerEntero("Elige una opcion (1-5): ");
    }

    a = leerDecimal("primer numero: ");
    b = leerDecimal("segundo numero: ");

    if (opcion== 4) {
        while (b == 0) {
            std::cout << "No se puede dividir entre cero" << std::endl;
            b = leerDecimal("segundo numero: ");
        }
    }

    switch (opcion) {
        case 1:
            std::cout <<a<< "+" <<b<< "=" << a+b << std::endl;
            break;
        case 2:
            std::cout <<a<< "-" <<b<< "=" << a-b << std::endl;
            break;
        case 3:
            std::cout <<a<< "*" <<b<< "=" << a*b << std::endl;
            break;
        case 4:
            std::cout <<a<< "/" <<b<< "=" << a/b << std::endl;
            break;
        case 5:
            std::cout << "Saliendo de la calculadora" << std::endl;
            break;
    }

    return 0;
}