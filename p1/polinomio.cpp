#include <cmath>
#include <algorithm>

#include "polinomio.hpp"

using std::cout;
using std::cin;

namespace ed {
    // Función necesaria para usar la función std::sort() que ordena el vector
    // debe devolver true cuando el primer argumento precede al segundo en orden
    bool comparacionMonomio(const Monomio& m1, const Monomio& m2) {
        if (m1.getGrado() < m2.getGrado())
            return true;
        else
            return false;        
    }

    void Polinomio::setMonomio (float coeficiente, int grado) {
        if ( coeficiente == 0 )
            return; // Sale en el caso de que el monomio valga 0
        
        Monomio m(coeficiente, grado);
        
        if ( this->estaVacio() ) {
            polinomio_.push_back(m);
            Polinomio::setNumeroMonomios(1);

        } else if ( grado > Polinomio::getGrado() ) {
            polinomio_.push_back(m);
            n_monomios_++;            
            
        } else { // En caso de que el grado sea mayor que el del polinomio

            int modificado = 0; // Indica si se ha modificado el vector

            for(int i = 1; i < n_monomios_; i++) {
                if (grado == polinomio_[i].getGrado()) {
                    polinomio_[i].setCoeficiente(coeficiente);
                    modificado = 1;
                }
            }
            if (!modificado) {
                polinomio_.push_back(m);
                n_monomios_++;
                std::sort(polinomio_.begin(), polinomio_.end(),
                    comparacionMonomio);
            }
        
        }
                
        Polinomio::setGrado(polinomio_.back().getGrado());
    }
    
    Monomio Polinomio::getMonomio(int grado) {

    	for(int i = 0; i < n_monomios_; i++) {
    		if (polinomio_[i].getGrado() == grado) {
    			return polinomio_[i]; // Si encuentra el monomio lo devuelve
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
        
        setMonomio(coeficiente, grado);
    }

    void Polinomio::escribirPolinomio() {
        cout << endl; // Deja espacio por encima del mensaje
    	
    	if ( estaVacio() ) {
    	    cout << "El polinomio esta vacío" << endl;
    	    return;
        }
        
    	cout << "Términos del polinomio:  ";
    	cout << polinomio_[0];
    	for(int i = 1; i < n_monomios_; i++) {
    	
    	    // Omite los términos con coeficiente 0 a propósito
    		if (polinomio_[i].getCoeficiente() > 0) {
    		    cout << " + " << polinomio_[i];
    		} else if (polinomio_[i].getCoeficiente() < 0) {
    		    Monomio m = polinomio_[i];
    		    m.setCoeficiente(m.getCoeficiente() * (-1));
    		    cout << " - " << m;
    		} else if ( i == 0 ) {
    		    cout << polinomio_[i];
    		}
    	}
    	
    	cout << endl;
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
    	Monomio m;
    	for(int i = 0; i < p.getNumeroMonomios(); i++) {
    	    m = p.polinomio_[i];
    	    p1.setMonomio(m.getCoeficiente(), m.getGrado());
    	}
    	for(int i = 0; i < this->getNumeroMonomios(); i++) {
    	    m = this->polinomio_[i];
    	    p1.setMonomio(m.getCoeficiente(), m.getGrado());
    	}
    	return p1;
    }

    istream &operator>>(istream &stream, Polinomio &p) {
        int grado;
        float coeficiente;

        cout << "Introduce el grado del monomio: ";
        stream >> grado;
        cout << "Introduce el coeficiente: ";
        stream >> coeficiente;

        p.setMonomio(coeficiente, grado);

        return stream;

    }

    ostream &operator<<(ostream &stream, Polinomio const &p) {
    	stream << endl; // Deja espacio por encima del mensaje
    	
    	if ( p.estaVacio() ) {
    	    stream << "\tEl polinomio esta vacío" << endl;
    	    return stream;
        }
        
    	cout << "\tTérminos del polinomio:  ";
//    	for(int i = 0; i < p.n_monomios_; i++) {
//    		stream << p.polinomio_[i] << " ";
//    		if ( p.polinomio_[i+1].getCoeficiente() > 0
//    		     && i != (p.n_monomios_ - 1) ) {
//    		    stream << "+";
//    		}
//    	}
    	
    	stream << endl;

    	return stream;
    }

}
