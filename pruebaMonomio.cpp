#include <iostream>
#include <cmath>

#include "monomio.hpp"
#include "monomioInterfaz.hpp"
using namespace ed;
int menu();

int main () {

      int opcion = 0;
      while(opcion != 3) {
	    Monomio m1(3,4), m2(3,4), m3;
	    opcion = menu();

	    switch (opcion) {
		case 1:
                    std::cout << "Lectura del monomio" << std::endl;
                    std::cin >> m3;
                    std::cout << "Introduce un valor de X: ";
                    int X;
                    std::cin >> X;
                    std::cout << "Valor de " << m3 << " con X=" << X;
                    std::cout << " --> " << pow(X,m3.getGrado())*m3.getCoeficiente() << std::endl;
		    break;
		case 2:
                    std::cout << "Lectura primer monomio: \n";
                    std::cin >> m1;
                    std::cout << "Lectura segundo monomio: \n";
                    std::cin >> m2;
                    m3 = m2*m1;
                    std::cout << "Valor del producto: " << m3 << std::endl;

		    break;
		case 3:
		    break;
		default:
		    std::cout << "Error con la opción del menu" << std::endl;
	    }
     }

return 0;
}

int menu() {
    int opcion = 0;
    do {
        std::cout << "\nIntroduce la opción deseada:\n"
                     "\t1) Valor del monomio para un valor de X\n"
                     "\t2) Multiplicación de dos monomios y almacenar el "
                     "resultado en el tercero\n"
                     "\t3) Fin del programa\n";

	std::cout << "Opcion: ";
        std::cin >> opcion;

    } while (opcion < 1 || opcion > 3);

    return opcion;
}
