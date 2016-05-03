#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <vector>

#include "monticuloDonantesInterfaz.hpp"

namespace ed {

/*! 
\brief Clase que representa un montículo cuyos nodos son elementos de la clase
        Donante. Implementa la interfaz especificada en MonticuloDonantesInterfaz
\sa ed::Donante ed::MonticuloDonantesInterfaz
*/
class MonticuloDonantes : public MonticuloDonantesInterfaz {
	private:
		/*!
			\brief Devuelve la posición dentro del vector del donante pasado por
					referencia. Devolverá -1 en caso de que no encuentre el
					Donante dentro del montículo.
			\param d Donante que hay que buscar
			\return Posición del donante dentro del vector
		*/
		int getPos(const Donante &d);
		
		/*!
			\brief Devuelve la posición del hijo derecho del nodo cuya posición
					se ha pasado por parámetro
			\param pos_padre Posición del nodo padre
			\warning Puede devolver posiciones no existentes
			\return Devuelve un entero como la posición
		*/
		int hijoIzquierdo(const unsigned int pos_padre);
		
		/*!
			\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
					se ha pasado por parámetro
			\param pos_padre Posición del nodo padre
			\warning Puede devolver posiciones no existentes
			\return Devuelve un entero como la posición
		*/
		int hijoDerecho(const unsigned int pos_padre);
		
		/*!
			\brief Devuelve la posición del hijo izquierdo del nodo cuya posición
					se ha pasado por parámetro
			\param pos_padre Posición del nodo padre
			\warning Puede devolver posiciones no existentes
			\return Devuelve un entero como la posición
		*/
		int padre(const unsigned int pos_hijo);
		
		/*!
			\brief Flota el nodo cuya posición se ha pasado por parámetro
			\param i Posición del nodo a flotar
			\return Nada
		*/
		void flotar(const unsigned int i);
		
		/*!
			\brief Hunde el nodo cuya posición se proporciona por parámetro
			\param i Posición del nodo a hundir
			\return Nada
		*/
		void hundir(const unsigned int i);
		
		/// Variable donde se almacena el montículo de donantes
		vector<Donante> monticulo_;
		
	public:
		MonticuloDonantes() {}
		
		/*!
			\brief Comprueba si el montículo esta vacio
			\return Devuelve un valor booleano que será verdadero si esta vacío
		*/
		bool vacio() const { return monticulo_.empty(); }
	
		/*!
			\brief Devuelve una copia del donante que está en la cima
			\pre El montículo no está vacío
			\return Devuelve el Donante que se encuentre en la cima del montículo
		*/
		Donante cima() const;
	
		/*!
			\brief Permite insertar un nuevo Donante en el montículo
			\param d Donante que se va a insertar
			\return Nada
		*/	
		void insertar(const Donante &d);
	
		/*!
			\brief Borra el Donante en la cima del montículo
			\pre El montículo no está vacío
			\return Nada
		*/	
		void borrar();
		
		/*!
			\brief Lee el montículo de un fichero cuyo nombre se ha pasado
					por parámetro. El formato del fichero será: 
					Apellidos, Nombre, Grupo, Factor RH, nº donanciones
			\param nombre_fichero Nombre del archivo de donde leer el montículo
			\pre El montículo no está vacío
			\return Nada
		*/	
		void leerMonticulo(string nombre_fichero);
		
		/*!
			\brief Escribe el montículo en un fichero cuyo nombre se ha pasado
					por parámetro. El formato del fichero será: 
					Apellidos, Nombre, Grupo, Factor RH, nº donanciones
			\param nombre_fichero Nombre del archivo donde grabar el montículo
			\pre El montículo no está vacío
			\return Nada
		*/	
		void grabarMonticulo(string nombre_fichero);
		
		/*!
			\brief Incrementa las donaciones del donante en la cima en 1.
					Luego actualiza el orden del montículo
			\pre El montículo no está vacío
			\warning Método no definido en la interfaz de la clase
			\return Nada
		*/	
		void realizarDonacion();

};
} // Fin namespace ed
#endif
