#include <iostream>
#include <ctime>
#include <cstdlib>

#include "monomio.hpp"
#include "polinomio.hpp"

using namespace ed;

int main () {
    Polinomio p;
    cout << "hola" << endl;
    srand(time(NULL));
    //for(int i = 0; i < 10; i++) {
    	p.setMonomio(0,3);
    	p.setMonomio(2,1);
    	p.setMonomio(5,2);
    //}
    p.escribirPolinomio();

    p.leerPolinomio();

    cout << p;

    cout << "adios" << endl;

    return 0;
}
