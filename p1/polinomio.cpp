#include <cmath>

#include "polinomio.hpp"

using std::cout;
using std::cin;

namespace ed {

    void Polinomio::setMonomio(int grado, float coeficiente) {
        if ( estaVacio() ) {
            Monomio m(grado, coeficiente);
            polinomio_.push_back(m);
            setNumeroMonomios(1);

        } else if ( grado <= grado_ ) {
            int encontrado = 0;
            for(int i = 0; i < n_monomios_; i++) {
                if (polinomio_[i].getGrado() == grado) {
                     polinomio_[i].setCoeficiente(coeficiente);
                     break;
                }
            }
            if (entoncontrado)
        } else { // En caso de que el grado sea mayor que el del polinomio
            Monomio m(grado,coeficiente);
            polinomio_.push_back(m);
            n_monomios_++;
        }
        
        setGrado(polinomio_.back().getGrado());
    }
    
    Monomio Polinomio::getMonomio(int grado) {

    	for(int i = 0; i < n_monomios_; i++) {
    		if (polinomio_[i].getGrado() == grado) {
    			return polinomio_[i];
    		} 
    	}

    	Monomio m(0,0); // Cuando no existe el monomio en el polinomio	
    	return  m;

    }

    void Polinomio::leerPolinomio() {
        int grado;
        float coeficiente;
        cout << "Introduce el grado: ";
        cin >> grado;
        cout << "Introduce el coeficiente: ";
        cin >> coeficiente;
        Monomio m(grado, coeficiente);
        polinomio_.push_back(m);
    }

    void Polinomio::escribirPolinomio() {
    	for(int i = 0; i < n_monomios_; i++) {
    		cout << polinomio_[i];
    	}
    }

    float Polinomio::getValorPolinomio(int x) {
    	float valor = 0, monomio = 0;
    	for (int i = 0; i < n_monomios_; i++) {
    		monomio = pow(x, polinomio_[i].getGrado());
    		monomio *= polinomio_[i].getCoeficiente();
    		valor += monomio;
    		monomio = 0;
    	}
    	return valor;
    }

    Polinomio& Polinomio::operator=(Polinomio const &p) {
        this->grado_ = p.grado_;
        this->n_monomios_ = p.n_monomios_;
        this->polinomio_  = p.polinomio_;
        return *this;
    }

// Sin implementar!!!
    Polinomio operator*(const Polinomio &p) {
    	Polinomio p1;
    	p1.setMonomio(3,5);
    	return p1;
    }

// Sin implementar!!!
    Polinomio Polinomio::operator+(Polinomio const &p) {
    	Polinomio p1;
    	p1.setMonomio(3,5);
    	return p1;
    }

    istream &operator>>(istream &stream, Polinomio &p) {
        int grado;
        float coeficiente;

        cout << "Introduce el grado del monomio: ";
        stream >> grado;
        cout << "Introduce el coeficiente: ";
        stream >> coeficiente;

        p.setMonomio(grado,coeficiente);

        return stream;

    }

    ostream &operator<<(ostream &stream, Polinomio const &p) {
    	for(int i = 0; i < p.n_monomios_; i++) {
    		stream << p.polinomio_[i];
    	}

    	return stream;
    }

}
