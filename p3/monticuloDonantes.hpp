#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <vector>

#include "monticuloDonantesInterfaz.hpp"

namespace ed {

class MonticuloDonantes : public MonticuloDonantesInterfaz {
	private:
		/*!
			\brief Devuelve la posición dentro del vector del donante pasado por
					referencia. Devolverá -1 en caso de que no encuentre el
					Donante dentro del montículo.
			\params d Donante que hay que buscar
			\return Posición del donante dentro del vector
		*/
		int getPos(const Donante& d);
		
		/*!
			\brief Devuelve la posición del hijo derecho del nodo cuya posición
					se ha pasado por parámetro
			\params pos_padre Posición del nodo padre
			\warning Puede devolver posiciones no existentes
			\return Devuelve un entero como la posición
		*/
		int hijoIzquierdo(const int pos_padre);
		
		/*!
			\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
					se ha pasado por parámetro
			\params pos_padre Posición del nodo padre
			\warning Puede devolver posiciones no existentes
			\return Devuelve un entero como la posición
		*/
		int hijoDerecho(const int pos_padre);
		
		/*!
			\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
					se ha pasado por parámetro
			\params pos_padre Posición del nodo padre
			\warning Puede devolver posiciones no existentes
			\return Devuelve un entero como la posición
		*/
		int padre(const int pos_hijo);
		
		/*!
			\brief Flota el nodo cuya posición se ha pasado por parámetro
			\params i Posición del nodo a flotar
			\return Nada
		*/
		void flotar(const int i);
		
		/*!
			\brief Hunde el nodo cuya posición se proporciona por parámetro
			\params i Posición del nodo a hundir
			\return Nada
		*/
		void hundir(const int i);
		
		
		/// Variable donde se almacena el montículo de donantes
		vector<Donante> monticulo_;
		
	public:
		MonticuloDonantes() {}
		
		/*!
			\brief Comprueba si el montículo esta vacio
			\params Ninguno
			\return Devuelve un valor booleano que será verdadero si esta vacío
		*/
		bool vacio() const { return monticulo_.empty(); }
	
		/*!
			\brief Devuelve una copia del donante que está en la cima
			\params Ninguno
			\pre El montículo no está vacío
			\return Devuelve el Donante que se encuentre en la cima del montículo
		*/
		Donante cima() const;
	
		/*!
			\brief Permite insertar un nuevo Donante en el montículo
			\params d Donante que se va a insertar
			\return Nada
		*/	
		void insertar(const Donante &d);
	
		/*!
			\brief Borra el Donante en la cima del montículo
			\params Ninguno
			\pre El montículo no está vacío
			\return Nada
		*/	
		void borrar();
		
		/*!
			\brief Lee el montículo de un fichero cuyo nombre se ha pasado
					por parámetro. El formato del fichero será: 
					Apellidos, Nombre, Grupo, Factor RH, nº donanciones
			\params nombre_fichero Nombre del archivo de donde leer el montículo
			\pre El montículo no está vacío
			\return Nada
		*/	
		void leerMonticulo(string nombre_fichero);
		
		/*!
			\brief Escribe el montículo en un fichero cuyo nombre se ha pasado
					por parámetro. El formato del fichero será: 
					Apellidos, Nombre, Grupo, Factor RH, nº donanciones
			\params nombre_fichero Nombre del archivo donde grabar el montículo
			\pre El montículo no está vacío
			\return Nada
		*/	
		void grabarMonticulo(string nombre_fichero);
		
		/*!
			\brief Incrementa las donaciones del donante en la cima en 1.
					Luego actualiza el orden del montículo
			\params Ninguno
			\pre El montículo no está vacío
			\warning Método no definido en la interfaz de la clase
			\return Nada
		*/	
		void realizarDonancion();

};
} // Fin namespace ed
#endif
