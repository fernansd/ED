#ifndef GRAFOINTERFAZ_HPP
#define GRAFOINTERFAZ_HPP

#include <string>

#include "vertice.hpp"

// Poner documentación de fichero
namespace ed {

using std::string;

// Documentar clase
class GrafoInterfaz {
	public:
		/// Creators
		virtual void hacerDirigido() = 0;
		virtual void hacerNoDirigido() = 0;
		
		/// Observers
		virtual int numVertices() const = 0;
		virtual int numLados() const = 0;
		virtual bool esDirigido() const = 0;
		virtual bool estaVacio() const = 0;

		/*!
			\brief Devuelve el peso del lado que une dos vértices, si no están
					unidos devolverá std::numeric_limits<double>::infinity()
			\return Peso del lado con tipo double
		*/
		virtual double adyacente(Vertice<string> const &v1, Vertice<string> const &v2) const = 0;

		/*!
			\brief Devuelve el vértice donde está situado el cursor, si el grafo
					está vacío entonces devuelve un vértice con etiqueta -1
			\return Devuelve el vértice con tipo Vertice<string>
		*/
		virtual Vertice<string> verticeCursor() const = 0;

		/// Mutators
		/*!
			\brief Añade un nuevo vértice al grafo
			\return Nada
		*/
		virtual void addVertice(Vertice<string> const &v) = 0;

		/*!
			\brief Une dos vértices existentes en el grafo, si no encuentra
					alguno de los vértices, no realizar ninguna acción y
					devuelve false
			\return Devuelve true si ha tenido éxito
		*/
		virtual bool addLado(Vertice<string> const &v1, Vertice<string> const &v2) = 0;

		/*! \brief Situa el cursor en el vertice cuyo contenido
			es el proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		virtual bool buscarVertice(string nombre) const = 0;

		/*! \brief Situa el cursor en el vertice igual al proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		virtual bool goTo(Vertice<string> const &v) const = 0;

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
			Indefinido
		*/
		virtual bool afterEndVertex() = 0;
};
} // Fin namespace ed


#endif
