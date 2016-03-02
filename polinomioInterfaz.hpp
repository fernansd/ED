#ifndef POLINOMIOINTERFAZ_HPP
#define POLINOMIOINTERFAZ_HPP

#include <vector>

#include "monomio.hpp"

namespace ed {
    class PolinomioInterfaz {
    public:
    
        virtual int getGrado() const = 0;
        
        /// Descarta los monomios necesarios para obtener el grado proporcionado
        virtual void setGrado(int grado) const = 0;

        /// No incluye los monomios nulos
        virtual int getNumeroMonomios() const = 0;
        
        /// Devuelve el polinomio en forma de lista de monomios
        virtual vector <Monomio> getPolinomio() const = 0;
        
        virtual Monomio getMonomio(int grado) const = 0;

        virtual void setMonomio(int grado, float coeficiente) const = 0;
        
        virtual bool estaVacio() const = 0;

    };
}
#endif
