#include <algorithm>
#include <sstream>
#include <fstream>

#include "donante.hpp"
#include "monticuloDonantes.hpp"

namespace ed {

/*
 *	Parte privada
 */
 
/*!
	\brief Devuelve la posición dentro del vector del donante pasado por
			referencia. Devolverá -1 en caso de que no encuentre el
			Donante dentro del montículo.
	\param d Donante que hay que buscar
	\return Posición del donante dentro del vector
 */
int MonticuloDonantes::getPos(const Donante &d) {
	for (size_t i = 0; i < monticulo_.size(); i++) {
		if ( d == monticulo_[i] )
			return i;
	}
	
	return -1; // En caso de que no lo encuentre
}

/*!
	\brief Devuelve la posición del hijo derecho del nodo cuya posición
			se ha pasado por parámetro
	\param pos_padre Posición del nodo padre
	\warning Puede devolver posiciones no existentes
	\return Devuelve un entero como la posición
*/
int MonticuloDonantes::hijoIzquierdo(const unsigned int pos_padre) {

	return 2*pos_padre + 1;
}

/*!
	\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
			se ha pasado por parámetro
	\param pos_padre Posición del nodo padre
	\warning Puede devolver posiciones no existentes
	\return Devuelve un entero como la posición
*/		
int MonticuloDonantes::hijoDerecho(const unsigned int pos_padre) {
	
	return 2*pos_padre + 2;
}

/*!
	\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
			se ha pasado por parámetro
	\param pos_padre Posición del nodo padre
	\warning Puede devolver posiciones no existentes
	\return Devuelve un entero como la posición
*/
int MonticuloDonantes::padre(const unsigned int pos_hijo) {
	
	return (pos_hijo - 1) / 2;
}

/*!
	\brief Flota el nodo cuya posición se ha pasado por parámetro
	\param i Posición del nodo a flotar
	\return Nada
*/
void MonticuloDonantes::flotar(const unsigned int i) {

    if ( monticulo_.size() == 1)
        return;
        
    if ( i == 0 ) return;

	if ( i < monticulo_.size() && monticulo_[i] <= monticulo_[padre(i)] ) {
		std::swap(monticulo_[i], monticulo_[padre(i)]);
		flotar(padre(i));
	}
}

/*!
	\brief Hunde el nodo cuya posición se proporciona por parámetro
	\param i Posición del nodo a hundir
	\return Nada
*/		
void MonticuloDonantes::hundir(const unsigned int i) {

	unsigned int hijoIzquierdo, hijoDerecho, hijoMenor;
	hijoIzquierdo = this->hijoIzquierdo(i);
	hijoDerecho = this->hijoDerecho(i);
	
	if ( i == (monticulo_.size() -1) ) return;
	
	
	// Primero buscamos cuál de los dos hijos es el menor para luego compararlo
	if ( hijoDerecho >= monticulo_.size() ) { // Si el hijo derecho no existe
	    // Si el hijo izquierdo tampoco existe vuelve directamente
	    if ( hijoIzquierdo >= monticulo_.size() ) {
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
	
	    std::swap(monticulo_[i], monticulo_[hijoMenor]);
	    hundir(hijoMenor); // En esta posición ya está el que era padre
	}

}


/*
 *	Parte pública
 */

/*!
	\brief Devuelve una copia del donante que está en la cima
	\pre El montículo no está vacío
	\return Devuelve el Donante que se encuentre en la cima del montículo
*/
Donante MonticuloDonantes::cima() const {

	if ( monticulo_.empty() )
		return Donante("vacio","vacio");
	else
		return monticulo_.front();
}

/*!
	\brief Permite insertar un nuevo Donante en el montículo
	\return Nada
*/
void MonticuloDonantes::insertar(const Donante &d) {
	monticulo_.push_back(d);
	int pos = monticulo_.size() -1;

	if (monticulo_.size() == 1) return;
	// Si el elemento insertado incumple la condición de monticulo se actualiza
	// el monticulo para que lo cumpla
	if ( monticulo_[padre(pos)] > d )
		this->flotar(monticulo_.size() -1 );
}

/*!
	\brief Borra el Donante en la cima del montículo
	\pre El montículo no está vacío
	\return Nada
*/	
void MonticuloDonantes::borrar() {

    if ( vacio() ) return;
    
    if ( monticulo_.size() == 1) {
        monticulo_.pop_back();    
        return;
    }

	monticulo_[0] = monticulo_.back();
	monticulo_.pop_back();
	this->hundir(0); // Hunde el nodo raíz hasta su posición
}

/*!
	\brief Lee el montículo de un fichero cuyo nombre se ha pasado
			por parámetro. El formato del fichero será: 
			Apellidos, Nombre, Grupo, Factor RH, nº donanciones
	\param nombre_fichero Nombre del archivo de donde leer el montículo
	\pre El montículo no está vacío
	\return Nada
*/	
void MonticuloDonantes::leerMonticulo(string nombre_fichero) {

	ifstream archivo(nombre_fichero); // El destructor cierra el fichero
	string linea;
	
	if (archivo.is_open()) {
	
	    // Obtiene líneas completas hasta llegar al final del fichero
	    while (getline(archivo, linea)) {
	        stringstream stream_linea(linea);
	        string valor;
	        Donante d;
	        
	        // Rellena los campos del donante con los obtenidos del fichero
	        getline(stream_linea, valor, ',');
	        d.setApellidos(valor);
	        getline(stream_linea, valor, ',');
	        d.setNombre(valor);
	        getline(stream_linea, valor, ',');
	        d.setGrupo(valor);
	        getline(stream_linea, valor, ',');
	        d.setFactorRH(valor);
	        getline(stream_linea, valor, ',');
	        if ( !d.setDonaciones( atoi(valor.c_str()) ) ) 
	            cout << "Error leyendo donaciones";
	        
	        this->insertar(d);
	    
	    }
	} else {
	    cout << "Error leyendo monticulo de fichero" << endl;
	}
	
	
}

/*!
	\brief Escribe el montículo en un fichero cuyo nombre se ha pasado
			por parámetro. El formato del fichero será: 
			Apellidos, Nombre, Grupo, Factor RH, nº donanciones
	\param nombre_fichero Nombre del archivo donde grabar el montículo
	\pre El montículo no está vacío
	\return Nada
*/	
void MonticuloDonantes::grabarMonticulo(string nombre_fichero) {
	ofstream archivo(nombre_fichero); // Se encarga de cerrarlo el destructor
	Donante d;
	
	if ( archivo.is_open() ) {
	
	    while ( !this->vacio() ) {
	        
	        d = cima();
	        archivo << d.getApellidos() << ',';
	        archivo << d.getNombre() << ',';
	        archivo << d.getGrupo() << ',';
	        archivo << d.getFactorRH() << ',';
	        archivo << d.getDonaciones() << '\n';
	        
	        // Elimina el donante en la cima para acceder al siguiente
	        this->borrar();
	    }
	} else {
	    cout << "Error escribiendo el montículo en el fichero" << endl;
	}
	hundir(0);
	
}

/*!
	\brief Incrementa las donaciones del donante en la cima en 1.
			Luego actualiza el orden del montículo
	\pre El montículo no está vacío
	\warning Método no definido en la interfaz de la clase
	\return Nada
*/	
void MonticuloDonantes::realizarDonacion() {

    Donante d = monticulo_.front();
	int donaciones = d.getDonaciones() + 1;
	monticulo_[0].setDonaciones(donaciones);
	
	// Se encarga de actualizar el orden del monticulo en el caso de que cambie
	hundir(0);

}
} // Fin namespace ed
