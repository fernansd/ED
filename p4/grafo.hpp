#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <string>
#include <limits> // Para el valor numérico infinito

#include "vertice.hpp"

// Poner documentación de fichero
namespace ed {

using std::vector;
using std::string;

// Documentar clase
class Grafo {

	private:
		bool es_dirigido_;
		/// Apunta al vertice actual, mutable para permitir
		/// grafos constantes
		mutable size_t cursor_;
		int etiqueta_actual_;
		vector<Vertice<string>> vertices_;
		vector<vector<double>> matriz_;

		size_t getCursor() const { return cursor_; }
		void setCursor(size_t cur) const { cursor_ = cur; }
		bool existe(Vertice<string> const &v);

	public:
		Grafo() {
			etiqueta_actual_ = 0;
			cursor_ = 0;
			// Por defecto el grafo es no dirigido
			es_dirigido_ = false;
		}

		/// Creators
		void hacerDirigido() { es_dirigido_ = true; }
		void hacerNoDirigido() { es_dirigido_ = false; }

		/// Observers
		int numVertices() const { return vertices_.size(); }
		int numLados() const { return matriz_.size(); }
		bool esDirigido() { return es_dirigido_; }
		bool estaVacio() { return vertices_.empty(); }

		/*!
			\brief Devuelve el peso del lado que une dos vértices, si no están
					unidos devolverá std::numeric_limits<double>::infinity()
			\return Peso del lado con tipo double
		*/
		double adyacente(Vertice<string> const &v1, Vertice<string> const &v2) const;

		/*!
			\brief Devuelve el vértice donde está situado el cursor, si el grafo
					está vacío entonces devuelve un vértice con etiqueta -1
			\return Devuelve el vértice con tipo Vertice<string>
		*/
		Vertice<string> verticeCursor() const;

		/// Mutators
		/*!
			\brief Añade un nuevo vértice al grafo
			\return Nada
		*/
		void addVertice(Vertice<string> const &v);

		/*!
			\brief Une dos vértices existentes en el grafo, si no encuentra
					alguno de los vértices, no realizar ninguna acción y
					devuelve false
			\return Devuelve true si ha tenido éxito
		*/
		bool addLado(Vertice<string> const &v1, Vertice<string> const &v2);

		/*! \brief Situa el cursor en el vertice cuyo contenido
			es el proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		bool buscarVertice(string nombre) const;

		/*! \brief Situa el cursor en el vertice igual al proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		bool goTo(Vertice<string> const &v) const;

		/*!
			\brief Situa el cursor en el inicio y devuelve el vertice.
					Si la lista está vacía devuelve un vértice con etiqueta -1
			\return Vertice en el cursor de tipo Vertice<string>
		*/
		Vertice<string> verticeInicio();

		/*!
			\brief Mueve el cursor al siguiente y devuelve el vertice.
					Si está en el final de la lista, devuelve un vertice con el
					valor de la etiqueta igual a -1. Si el cursor ya está al
					final del vector entonces no se moverá.
			\return Vertice en el cursor de tipo Vertice<string>
		*/
		Vertice<string> verticeSiguiente();

		/*!
			Indefinido
		*/
		bool afterEndVertex();
};
} // Fin namespace ed


#endif
