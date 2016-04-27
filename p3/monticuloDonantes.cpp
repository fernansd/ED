#include <algorithm>

#include "monticuloDonantes.hpp"

namespace ed {

/*
 *	Parte privada
 */
 
/*!
			\brief Devuelve la posición dentro del vector del donante pasado por
					referencia. Devolverá -1 en caso de que no encuentre el
					Donante dentro del montículo.
			\params d Donante que hay que buscar
			\return Posición del donante dentro del vector
 */
int MonticuloDonantes::getPos(const Donante& d) {
	for (int i = 0; i < monticulo_.size(); i++) {
		if ( d == monticulo_[i] )
			return i;
	}
	
	return -1; // En caso de que no lo encuentre
}

/*!
	\brief Devuelve la posición del hijo derecho del nodo cuya posición
			se ha pasado por parámetro
	\params pos_padre Posición del nodo padre
	\warning Puede devolver posiciones no existentes
	\return Devuelve un entero como la posición
*/
int MonticuloDonantes::hijoIzquierdo(const int pos_padre) {

	return 2*pos_padre + 1;
}

/*!
	\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
			se ha pasado por parámetro
	\params pos_padre Posición del nodo padre
	\warning Puede devolver posiciones no existentes
	\return Devuelve un entero como la posición
*/		
int MonticuloDonantes::hijoDerecho(const int pos_padre) {
	
	return 2*pos_padre + 2;
}

/*!
	\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
			se ha pasado por parámetro
	\params pos_padre Posición del nodo padre
	\warning Puede devolver posiciones no existentes
	\return Devuelve un entero como la posición
*/
int MonticuloDonantes::padre(const int pos_hijo) {
	
	return (pos_hijo - 1) / 2;
}

/*!
	\brief Flota el nodo cuya posición se ha pasado por parámetro
	\params i Posición del nodo a flotar
	\return Nada
*/
void MonticuloDonantes::flotar(const int i) {


	if ( i < monticulo_.size() && monticulo_[i] < monticulo_[padre(i)] ) {
		swap(monticulo_[i], monticulo_[padre(i)] );
		flotar(padre(i));
	}
}

/*!
	\brief Hunde el nodo cuya posición se proporciona por parámetro
	\params i Posición del nodo a hundir
	\return Nada
*/
void MonticuloDonantes::hundir(const int i) {
	return; // Sustituir por código bueno
}


/*
 *	Parte pública
 */

/*!
	\brief Devuelve una copia del donante que está en la cima
	\params Ninguno
	\pre El montículo no está vacío
	\return Devuelve el Donante que se encuentre en la cima del montículo
*/
Donante MonticuloDonantes::cima() const {
	if ( monticulo_.empty() )
		return Donante("vacio","vacio");
	else
		return monticulo_[0];
}

/*!
	\brief Permite insertar un nuevo Donante en el montículo
	\params d Donante que se va a insertar
	\return Nada
*/
void MonticuloDonantes::insertar(const Donante &d) {
	monticulo_.push_back(d);
	// Si el elemento insertado incumple la condición de monticulo se actualiza
	// el monticulo para que lo cumpla
	this->flotar(monticulo_.size() -1);
}

/*!
	\brief Borra el Donante en la cima del montículo
	\params Ninguno
	\pre El montículo no está vacío
	\return Nada
*/	
void MonticuloDonantes::borrar() {
	return; // Sustituir por código bueno
}

/*!
	\brief Lee el montículo de un fichero cuyo nombre se ha pasado
			por parámetro. El formato del fichero será: 
			Apellidos, Nombre, Grupo, Factor RH, nº donanciones
	\params nombre_fichero Nombre del archivo de donde leer el montículo
	\pre El montículo no está vacío
	\return Nada
*/	
void MonticuloDonantes::leerMonticulo(string nombre_fichero) {
	return; // Sustituir por código bueno
}

/*!
	\brief Escribe el montículo en un fichero cuyo nombre se ha pasado
			por parámetro. El formato del fichero será: 
			Apellidos, Nombre, Grupo, Factor RH, nº donanciones
	\params nombre_fichero Nombre del archivo donde grabar el montículo
	\pre El montículo no está vacío
	\return Nada
*/	
void MonticuloDonantes::grabarMonticulo(string nombre_fichero) {
	return; // Sustituir por código bueno
}

/*!
	\brief Incrementa las donaciones del donante en la cima en 1.
			Luego actualiza el orden del montículo
	\params Ninguno
	\pre El montículo no está vacío
	\warning Método no definido en la interfaz de la clase
	\return Nada
*/	
void MonticuloDonantes::realizarDonancion() {

	int donaciones = monticulo_[0].getDonaciones() + 1;
	monticulo_[0].setDonaciones(donaciones);
	// Se encarga de actualizar el orden del monticulo en el caso de que cambie
	hundir(0);

}
} // Fin namespace ed
