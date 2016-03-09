#ifndef POLINOMIOINTERFAZ_HPP
#define POLINOMIOINTERFAZ_HPP

#include <iostream>
#include <vector>

#include "monomio.hpp"

using namespace std;

namespace ed {
    class PolinomioInterfaz {
    public:
    
        virtual int getGrado() const = 0;
        
        /// Descarta los monomios necesarios para obtener el grado proporcionado
        virtual void setGrado(int grado) = 0;

        /// No incluye los monomios nulos
        virtual int getNumeroMonomios() const = 0;
                
        virtual Monomio getMonomio(int grado) const = 0;

        virtual void setMonomio(int grado, float coeficiente) = 0;
        
        virtual bool estaVacio() = 0;

    };
}
#endif
