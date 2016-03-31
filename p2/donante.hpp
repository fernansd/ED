#ifndef DONANTE_HPP
#define DONANTE_HPP

#include "donanteInterfaz.hpp"

namespace ed {

class Donante : public DonanteInterfaz {
    private:
        string nombre_, apellidos_, grupo_, factor_;
    
    public:
        Donante(string nombre = "", string apellidos = "", string grupo = "",
            string factor = "") {
            
            if ( grupo != "0" || grupo != "A" || grupo != "B" || grupo != "AB" )
                grupo = "";            
            
            if (factor != "negativo" || factor != "positivo") 
                factor = "";            
            
            nombre_ = nombre;
            apellidos_ = apellidos;
            grupo_ = grupo;
            factor_ = factor;
        }
        
        Donante(Donante &d) {
            nombre_ = d.getNombre();
            apellidos_ = d.getApellidos();
            grupo_ = d.getGrupo();
            factor_ = d.getFactorRH();
        }
    
        string getNombre() const { return nombre_; }
        
        void setNombre(string nombre) { nombre_ = nombre; }

        string getApellidos() const { return apellidos_; }
        
        void setApellidos(string apellidos) { apellidos_ = apellidos; }
        
        string getGrupo() const { return grupo_; }
        
        void setGrupo(string grupo);
        
        string getFactorRH() const { return factor_; }
        
        void setFactorRH(string factor);
        
        void leerDonante();
        
        void escribirDonante();
        
        Donante &operator=(Donante const &d);
        
        bool operator==(Donante const &d);
        
        bool operator<=(Donante const &d);
        
        friend istream &operator>>(istream &stream, Donante &d);
        
        friend ostream &operator<<(ostream &stream, Donante &d);
};
}
#endif
