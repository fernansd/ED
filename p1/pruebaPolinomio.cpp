#include <iostream>
#include <ctime>
#include <cstdlib>

#include "monomio.hpp"
#include "polinomio.hpp"

using namespace ed;

int main () {
    
    // Falta usar constructor de copia y valores por defecto
    Polinomio p1, p2, p3;
    srand(time(NULL));
    for(int i = 0; i <= 11; i++) {
    	p1.setMonomio(rand()%10, rand()%10);
    }
    p1.escribirPolinomio();
    
    float valor = p1.getValorPolinomio(1);
    cout << "Valor de p1 = " << valor << endl;

    p1.leerPolinomio();

    cout << p1;

    p2.setMonomio(2,7);
    p2.setMonomio(5,3);
    p2.setMonomio(50,100);
    
    cout << p2;
    
    p3 = p1 + p2;
    cout << p3;
    
//    p3 = p1 * p2;
//    cout << p3;

    return 0;
}
