#ifndef VERTICE_HPP
#define VERTICE_HPP

namespace ed {

/*!
    \brief Esta clase representa un vértice para ser usado dentro de un grafo.
            Permite guardar datos los cuales indentificarán al vértice, así
            como una etiqueta que permite almacenar información extra sobre
            las características del vértice.
*/
template<class T>
class Vertice {
	private:
		T data_; /// Miembro que almacena los datos del vértice
		int label_; /// Miembro que permite dar información extra sobre el vértice

	public:
		Vertice() {
			data_ = T();
			label_ = 0;
		}
		
		/// Permite crear un vertice proporcionando los datos del mismo
		Vertice(T datos) {
		    data_ = datos;
		    label_ = 0;
		}

        /// Permite darle valores a los miembros del vértice
		Vertice(int etiqueta = 0, T datos = T()) {
			data_ = datos;
			etiqueta = etiqueta;
		}

		/*!
			\brief Devuelve el contenido del vértice
			\return Contenido del vértice
		*/
		T getData() const { return data_; }

		/*!
			\brief Devuelve la etiqueta del vértice
			\post La etiqueta del vértice debe ser única en el grafo
			\return Valor de la etiqueta con tipo de entero
		*/
		int getLabel() const { return label_; }

		/*!
			\brief Cambia el contenido del vértice por el pasado por referencia
			\return Nada
		*/
		void setData(T const &d) { data_ = d; }

		/*!
			\brief Cambia el valor de la etiqueta.
			\return Nada
		*/
		void setLabel(int etiqueta) { label_ = etiqueta; }

		/*!
			\brief Compara los vértices por el valor de su contenido
			\return Devuelve true si son iguales
		*/
		bool operator==(Vertice<T> &v) const {

			if ( this->getData() == v.getData() )
				return true;
			else
				return false;
		}

};
} // Fin namespace ed

#endif
