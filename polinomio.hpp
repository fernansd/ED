#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include "polinomioInterfaz.hpp"

namespace ed {

    class Polinomio : public PolinomioInterfaz {
    private:
        int grado_;
        int n_monomios_; /// No considera los monomios nulos
        vector<Monomio> polinomio_;
        
    public:
        Polinomio() {
            grado_ = 0;
            n_monomios = 0;
            polinomio_.erase();
        }
        
        int getGrado() { return grado_; }
        
        void setGrado(int grado);
        
        int getNumeroMonomios() { return n_monomios_; }
        
        vector<Monomio> getPolinomio() { return polinomio_; }
        
        Monomio getMonomio(int grado) { return polinomio_[grado]; }
        
        void setMonomio(int grado, float coeficiente);
        
        bool estaVacio() { polinomio_.empty(); }
        
        void leerPolinomio();
        
        void escribirPolinomio();
        
        Polinomio &operator=(Polinomio const &p);
        
        Polinomio operator*(Polinomio const &p);
        
        Polinomio operator+(Polinomio const &p);
        
        float getValorPolinomio(int x);
        
        friend istream &operator>>(istream &stream, Polinomio &p);
        
        friend ostream &operator<<(ostream &stream, Polinomio const &p);
    };

} // Fin espacio de nombres
#endif
