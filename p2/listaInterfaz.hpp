#ifndef LISTAINTERFAZ_HPP
#define LISTAINTERFAZ_HPP

using namespace std;

namespace ed {

template< class T >
class listaInterfaz {
	public:

		/*! 
		\brief Constructor que crea un Punto2D a partir de sus coordenadas x e y
		\attention Función sobrecargada        
	 	\note Los parámetros tienen valores por defecto		
		\param x de tipo T, valor por defecto 0
		\param y de tipo T, valor por defecto 0
		\pre Ninguna
		\post Ninguna
		\sa setX(), setY()
		*/
		
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
		
		virtual int getPos() const = 0;
		
		virtual bool goTo(int pos) const = 0;
		
		virtual bool search(T item) const = 0;
		
		virtual T* getItem() const = 0;
		
		virtual T* getPrev() const = 0;
		
		virtual T* getNext() const = 0;
	
		virtual void insertBefore(T const& item) = 0;
		
		virtual void insertAfter(T const& item) = 0;
		
		virtual void removeItem() = 0;


};
} // Fin namespace ed
#endif
