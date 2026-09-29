// Práctica 4: Calculadora básica
// Traduce la receta de RECETA.md a C++, paso por paso.
// Deja el comentario "// Paso N" sobre cada bloque de código.

#include <iostream>

#include "utilerias.h"

int main() {
    int opcion = 0;
    double a = 0;
    double b = 0;

    std::cout << "Bienvenido a la calculadora basica" << std::endl;
    std::cout << "1) Suma" << std::endl;
    std::cout << "2) Resta" << std::endl;
    std::cout << "3) Multiplicacion" << std::endl;
    std::cout << "4) Division" << std::endl;
    std::cout << "5) Salir" << std::endl;

    std::cout << "Elige una opcion: (1-5) ";
    std::cin >> opcion;
        while (opcion < 1 || opcion > 5) {
            std::cout << "opcion no valida, elige una opcion: (1-5) ";
            std::cin >> opcion;
        }

    
    std::cout << "Primer numero: ";
    std::cin >> a;
    std::cout << "Segundo numero: ";
    std::cin >> b;
    
    if (opcion== 4) {
        while (b == 0) {
            std::cout << "No se puede dividir entre cero" << std::endl;
            std::cout << "segundo numero distinto de 0: ";
            std::cin >> b;
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