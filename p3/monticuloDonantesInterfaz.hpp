#ifndef MONTICULODONANTESINTERFAZ_HPP
#define MONTICULODONANTESINTERFAZ_HPP

#include "donante.hpp"

namespace ed {

/*! 
\brief Clase abstracta interfaz para la clase MonticuloDonantes
\sa ed::MonticuloDonantes
*/
class MonticuloDonantesInterfaz {
	
	/*!
		\brief Comprueba si el montículo esta vacio
		\return Devuelve un valor booleano que será verdadero si esta vacío
	*/	
	virtual bool vacio() const = 0;
	
	/*!
		\brief Indica que donante está en la cima
		\return Devuelve el Donante que se encuentre en la cima del montículo
	*/	
	virtual Donante cima() const = 0;
	
	/*!
		\brief Permite insertar un nuevo Donante en el montículo
		\param d Donante que se va a insertar
		\return Nada
	*/	
	virtual void insertar(const Donante &d) = 0;
	
	/*!
		\brief Borra el Donante en la cima del montículo
		\return Nada
	*/	
	virtual void borrar() = 0;
	
};
} // Fin namespace ed
#endif
