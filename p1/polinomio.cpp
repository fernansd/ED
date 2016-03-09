#include <cmath>

#include "polinomio.hpp"

using std::cout;
using std::cin;

namespace ed {

    void Polinomio::setMonomio(int grado, float coeficiente) {
        if ( grado <= grado_ ) {
            polinomio_[grado].setCoeficiente(coeficiente);
        } else {
            Monomio m(grado,coeficiente);
            polinomio_.push_back(m);
        }
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
        cout << "Introducir grado";
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

	
    Polinomio operator*(const Polinomio &p) {
    	Polinomio p1;
    	p1.setMonomio(3,5);
    	return p1;
    }

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
