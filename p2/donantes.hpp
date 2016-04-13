#ifndef DONANTES_HPP
#define DONANTES_HPP

#include <iostream>
#include <fstream>
#include <cstring>

#include "donantesInterfaz.hpp"
#include "donante.hpp"
#include "lista.hpp"

namespace ed {

class Donantes : public DonantesInterfaz {
    private:
        Lista<Donante> lista_;
        
    public:
        Donantes() {}
    
        Donantes(string archivo_donantes);
    
        bool estaVacia() const;
    
        Donante buscaDonante(string nombre, string apellidos) const;

        void insertaDonante(const Donante &d);

        void borrarDonante(Donante &d);
        
        /// Devuelve -1 si no encuentra el donante
        int posicionDonante(const Donante &d) const;
        
        void actualizaDonante(int posicion_donante, const Donante &d);
        
        void escribirDonantes() const;
        
        void leerDonantes();
};
} // Fin namespace ed
#endif
