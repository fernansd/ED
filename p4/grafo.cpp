#include <limits>
#include <vector>

#include "grafo.hpp"
#include "vertice.hpp"

namespace ed {

	int Grafo::numLados() const {
	    if ( this->estaVacio() )
	        return 0;

	    int num_lados = 0;   
	    double infinito = std::numeric_limits<double>::infinity();
	    // Recorre todos los elementos de la matriz buscando aquellos que
	    // representen lados entre dos vértices
        for (vector<double> vector : matriz_) {
            for (double peso : vector) {
                if ( peso != infinito && peso != 0)
                    num_lados++;
            }
        
        }
        
        if ( esDirigido() ) {
            return num_lados;
        } else {
            // Al ser no dirigido solo puede haber un lado entre dos vértices
            return num_lados / 2;
        }
	}

    /*!
        \brief Devuelve el peso del lado que une dos vértices, si no están
                unidos devolverá std::numeric_limits<double>::infinity().

        \return Peso del lado con tipo double
    */
    double Grafo::adyacente(Vertice<string> const v1,
        Vertice<string> const v2) const {
        int aux = this->getCursor();
        
        // goTo devuelve false si no encuentra el vértice, por lo que
        // si se cumple la condición los dos vértice existen
        if ( goTo(v1) && goTo(v2) ) {
            this->setCursor(aux);
            return matriz_[v1.getLabel()][v2.getLabel()];
            
        } else {
            // En este caso al no existir los dos vértices también se devuelve
            // infinito haciendo referencia a que no están conectados.
            return std::numeric_limits<double>::infinity();
        }
    }

    /*!
        \brief Devuelve el vértice donde está situado el cursor, si el grafo
                está vacío entonces devuelve un vértice con etiqueta -1
        \return Devuelve el vértice con tipo Vertice<string>
    */
    Vertice<string> Grafo::verticeCursor() const {
        if ( cursor_ >= 0 && cursor_ < vertices_.size() ) {
            return vertices_[cursor_];
        } else {
            // Devuelve un vértice inválido (etiqueta igual a -1)
            Vertice<string> aux(-1,"");
            return aux;
        }
    }

    /// Mutators
    /*!
        \brief Añade un nuevo vértice al grafo
        \return Nada
    */
    void Grafo::addVertice(Vertice<string> const v) {
        // Insertamos el vértice en el vector de vértices
        vertices_.push_back(v);
        
        // Comprobamos si la matriz está vacía (es el primer vértice )
        if (matriz_.empty()) {
            // El primer vértice tiene coste 0 consigo mismo
            matriz_.push_back(
                vector<double>(1, 0));
            // Ya no se necesitan hacer más operaciones cuando se inserta
            // el primer vértice
            return;
        }

        // Inserta un nuevo elemento en cada fila de los vértices
        // inicialmente vale infinito. Representa un enlace con el nuevo
        // vértice insertado
        for (size_t i = 0; i < matriz_.size(); i++) {
            matriz_[i].push_back(std::numeric_limits<double>::infinity());
        }
        // Crea un vector para los lados del nuevo vértice
        vector<double> aux(vertices_.size(),
                            std::numeric_limits<double>::infinity());
        // Cada nodo consigo mismo se une con coste 0
        aux[aux.size()-1] = 0;
        matriz_.push_back(aux);

    }

    /*!
        \brief Une dos vértices existentes en el grafo, si no encuentra
                alguno de los vértices, no realizar ninguna acción y
                devuelve false
        \return Devuelve true si ha tenido éxito
    */
    bool Grafo::addLado(Vertice<string> const v1, Vertice<string> const v2,
        double peso) {
        
        // Permite restablecer el estado del cursor
        int cursor_previo = this->getCursor();
        
        int cursor_v1, cursor_v2;
        cursor_v1 = cursor_v2 = 0;
        
        // Comprobamos si existen los dos vertices
        if ( !(this->goTo(v1)) ) {
            return false;
        } else {
            cursor_v1 = this->getCursor();
        }
        if ( !(this->goTo(v2)) ) {
            return false;
        } else {
            cursor_v2 = this->getCursor();
        }

        // Solo se ejecuta si existen los dos vértices
        matriz_[cursor_v1][cursor_v2] = peso;
        
        // Si el grafo no es dirigido entonces la matriz de adyacencia debe
        // de ser simétrica
        if ( !esDirigido() ) {
            matriz_[cursor_v2][cursor_v1] = peso;
        }
        
        // Devuelve el cursor a su estado anterior
        this->setCursor(cursor_previo);
		return true;

    }

