#ifndef POLINOMIOINTERFAZ_HPP
#define POLINOMIOINTERFAZ_HPP

#include <vector>

#include "monomio.hpp"

using namespace std;

namespace ed {
    class PolinomioInterfaz {
    private:

        virtual void setGrado(int grado) = 0;

        virtual void setNumeroMonomios(int num) = 0;

    public:

        virtual int getGrado() const = 0;

        /// No incluye los monomios nulos
        virtual int getNumeroMonomios() const = 0;

        virtual Monomio getMonomio(int grado) = 0;

        virtual void setMonomio(int grado, float coeficiente) = 0;
        
        virtual bool estaVacio() = 0;

    };
}
#endif
