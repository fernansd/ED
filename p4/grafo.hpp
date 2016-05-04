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
		bool es_dirigido;
		/// Apunta al vertice actual, mutable para permitir grafos constantes
		mutable int cursor_;
		vector<Vertice<string>> vertices_;
		vector<vector<double>> matriz_;
	public:
		Grafo() {
			double inf = std::numeric_limits<double>::infinity();
			// Por defecto el grafo es no dirigido
			es_dirigido = false;
		}
	
		/// Creators
		void hacerDirigido() { es_dirigido = true; }
		void hacerNoDirigido() { es_dirigido = false; }
		
		/// Observers
		int numVertices() const { return vertices_.size(); }
		int numLados() const { return matriz_.size(); }
		bool esDirigido() { return es_dirigido; }
		bool estaVacio() { return vertices_.empty(); }
		int adyacente() const;
		Vertice<string> verticeCursor() const;
		
		/// Mutators
		void addVertice();
		void addLado();
		bool buscarVertice() const;
		bool goTo() const;
		Vertice<string> verticeInicio();
		Vertice<string> verticeSiguiente();
		bool afterEndVertex();
};
} // Fin namespace ed
