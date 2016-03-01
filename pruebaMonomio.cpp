#include <iostream>

#include "monomio.hpp"

int main () {

    Monomio m1, m2;
    int opcion;
    opcion = menu();

    switch (opcion) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            std::cout << "Error con la opción del menu" << std::endl;
    }

return 0;
}

int menu() {
    int opcion = 0;
    do {
        std::cout << "Introduce la opción deseada:\n"
                     "\t1) Valor del monomio para un valor de X\n"
                     "\t2) Multiplicación de dos monomios y almacenar el "
                     "resultado en el tercero\n"
                     "\t3) Fin del programa\n";

        std::cin >> opcion;
    } while (opcion < 1 || opcion > 3);

    return opcion;
}
