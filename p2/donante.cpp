#include "donante.hpp"

namespace ed {

bool Donante::setGrupo(string grupo) {

    if ( grupo != "0" && grupo != "A" && grupo != "B" && grupo != "AB" )
        return;
        
    grupo_ = grupo;
}
        
bool Donante::setFactorRH(string factor) {

    if (factor != "negativo" && factor != "positivo") 
        return;
        
    factor_ = factor; 
}
        
void Donante::leerDonante() {
    cin >> *this;
}
        
void Donante::escribirDonante() {
    cout << *this;
}

// Falta por implementar        
Donante& Donante::operator=(Donante const &d) {

    *this = d;
    return *this;
}
        
bool Donante::operator==(Donante const &d) {

    if (this->getNombre() == d.getNombre() &&
        this->getApellidos() == d.getApellidos() &&
        this->getGrupo() == d.getGrupo() &&
        this->getFactorRH() == d.getFactorRH()    
        ) return true;
    else
        return false;
}

bool operator<=(Donante const &d1, Donante const &d2) {
    if (d1.getApellidos() == d2.getApellidos()) {
        if (d1.getNombre() < d2.getNombre()) {
            return false;
        }
    } else {
        if (d1.getApellidos() == d2.getApellidos()) {
            return false;
        }
    }
    
    return true;
}
        
istream &operator>>(istream &stream, Donante &d) {
    string aux;
    
    cout << "Lectura de datos de donante" << endl;
    
    cout << "Introduce el nombre: ";
    cin >> aux;
    d.setNombre(aux);
    
    cout << "Introduce los apellidos: ";
    cin >> aux;
    d.setApellidos(aux);
    
    cout << "Introduce el grupo: ";
    cin >> aux;
    d.setGrupo(aux);
    
    cout << "Introduce el factor RH: ";
    cin >> aux;
    d.setFactorRH(aux);
    
    return stream;
}
        
ostream &operator<<(ostream &stream, Donante &d) {

    stream << "Datos de donante: " << endl << endl;
    
    stream << "\tNombre: " << d.getNombre() << endl;
    stream << "\tApellidos: " << d.getApellidos() << endl;
    stream << "\tGrupo: " << d.getGrupo() << endl;
    stream << "\tFactor RH: " << d.getFactorRH() << endl;
    
    return stream;
}

}// Fin namespace ed
