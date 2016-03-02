#ifndef MONOMIO_HPP
#define MONOMIO_HPP

#include <fstream>
#include <iostream>

#include "monomioInterfaz.hpp"

namespace ed{

class Monomio : public MonomioInterfaz {

private:
    float coeficiente_;
    int grado_;

public:
    Monomio(float coeficiente = 0, int grado = 0) : coeficiente_(coeficiente),
        grado_(grado) {};

    float getCoeficiente() const { return coeficiente_; }

    int getGrado() const { return grado_; }

    void setCoeficiente(float coeficiente) { coeficiente_ = coeficiente; }

    void setGrado(int grado) { grado_ = grado; }

    void leerMonomio();

    void escribirMonomio();

    Monomio& operator=(const Monomio &m);

    Monomio operator*(const Monomio &m);

    friend std::istream &operator>>(std::istream &stream, Monomio &m);

    friend std::ostream &operator<<(std::ostream &stream, Monomio const &m);


};

}


#endif
