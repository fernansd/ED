#ifndef GRAFOINTERFAZ_HPP
#define GRAFOINTERFAZ_HPP

#include <string>

#include "vertice.hpp"

namespace ed {

using std::string;

/*!
    \class GrafoInterfaz grafoInterfaz.hpp "./grafoInterfaz.hpp"
    \brief Clase abstracta que define la interfaz de lo que sería una clase
            de grafo. Permite grafos tanto dirigidos como no dirigidos.
            El grafo se considera estático por lo que solo se modificará en la
            creación del mismo.
*/
class GrafoInterfaz {
	public:
		/*!
		    \brief Permite fijar el comportamiento del grafo a grafo dirigido
		    \warning Si se cambia el tipo de grafo el comportamiento no
		            está definido.
		*/
		virtual void hacerDirigido() = 0;
		
		/*!
		    \brief Permite fijar el comportamiento del grafo a grafo no dirigido
		    \warning Si se cambia el tipo de grafo el comportamiento no
		            está definido.
		*/
		virtual void hacerNoDirigido() = 0;
		
		/// Devuelve un valor entero como número de vértices
		virtual int numVertices() const = 0;
		
		/// Devuelve un valor entero como número de lados en el grafo
		virtual int numLados() const = 0;
		
		/// Devuelve true en caso de que el grafo esté fijado a grafo dirigido
		virtual bool esDirigido() const = 0;
		
		/// Devuelve true si el grafo no contiene ningún vértice
		virtual bool estaVacio() const = 0;

		/*!
			\brief Devuelve el peso del lado que une dos vértices, si no están
					unidos devolverá std::numeric_limits<double>::infinity()
			\return Peso del lado con tipo double
		*/
		virtual double adyacente(Vertice<string> const v1, Vertice<string> const v2) const = 0;

		/*!
			\brief Devuelve el vértice donde está situado el cursor, si el grafo
					está vacío entonces devuelve un vértice con etiqueta -1
			\return Devuelve el vértice con tipo Vertice<string>
		*/
		virtual Vertice<string> verticeCursor() const = 0;

		/*!
			\brief Añade un nuevo vértice al grafo
			\return Nada
		*/
		virtual void addVertice(Vertice<string> const v) = 0;

		/*!
			\brief Une dos vértices existentes en el grafo, si no encuentra
					alguno de los vértices, no realizar ninguna acción y
					devuelve false
			\return Devuelve true si ha tenido éxito
		*/
		virtual bool addLado(Vertice<string> const v1, Vertice<string> const v2,
		    double peso) = 0;

		/*! \brief Situa el cursor en el vertice cuyo contenido
			es el proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		virtual bool buscarVertice(string nombre) const = 0;

		/*! \brief Situa el cursor en el vertice igual al proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		virtual bool goTo(Vertice<string> const v) const = 0;

		/*!
			\brief Situa el cursor en el inicio y devuelve el vertice.
					Si la lista está vacía devuelve un vértice con etiqueta -1
			\return Vertice en el cursor de tipo Vertice<string>
		*/
		virtual Vertice<string> verticeInicio() = 0;

		/*!
			\brief Mueve el cursor al siguiente y devuelve el vertice.
					Si está en el final de la lista, devuelve un vertice con el
					valor de la etiqueta igual a -1. Si el cursor ya está al
					final del vector entonces no se moverá.
			\return Vertice en el cursor de tipo Vertice<string>
		*/
		virtual Vertice<string> verticeSiguiente() = 0;

		/*!
			\brief Devuelve true, cuando al usar verticeSiguiente() se estaría
			        accediendo a un vértice no existente.
			\return Valor booleano, que será true si se está en el último vértice
		*/
		virtual bool quedanVertices() = 0;
};
} // Fin namespace ed


#endif
