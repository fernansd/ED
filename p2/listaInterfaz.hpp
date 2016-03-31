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
		virtual int capacity() const = 0;
		
		/*! 
		\brief Constructor que crea un Punto2D a partir de sus coordenadas x e y     
	 	\note Los parámetros tienen valores por defecto
		\pre Ninguna
		\post Valor entre comprendido en [0, capacity()]
		*/
		virtual int nItems() const = 0;
		
		/*! 
		\brief Constructor que crea un Punto2D a partir de sus coordenadas x e y     
	 	\note Los parámetros tienen valores por defecto
		\pre Ninguna
		\post Devuelve true si nItems() == capacity()
		\post Devuelve false si nItems() < capacity()
		*/
		virtual bool isFull() const = 0;
		
		virtual void insertFirst(T const& item) = 0;


};
} // Fin namespace ed
#endif
