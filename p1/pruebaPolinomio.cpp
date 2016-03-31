#include <iostream>
#include <ctime>
#include <cstdlib>

#include "monomio.hpp"
#include "polinomio.hpp"

using namespace ed;

int menu();

int main () {
    
    // Falta usar constructor de copia y valores por defecto
    Polinomio p1, p2(3), p3(p2), p4;
    srand(time(NULL));
    for(int i = 0; i <= 6; i++) {
    	p1.setMonomio(rand()%10, rand()%10);
    }
    
    int x, opcion = 1;
    while(opcion !=0) {
	    opcion = menu();
        
	    switch (opcion) {
		    case 1:		        
                cout << "Introducir un valor de X: ";
                cin >> x;
                cout << "Valor del polinomio: ";
                p1.escribirPolinomio();
                cout << "\nPara un valor de x = " << x;
                cout << "\nValor: " << p1.getValorPolinomio(x);
                
		        break;
		        
		    case 2:
                cout << "\nValor de la suma del polinomio 1:";
                p1.escribirPolinomio();
                cout << "\ncon el polinomio 2: ";
                p2.escribirPolinomio();
                            
                p3 = p1 + p2;
                cout << "\n\tp1 + p2 = ";
                p3.escribirPolinomio();

		        break;
		        
		    case 3:
		        cout << "\nValor de la producto del polinomio 1:";
                p1.escribirPolinomio();
                cout << "\ncon el polinomio 2: ";
                p2.escribirPolinomio();
                            
                p3 = p1 * p2;
                cout << "\n\tp1 * p2 = ";
                p3.escribirPolinomio();
		
		        break;
		        
		    case 4:
                cin >> p4;
                cout << p4;
                		    
		        break;
		        
		    case 0:
		        break;
		        
		    default:
		        cout << "Error con la opción del menu" << endl;
	    }
     }

    return 0;
}

int menu() {
    int opcion = 0;
    do {
        std::cout << "\nIntroduce la opción deseada:\n"
                     "\t1) Valor de polinomio para un valor de X\n"
                     "\t2) Suma de dos polinomios y almacenar resultado"
                     " en el tercero\n"
                     "\t3) Multiplicación de dos polinomios y almacenar"
                     " resultado en el tercero\n"
                     "\t4) Lectura y escritura de un polinomio por sobrecarga"
                     " de operadores\n"
                     "\t0) Fin del programa\n";

	std::cout << "Opcion: ";
        std::cin >> opcion;

    } while (opcion < 0 || opcion > 4);

    return opcion;
}
