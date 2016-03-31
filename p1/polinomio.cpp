#include <cmath>
#include <algorithm>

#include "polinomio.hpp"

using std::cout;
using std::cin;

namespace ed {
    // Función necesaria para usar la función std::sort() que ordena el vector
    // debe devolver true cuando el primer argumento precede al segundo en orden
    bool comparadorMonomio(const Monomio& m1, const Monomio& m2) {
        if (m1.getGrado() < m2.getGrado())
            return true;
        else
            return false;        
    }

    void Polinomio::setMonomio (float coeficiente, int grado) {
        if ( coeficiente == 0 )
            return; // Sale en el caso de que el monomio valga 0
        
        Monomio monomio(coeficiente, grado);
        
        if ( estaVacio() ) {
            polinomio_.push_back(monomio);
            Polinomio::setNumeroMonomios(1);

        // En caso de que el grado sea mayor que el del polinomio
        } else if ( grado > Polinomio::getGrado() ) {
            polinomio_.push_back(monomio);
            n_monomios_++;            
            
        } else {

            int modificado = 0; // Indica si se ha modificado el vector

            for(int i = 0; i < n_monomios_; i++) {
                if (grado == polinomio_[i].getGrado()) {
                
                    polinomio_[i].setCoeficiente(
                        polinomio_[i].getCoeficiente() + coeficiente);
                    modificado = 1;
                    
                    if (polinomio_[i].getCoeficiente() == 0) {
                        polinomio_.erase(polinomio_.begin() + i);
                        n_monomios_--;
                    }
                }
            }
            if (!modificado) {
                polinomio_.push_back(monomio);
                n_monomios_++;
                std::sort(polinomio_.begin(), polinomio_.end(),
                    comparadorMonomio);
            }
        
        }
                
        Polinomio::setGrado(polinomio_.back().getGrado());
    }

    void Polinomio::leerPolinomio() {
        cin >> *this;
    }

    void Polinomio::escribirPolinomio() {
        cout << *this;
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
    Polinomio Polinomio::operator*(const Polinomio &p) {
    	Polinomio aux;
    	Monomio m;
    	
    	for(int i = 0; i < p.getNumeroMonomios(); i++) {
            for(int j = 0; j < this->getNumeroMonomios(); j++) {
                m = this->getMonomio(j) * p.getMonomio(i);
                aux.setMonomio(m.getCoeficiente(), m.getGrado());
            }
    	}
    	
    	return aux;
    }

    Polinomio Polinomio::operator+(Polinomio const &p) {
    	Polinomio aux;
    	Monomio m;
    	
    	for(int i = 0; i < p.getNumeroMonomios(); i++) {
    	    m = p.getMonomio(i);
    	    aux.setMonomio(m.getCoeficiente(), m.getGrado());
    	}
    	
    	for(int i = 0; i < this->getNumeroMonomios(); i++) {
    	    m = this->polinomio_[i];
    	    aux.setMonomio(m.getCoeficiente(), m.getGrado());
    	}
    	
    	return aux;
    }

    istream &operator>>(istream &stream, Polinomio &p) {
        int grado;
        float coeficiente;
        cout << "Introduce grado -1 para detener la introducción" << endl;
        cout << "Introduce el grado del monomio: ";
        stream >> grado;
        cout << "Introduce el coeficiente: ";
        stream >> coeficiente;
        
        while (grado != -1) {
            p.setMonomio(coeficiente, grado);
            
            cout << "Introduce el grado de otro monomio: ";
            stream >> grado;
            cout << "Introduce su coeficiente: ";
            stream >> coeficiente;            
        }        

        return stream;

    }

    ostream &operator<<(ostream &stream, Polinomio const &p) {
    	stream << endl; // Deja espacio por encima del mensaje
    	
    	if ( p.estaVacio() ) {
    	    stream << "El polinomio esta vacío" << endl;
    	    return stream;
        }
        
    	stream << "Términos del polinomio:  ";
    	stream << p.polinomio_[p.n_monomios_-1];// Última posición
    	for(int i = p.n_monomios_-2; i > -1; i--) {
    	    Monomio m = p.getMonomio(i);
    	    // Omite los términos con coeficiente 0 a propósito
    		if (m.getGrado() == 0) {
   		        stream << " + " << m.getCoeficiente();
    		} else {
        		if (m.getCoeficiente() > 0) {
        		    stream << " + " << m;
        		} else if (m.getCoeficiente() < 0) {
        		    m.setCoeficiente(m.getCoeficiente() * (-1));
        		    stream << " - " << m;
        		}
        	}
    	}
    	
    	stream << endl;
    	return stream;
    }

}
