#ifndef DONANTE_HPP
#define DONANTE_HPP

#include "donanteInterfaz.hpp"

namespace ed {

class Donante : public DonanteInterfaz {

    private:
        string nombre_, apellidos_, grupo_, factor_;
        int donaciones_;
    
    public:
        Donante(string nombre = "-", string apellidos = "-", string grupo = "-",
            string factor = "-", int donaciones = 0) {
            
            if ( grupo != "0" && grupo != "A" && grupo != "B" && grupo != "AB" 
                && grupo != "-")
                grupo = "";            
            
            if (factor != "negativo" && factor != "positivo" && factor != "-") 
                factor = "";            
            
            if (donaciones < 0)
            	donaciones = 0;
            
            nombre_ = nombre;
            apellidos_ = apellidos;
            grupo_ = grupo;
            factor_ = factor;
            donaciones_ = donaciones;
        }
        
        Donante(const Donante &d) {
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
        
        bool setGrupo(string grupo);
        
        string getFactorRH() const { return factor_; }
        
        bool setFactorRH(string factor);
        
        int getDonaciones() const { return donaciones_; }
        
        bool setDonanciones(int num);
        
        void leerDonante();
        
        void escribirDonante();
        
        Donante &operator=(Donante const &d);
        
        bool operator==(Donante const &d) const;
        
        friend bool operator<=(Donante const &d1, Donante const &d2);
        
        friend istream &operator>>(istream &stream, Donante &d);
        
        friend ostream &operator<<(ostream &stream, Donante &d);
};
}
#endif
