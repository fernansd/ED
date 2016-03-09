#include <iostream>
#include <ctime>
#include <cstdlib>

#include "polinomio.hpp"
using namespace ed;
int main () {
    Polinomio p;
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
    	p.setMonomio(rand()%10,rand());
    }
}
