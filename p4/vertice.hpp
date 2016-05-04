// Poner documentación de fichero
namespace ed {

// Documentar clase
template<class T>
class Vertice {
	private:
		T data_;
		int label_;	
	
	public:
		/*!
			\brief Devuelve el contenido del vértice
			\return Contenido del vértice
		*/
		T getData() { return data_; }
		
		/*!
			\brief Devuelve la etiqueta del vértice
			\post La etiqueta del vértice debe ser única en el grafo
			\return Valor de la etiqueta con tipo de entero
		*/
		int getLabel() { return label_; }
		
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
		
};
} // Fin namespace ed
