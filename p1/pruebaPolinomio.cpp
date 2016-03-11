#include <iostream>
#include <ctime>
#include <cstdlib>

#include "monomio.hpp"
#include "polinomio.hpp"

using namespace ed;

int main () {
    Polinomio p1;
    srand(time(NULL));
    for(int i = 0; i <= 11; i++) {
    	p1.setMonomio(rand()%100, rand()%100);
    }
    p1.escribirPolinomio();

    p1.leerPolinomio();

    cout << p1;
    
    Polinomio p2;
    p2.setMonomio(2,7);
    p2.setMonomio(5,3);
    p2.setMonomio(50,100);
    
    cout << p2;
    
    cout << (p1+p2);

    return 0;
}
