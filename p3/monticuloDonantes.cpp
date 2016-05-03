#include <algorithm>

#include "monticuloDonantes.hpp"

namespace ed {

/*
 *	Parte privada
 */

int MonticuloDonantes::hijoIzquierdo(const unsigned int pos_padre) {

	return 2*pos_padre + 1;
}
		
int MonticuloDonantes::hijoDerecho(const unsigned int pos_padre) {
	
	return 2*pos_padre + 2;
}
		
int MonticuloDonantes::padre(const unsigned int pos_hijo) {
	
	return (pos_hijo - 1) / 2;
}

void MonticuloDonantes::flotar(const unsigned int i) {

	if ( i < monticulo_.size() && monticulo_[i] <= monticulo_[padre(i)] ) {
		swap(monticulo_[i], monticulo_[padre(i)]);
		flotar(padre(i));
	}
}
		
void MonticuloDonantes::hundir(const unsigned int i) {

	unsigned int hijoIzquierdo, hijoDerecho, hijoMenor;
	hijoIzquierdo = this->hijoIzquierdo(i);
	hijoDerecho = this->hijoDerecho(i);
	
	
	// Primero buscamos cuál de los dos hijos es el menor para luego compararlo
	if ( hijoDerecho >= monticulo_.size() ) { // Si el hijo derecho no existe
	    // Si el hijo izquierdo tampoco existe vuelve directamente
	    if ( hijoDerecho >= monticulo_.size() ) {
	        return;
        // Si solo existe el hijo derecho entonces será el menor
	    } else {
	        hijoMenor = hijoIzquierdo;
	    }
	// Si existe derecho también existe izquierdo, debido al orden de llenado
	} else {
	    if ( monticulo_[hijoIzquierdo] <= monticulo_[hijoDerecho] ) {
	        hijoMenor = hijoIzquierdo;
	    } else {
	        hijoMenor = hijoDerecho;
	    }
	}
	
	if ( monticulo_[i] > monticulo_[hijoMenor] ) {
	
	    swap(monticulo_[i], monticulo_[hijoMenor]);
	    hundir(hijoMenor); // En esta posición ya está el que era padre
	}
}


/*
 *	Parte pública
 */
	
Donante MonticuloDonantes::cima() const {
	if ( monticulo_.empty() )
		return Donante("vacio","vacio"); // Devuelve un donante inexistente
	else
		return monticulo_.front();
}

void MonticuloDonantes::insertar(const Donante &d) {
	monticulo_.push_back(d);
	int pos = monticulo_.size() -1 ;
	if ( monticulo_[padre(pos)] <= d )
		this->flotar(monticulo_.size() -1 );
}

void MonticuloDonantes::borrar() {
	std::iter_swap(monticulo_.begin(), monticulo_.end());
	monticulo_.pop_back();
	this->hundir(0); // Hunde el nodo raíz hasta su posición
}

void MonticuloDonantes::leerMonticulo(string nombre_fichero) {
return;
}

void MonticuloDonantes::grabarMonticulo(string nombre_fichero) {
return;
}

} // Fin namespace ed
