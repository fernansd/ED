#include "grafo.hpp"
namespace ed {

    bool existe(Vertice<string> const &v);

    /*!
        \brief Devuelve el peso del lado que une dos vértices, si no están
                unidos devolverá std::numeric_limits<double>::infinity().

        \return Peso del lado con tipo double
    */
    double Grafo::adyacente(Vertice<string> const &v1,
        Vertice<string> const&v2) const {
        int aux = this->getCursor();
        // goTo devuelve false si no encuentra el vértice, por lo que
        // si se cumple la condición los dos vértice existen
        if ( goTo(v1) && goTo(v2) ) {
            this->setCursor(aux);
            return matriz_[v1.getLabel()][v2.getLabel()];
        } else {
            return -1;
        }
    }

    /*!
        \brief Devuelve el vértice donde está situado el cursor, si el grafo
                está vacío entonces devuelve un vértice con etiqueta -1
        \return Devuelve el vértice con tipo Vertice<string>
    */
    Vertice<string> Grafo::verticeCursor() const {
        return vertices_[cursor_];
    }

    /// Mutators
    /*!
        \brief Añade un nuevo vértice al grafo
        \return Nada
    */
    void Grafo::addVertice(Vertice<string> const &v) {
        vertices_.push_back(v);
        vertices_[vertices_.size()-1].setLabel(etiqueta_actual_);

        // Inserta un nuevo elemento en cada fila de los vértices
        // inicialmente vale infinito
        for (vector<double> vector : matriz_) {
            vector.push_back(std::numeric_limits<double>::infinity());
        }

        vector<double> aux(vertices_.size(),
                            std::numeric_limits<double>::infinity());
        matriz_.push_back(aux);

    }

    /*!
        \brief Une dos vértices existentes en el grafo, si no encuentra
                alguno de los vértices, no realizar ninguna acción y
                devuelve false
        \return Devuelve true si ha tenido éxito
    */
    bool Grafo::addLado(Vertice<string> const &v1, Vertice<string> const &v2) {
        // Comprobamos si existen los dos vertices
        if ( !(this->goTo(v1)) )
            return false;
        if ( !(this->goTo(v2)) )
            return false;

        // Solo se ejecuta si existen los dos vértices

		return true;

    }

    /*! \brief Situa el cursor en el vertice cuyo contenido
        es el proporcionado
        \return Devuelve true si encuentra el vertice
    */
    bool Grafo::buscarVertice(string nombre) const {
		return true;
    }

    /*! \brief Situa el cursor en el vertice igual al proporcionado
        \return Devuelve true si encuentra el vertice
    */
    bool Grafo::goTo(Vertice<string> const &v) const {
        if ( this->estaVacio() )
            return false;
        for (Vertice<string> v : vertices_) {
            break;
        }
        return true;
    }

    /*!
        \brief Situa el cursor en el inicio y devuelve el vertice.
                Si la lista está vacía devuelve un vértice con etiqueta -1
        \return Vertice en el cursor de tipo Vertice<string>
    */
    Vertice<string> Grafo::verticeInicio() {
        if ( this->estaVacio() )
            return Vertice<string>(-1);
        else
            this->setCursor(0);
            return vertices_[0];
    }

    /*!
        \brief Mueve el cursor al siguiente y devuelve el vertice.
                Si está en el final de la lista, devuelve un vertice con el
                valor de la etiqueta igual a -1. Si el cursor ya está al
                final del vector entonces no se moverá.
        \return Vertice en el cursor de tipo Vertice<string>
    */
    Vertice<string> Grafo::verticeSiguiente() {
        if ( cursor_ == (vertices_.size() -1) )
            return Vertice<string>(-1);
        cursor_++;
        return verticeCursor();
    }

    /*!
        Indefinido
    */
    bool Grafo::afterEndVertex() {
        return false;
    }

}
