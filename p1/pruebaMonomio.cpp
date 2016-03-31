#include <iostream>
#include <cmath>

#include "monomio.hpp"

using namespace ed;

//Prototipos
int menu();

int main () {

      int opcion = 0;

      Monomio m1(3,4), m2(m1), m3;
      std::cout << "\nValor de los tres monomio: " << m1 << ", ";
	  std::cout << m2 << ", " << m3 << "\n\n\n";

      while(opcion !=0) {
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
                    std::cout << "Valor del producto: " << m1 << " * " << m2 <<
                        " = " << m3;

		    break;
		case 0:
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
                     "\t0) Fin del programa\n";

	std::cout << "Opcion: ";
        std::cin >> opcion;

    } while (opcion < 0 || opcion > 2);

    return opcion;
}
