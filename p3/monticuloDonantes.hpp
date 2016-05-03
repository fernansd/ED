#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include <vector>

#include "monticuloDonantesInterfaz.hpp"

namespace ed {

class MonticuloDonantes : public MonticuloDonantesInterfaz {
	private:
		int getPos(const Donante& d);
		
		int hijoIzquierdo(const unsigned int pos_padre);
		
		int hijoDerecho(const unsigned int pos_padre);
		
		int padre(const unsigned int pos_hijo);
		
		void flotar(const unsigned int i);
		
		void hundir(const unsigned int i);
		
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
			\brief Indica que donante está en la cima
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
		
		void leerMonticulo(string nombre_fichero);
		
		void grabarMonticulo(string nombre_fichero);

};
} // Fin namespace ed
#endif
