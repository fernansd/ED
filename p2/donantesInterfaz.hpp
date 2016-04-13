#ifndef DONANTESINTERFAZ_HPP
#define DONANTESINTERFAZ_HPP

#include "donante.hpp"

using namespace std;

namespace ed {

class DonantesInterfaz {

    virtual bool estaVacia() const = 0;
    
    virtual Donante buscaDonante(string nombre, string apellidos) const = 0;
    
    virtual void insertaDonante(const Donante &d) = 0;
    
    virtual void borrarDonante(Donante &d) = 0;
    
};
} // Fin namespace ed
#endif
