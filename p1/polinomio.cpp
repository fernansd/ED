#include "polinomio.hpp"
using std::cout;
using std::cin;

namespace ed {

    void Polinomio::setGrado(int grado) {
        if ( grado < grado_ )
            polinomio_.resize(grado);
    }

    void Polinomio::setMonomio(int grado, float coeficiente) {
        if ( grado <= grado_ ) {
            Monomio m = polinomio_[grado];
        }
    }

    void Polinomio::leerPolinomio() {
        cout << "Introducir grado";
    }

    void Polinomio::escribirPolinomio() {
    	cout << "Por Implementar" << endl;
    }

    Polinomio& Polinomio::operator=(Polinomio const &p) {
        grado_ = p.grado_;
        n_monomios_ = p.n_monomios_;
        polinomio_  = p.polinomio_;
    }

    Polinomio operator*(Polinomio const &p) {
    	cout << "Por Implementar" << endl;
    }

    Polinomio operator+(Polinomio const &p) {
    	cout << "Por Implementar" << endl;
    }

    float getValorPolinomio(int x) {
    	cout << "Por Implementar" << endl;
    }

    istream &operator>>(istream &stream, Polinomio &p);

    ostream &operator<<(ostream &stream, Polinomio const &p);

}
