#ifndef MONTICULODONANTES_HPP
#define MONTICULODONANTES_HPP

#include "monticuloDonantesInterfaz.hpp"

namespace ed {

class MonticuloDonantes : public MonticuloDonantesInterfaz {
	private:
		void flotar() { return; }
		
		void hundir() { return; }
		
	public:
		MonticuloDonantes() {}
		
		/*!
			\brief Comprueba si el montículo esta vacio
			\params Ninguno
			\return Devuelve un valor booleano que será verdadero si esta vacío
		*/
		bool vacio() const;
	
		/*!
			\brief Indica que donante está en la cima
			\params Ninguno
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
			\return Nada
		*/	
		void borrar();

};
} // Fin namespace ed
#endif
