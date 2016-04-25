#include <algorithm>

#include "monticuloDonantes.hpp"

namespace ed {

/*
 *	Parte privada
 */
int MonticuloDonantes::getPos(const Donante& d) {
	for (int i = 0; i < monticulo_size(); i++) {
		if ( d == monticulo_[i] )
			return i;
	}
	
	return -1; // En caso de que no lo encuentre
}

int MonticuloDonantes::hijoIzquierdo(const int pos_padre) {

	return monticulo[2*pos_padre + 1];
}
		
int MonticuloDonantes::hijoDerecho(const int pos_padre) {
	
	return monticulo[2*pos_padre + 2];
}
		
int MonticuloDonantes::padre(const int pos_hijo) {
	
	return monticulo[(pos_hijo - 1) / 2];
}

void MonticuloDonantes::flotar(const int i) {

	if ( i < monticulo_.size() && monticulo_[i] < padre(monticulo_[i] ) {
		swap(monticulo_[i], padre(monticulo_[i]));
		flotar(padre(monticulo_[i]));
	}
}
		
void MonticuloDonantes::hundir(const int i) {
	int i;
	for (i = 0; i < monticulo_size(); i++) {
		if ( d == monticulo_[i] )
			break;
	}
	
	int izq = 
	
	if ( !(d == n) ) {
		swap(monticulo_[i], monticu
	}
}


/*
 *	Parte pública
 */
bool MonticuloDonantes::vacio() const {
	if ( tam_ == 0 )
		return true;
	else
		return false;
}
	
Donante MonticuloDonantes::cima() const {
	if ( monticulo_.empty() )
		return;
	else
		return monticulo_[0];
}

void MonticuloDonantes::insertar(const Donante &d) {
	monticulo_.push_back(d);
	if ( padre(d) <= d )
		monticulo_.flotar(d);
}

void MonticuloDonantes::borrar() {
	return;
}

void MonticuloDonantes::leerMonticulo(string nombre_fichero);

void MonticuloDonantes::grabarMonticulo(string nombre_fichero);

} // Fin namespace ed
