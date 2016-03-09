#include "monomio.hpp"

using namespace std;

namespace ed{

Monomio& Monomio::operator=(const Monomio &m) {
    grado_ = m.grado_;
    coeficiente_ = m.coeficiente_;
    return *this;
}

void Monomio::leerMonomio() {
    cout << "Introduce el coeficiente: ";
    cin >> coeficiente_;
    cout << "Introduce el grado: ";
    cin >> grado_;
}

void Monomio::escribirMonomio() {
    cout << coeficiente_;
    cout << "x^" << grado_;
}

Monomio Monomio::operator*(const Monomio &m) {
    Monomio aux;

    aux.grado_ = grado_ + m.grado_;
    aux.coeficiente_ = coeficiente_ * m.coeficiente_;

    return aux;

}

istream &operator>>(istream &stream, Monomio &m) {
    cout << "Introduce el coeficiente: ";
    stream >> m.coeficiente_;
    cout << "Introduce el grado: ";
    stream >> m.grado_;

    return stream;
}

ostream &operator<<(ostream &stream, Monomio const &m) {
    stream << m.getCoeficiente();
    stream << "x^" << m.getGrado();
    
    return stream;
}

} // Fin namespace
