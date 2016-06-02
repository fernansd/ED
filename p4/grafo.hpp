#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <string>
#include <limits> // Para el valor numérico infinito

#include "vertice.hpp"
#include "grafoInterfaz.hpp"

namespace ed {

using std::vector;
using std::string;

/*!
    \class Grafo grafo.hpp "./grafo.hpp"
    \brief Clase que implementa la Clase abstracta GrafoInterfaz. Permite,
            la creación de un grafo, así como la interacción con el mismo.
            Sin embargo, no permite el borrado de vértices.
            El grafo puede tanto dirigido como no dirigido.
*/
class Grafo : public GrafoInterfaz {

	private:
	    /// Esta variable indica si el grafo es o no dirigido, true si es dirigido
		bool es_dirigido_;
		/// Apunta al vertice actual, mutable para permitir grafos constantes
		mutable size_t cursor_;
		/// Vector que contiene los vértices del grafo
		vector<Vertice<string>> vertices_;
	    /// Matriz de adyacencia del grafo de cada instacia de la clase
		vector<vector<double>> matriz_;

	public:
		Grafo() {
			cursor_ = 0;
			// Por defecto el grafo es no dirigido
			es_dirigido_ = false;
		}
		
		/*!
		    \brief Devuelve la posición del cursor interno del grafo
		    \return El valor devuelto es un entero positivo del tipo size_t
		*/
		size_t getCursor() const { return cursor_; }
		
		/*!
		    \brief Permite cambiar el valor del cursor interno del grafo
		    \warning Si se establece un valor incorrecto, el comportamiento
		            no está definido. Valores incorrectos son aquellos que no
		            identifiquen una posición dentro del vector de vértices
		*/
		void setCursor(size_t cur) const { cursor_ = cur; }

		/*!
		    \brief Permite fijar el comportamiento del grafo a grafo dirigido
		    \warning Si se cambia el tipo de grafo el comportamiento no
		            está definido.
		*/
		void hacerDirigido() { es_dirigido_ = true; }
		
		/*!
		    \brief Permite fijar el comportamiento del grafo a grafo no dirigido
		    \warning Si se cambia el tipo de grafo el comportamiento no
		            está definido.
		*/
		void hacerNoDirigido() { es_dirigido_ = false; }

		/// Devuelve un valor entero como número de vértices
		int numVertices() const { return vertices_.size(); }
		
		/// Devuelve un valor entero como número de lados en el grafo
		int numLados() const;
		
		/// Devuelve true en caso de que el grafo esté fijado a grafo dirigido
		bool esDirigido() const { return es_dirigido_; }
		
		/// Devuelve true si el grafo no contiene ningún vértice
		bool estaVacio() const { return vertices_.empty(); }

		/*!
			\brief Devuelve el peso del lado que une dos vértices, si no están
					unidos devolverá std::numeric_limits<double>::infinity()
			\return Peso del lado con tipo double
		*/
		double adyacente(Vertice<string> const v1, Vertice<string> const v2) const;

		/*!
			\brief Devuelve el vértice donde está situado el cursor, si el grafo
					está vacío entonces devuelve un vértice con etiqueta -1
			\return Devuelve el vértice con tipo Vertice<string>
		*/
		Vertice<string> verticeCursor() const;

		/*!
			\brief Añade un nuevo vértice al grafo
			\return Nada
		*/
		void addVertice(Vertice<string> const v);

		/*!
			\brief Une dos vértices existentes en el grafo, si no encuentra
					alguno de los vértices, no realizar ninguna acción y
					devuelve false. Se puede pasar como parámetro opcional
					el peso del lado, su valor por defecto será 0.
			\return Devuelve true si ha tenido éxito
		*/
		bool addLado(Vertice<string> const v1, Vertice<string> const v2,
		    double peso = 0);

		/*! \brief Situa el cursor en el vertice cuyo contenido
			es el proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		bool buscarVertice(string nombre) const;

		/*! \brief Situa el cursor en el vertice igual al proporcionado
			\return Devuelve true si encuentra el vertice
		*/
		bool goTo(Vertice<string> const v) const;

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
			\brief Devuelve true, cuando al usar verticeSiguiente() se estaría
			        accediendo a un vértice no existente.
			\return Valor booleano, que será true si se está en el último vértice
		*/
		bool quedanVertices();
		
		/*!
			\brief Permite obtener un vector con todos los vértices adyacentes
			        al vértice apuntado por el cursor interno del grafo
			\return Devuelve un vector de tipo std::vector<Vertice<string>>
		*/
		vector<Vertice<string>> obtenerAdyacentes();
		
		/*!
			\brief Devuelve la matriz de adyacencia del grafo
			\return El tipo devuelto es vector<vector<double>>
		*/
		vector<vector<double>> devuelveMatriz() { return matriz_; }
		
		/*!
			\brief Devuelve el vector que contiene a los vértices del grafo
			\return El tipo devuelto es vector<Vertice<string>>
		*/
		vector<Vertice<string>> devuelveVertices() { return vertices_; }
		
		/*!
		    \brief Función que imprime por pantalla el camino más corto entre
		            dos vértices del grafo. Requiere que se le proporcione
		            un grafo, la matriz de distancias, una matriz de intermedios
		            un nodo de origen y otro nodo como destino.
		    \warning Se esperan matrices resultado de aplicar el algoritmo de Floyd
		    \sa aplicarFloyd()
		*/
		friend void caminoMinimo(Grafo &g, vector<vector<double>> &m_dist,
	        vector<vector<int>> &m_intm, Vertice<string> &origen, 
	        Vertice<string> &destino);
};
} // Fin namespace ed


#endif
