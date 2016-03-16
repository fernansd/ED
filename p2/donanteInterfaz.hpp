#ifndef DONANTEINTERFAZ_HPP
#define DONANTEINTERFAZ_HPP

#include <string>
#include <iostream>

using namespace std;

namespace ed {

class DonanteInterfaz {
    public:
        virtual string getNombre() const = 0;
        
        virtual void setNombre(string nombre) = 0;

        virtual string getApellidos() const = 0;
        
        virtual void setApellidos(string apellidos) = 0;
        
        virtual string getGrupo() const = 0;
        
        virtual void setGrupo(string grupo) = 0;
        
        virtual string getFactorRH() const = 0;
        
        virtual void setFactorRH(string factor) = 0;
        
        virtual void leerDonante() = 0;
        
        virtual void escribirDonante() = 0;

};
}// Fin namespace ed
#endif
