#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <iostream>

#include "polinomioInterfaz.hpp"
#include "monomio.hpp"

namespace ed {

    class Polinomio : public PolinomioInterfaz {
    private:
        int grado_;
        int n_monomios_; /// No considera los monomios nulos
        vector<Monomio> polinomio_;

        // Funciones privadas
        void setGrado(int grado) { grado_ = grado; }

        void setNumeroMonomios(int num) { n_monomios_ = num; }

    public:
        Polinomio() {
            grado_ = 0;
            n_monomios_ = 0;
            polinomio_.clear();
            polinomio_.reserve(10); // Reservamos un espacio inicial de vector
        }

        int getGrado() const{ return grado_; }

        int getNumeroMonomios() const { return n_monomios_; }

        Monomio getMonomio (int pos) const { return polinomio_[pos]; };

        void setMonomio (float coeficiente, int grado);

        bool estaVacio() const { return polinomio_.empty(); }

        void leerPolinomio();

        void escribirPolinomio();

        float getValorPolinomio(int x);

        Polinomio &operator=(Polinomio const &p);

        Polinomio operator*(Polinomio const &p);

        Polinomio operator+(Polinomio const &p);

        friend istream &operator>>(istream &stream, Polinomio &p);

        friend ostream &operator<<(ostream &stream, Polinomio const &p);
    };

} // Fin espacio de nombres
#endif
