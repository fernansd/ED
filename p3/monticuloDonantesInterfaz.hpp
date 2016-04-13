#ifndef MONTICULODONANTESINTERFAZ_HPP
#define MONTICULODONANTESINTERFAZ_HPP

#include "donante.hpp"

namespace ed {

class MonticuloDonantesInterfaz {
	
	/*!
		\brief Comprueba si el montículo esta vacio
		\params Ninguno
		\return Devuelve un valor booleano que será verdadero si esta vacío
	*/	
	virtual bool vacio() const = 0;
	
	/*!
		\brief Indica que donante está en la cima
		\params Ninguno
		\return Devuelve el Donante que se encuentre en la cima del montículo
	*/	
	virtual Donante cima() const = 0;
	
	/*!
		\brief Permite insertar un nuevo Donante en el montículo
		\params d Donante que se va a insertar
		\return Nada
	*/	
	virtual void insertar(const Donante &d) = 0;
	
	/*!
		\brief Borra el Donante en la cima del montículo
		\params Ninguno
		\return Nada
	*/	
	virtual void borrar() = 0;
	
};
} // Fin namespace ed
#endif
