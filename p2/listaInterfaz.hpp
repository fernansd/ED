#ifndef LISTAINTERFAZ_HPP
#define LISTAINTERFAZ_HPP

using namespace std;

namespace ed {

/*!
    \class listaInterfaz listaInterfaz.hpp "./listaInterfaz.hpp"
    \brief Clase abstracta que define la interfaz para interaccionar con un
            TAD lista. Hace uso de plantillas para no limitar el tipo de
            elementos que pueden formar la lista.
*/
template< class T >
class listaInterfaz {
	public:
		
		/*! 
		\brief Devuelve el número de elementos en la lista.    
	 	\note Los parámetros tienen valores por defecto
		\pre Ninguna
		\post El valor devuelto está comprendido en [0, capacity()]
		*/
		virtual int size() const = 0;
		
		/*! 
		\brief Comprueba si la lista está vacía.
		\pre Ninguna
		\return Valor booleano que indica el estado de la lista.
		\post Devuelve true si size() == 0
		\post Devuelve false si size() > 0
		*/
		virtual bool isEmpty() const = 0;
		
		/*! 
		\brief Devuelve la posición del cursor
		\return Posición del cusor tipo entero
		*/
		virtual int getPos() const = 0;
		
		/*! 
		\brief Mueve el puntero a la posición proporcionada
		\param pos Posición donde mover el cursor
		\return Devuelve true si la posición es válida
		*/
		virtual bool goTo(int pos) = 0;
		
		/*!
		\brief Situa el puntero en el elemento proporcionado
		\param item Elemento a buscar en la lista
		\return Devuelve false si no lo encuentra
		*/
		virtual bool search(T item) = 0;
		
		/*!
		\brief Devuelve un puntero al elemento donde apunta el cursor
		\return Devuelve el puntero
		*/
		virtual T* getItem() const = 0;
		
		/*!
		\brief Devuelve un puntero al elemento siguiente donde apunta el cursor
		\return Devuelve el puntero
		*/
		virtual T* getPrev() const = 0;
		
		/*!
		\brief Devuelve unpuntero al elemento anterior donde apunta el cursor
		\return Devuelve el puntero
		*/
		virtual T* getNext() const = 0;
	    
	    /*!
		\brief Inserta el elemento proporcionado antes del elemento al cual
		        apunta el cursor
		\param item Elemento a insertar
		*/
		virtual void insertBefore(T const& item) = 0;
		
		/*!
		\brief Inserta el elemento proporcionado después del elemento al cual
		        apunta el cursor
		\param item Elemento a insertar
		*/
		virtual void insertAfter(T const& item) = 0;
		
		/// Elimina el elemento al cual apunta el cursor
		virtual void removeItem() = 0;


};
} // Fin namespace ed
#endif