    /*! \brief Situa el cursor en el vertice cuyo contenido
        es el proporcionado
        \return Devuelve true si encuentra el vertice
    */
    bool Grafo::buscarVertice(string nombre) const {
		
		// Recorre el vector de vértices en busca de uno con el mismo nombre
		// Usa el vector de vértices directamente para evitar alterar el
		// estado del cursor.
		for (size_t i = 0; i < vertices_.size(); i++) {
            // Si lo encuentra, sitúa el cursor encima y devuelve true
		    if ( vertices_[i].getData() == nombre ) {
		        this->setCursor(i);
		        return true;
		    }
		}
		
		// Si llega aquí devuelve false, porque no ha encontrado el vértice
		return false;
    }

    /*! \brief Situa el cursor en el vertice igual al proporcionado
        \return Devuelve true si encuentra el vertice
    */
    bool Grafo::goTo(Vertice<string> const v) const {
        if ( this->estaVacio() )
            return false;
        
        for (size_t i = 0; i < vertices_.size(); i++) {
            Vertice<string> aux = vertices_[i];
            if ( v == aux ) {
                // Situa el cursor en el vértice buscado
                this->setCursor(i);
                return true;
            }
        }
        // Si llega aquí no ha encontrado el vértice
        return false;
    }

    /*!
        \brief Situa el cursor en el inicio y devuelve el vertice.
                Si la lista está vacía devuelve un vértice con etiqueta -1
        \return Vertice en el cursor de tipo Vertice<string>
    */
    Vertice<string> Grafo::verticeInicio() {
        // Si está vacio el grafo devuelve un vértice nulo
        if ( this->estaVacio() ) {
            Vertice<string> aux(-1,"");
            return aux;        
        } else {
            // Situa el cursor en el inicio y devuelve el vértice inicial
            this->setCursor(0);
            return vertices_[0];
        }
    }

    /*!
        \brief Mueve el cursor al siguiente y devuelve el vertice.
                Si está en el final de la lista, devuelve un vertice con el
                valor de la etiqueta igual a -1. Si el cursor ya está al
                final del vector entonces no se moverá.
        \return Vertice en el cursor de tipo Vertice<string>
    */
    Vertice<string> Grafo::verticeSiguiente() {
        if ( cursor_ == (vertices_.size() -1) ) {
            Vertice<string> aux(-1,"");
            return aux;
        }
        cursor_++;
        return verticeCursor();
    }

	/*!
		\brief Devuelve true, cuando al usar verticeSiguiente() se estaría
		        accediendo a un vértice no existente.
		\return Valor booleano, que será true si se está en el último vértice
	*/
    bool Grafo::quedanVertices() {
        // Si está en el final o no hay vértices devuelve falso
        if ( cursor_ == (vertices_.size() -1) || vertices_.size() == 0)
            return false;
        else
            return true;
    }
    
    /*!
    	\brief Devuelve un vector con los vértices adyacentes al vértice
    			seleccionado por el cursor interno del grafo.
    */
    vector<Vertice<string>> Grafo::obtenerAdyacentes() {
        vector<Vertice<string>> adyacentes;
        double infinito = std::numeric_limits<double>::infinity();
        
        for (size_t i = 0; i < matriz_.size(); i++) {
            if ( matriz_[cursor_][i] != infinito && matriz_[cursor_][i] != 0) {
                adyacentes.push_back(vertices_[i]);
            }
        }
        
        return adyacentes;
    }

}
