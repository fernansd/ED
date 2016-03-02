#include "polinomio.hpp"
using std::cout;
using std::cin;

namespace ed {

    void setGrado(int grado) {
        if ( grado < grado_ )
            polinomio_.resize(grado);
    }

    vector<Monomio> getPolinomio();

    void setMonomio(int grado, float coeficiente) {
        if ( grado <= grado_ ) {
            polinomio_[grado].
        }
    }

    void leerPolinomio() {
        cout << "Introducir grado";
    }

    void escribirPolinomio();

    Polinomio &operator=(Polinomio const &p) {
        grado_ = p.grado_;
        n_monomios_ = p.n_monomios_;
        polinomio_  = p.polinomio_;
    }

    Polinomio operator*(Polinomio const &p);

    Polinomio operator+(Polinomio const &p);

    float getValorPolinomio(int x);

    friend istream &operator>>(istream &stream, Polinomio &p);

    friend ostream &operator<<(ostream &stream, Polinomio const &p);

}
