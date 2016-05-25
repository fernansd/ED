#include "funciones.hpp"

#include <cstdio>
#include <iostream>

#include "grafo.hpp"
#include "macros.hpp"


// Incluye de la librería estándar lo necesario para interaccionar con el usuario
using std::endl;
using std::cout;
using std::cin;

namespace ed {

void aplicarFloyd(Grafo &g, vector<vector<double>> &m_dist, 
	vector<vector<int>> &m_intm) {
	
	int n_vertices = g.numVertices();
	
	for (int k = 0; k < n_vertices; k++) {
		for (int i = 0; i < n_vertices; i++) {
			for (int j = 0; j < n_vertices; j++) {
			
				if ( m_dist[i][k] + m_dist[k][j] < m_dist[i][j] ) {
				
					m_dist[i][j] = m_dist[i][j] + m_dist[k][j];
					m_intm[i][j] = k;
				}
			}
		}
	}
	return;
}
	
void caminoMinimo(Grafo &g, vector<vector<double>> &m_dist,
	vector<vector<int>> &m_intm, Vertice<string> &origen, 
	Vertice<string> &destino) {
	
	g.goTo(origen);
	int pos_origen = g.getCursor();
	
	g.goTo(destino);
	int pos_destino = g.getCursor();
	
	cout << "La distancia entre los dos vertices es: ";
	cout << m_dist[pos_origen][pos_destino] << endl;
	
	vector<int> camino;
	int siguiente_nodo = pos_origen;
	while (true) {
	
		camino.push_back(m_intm[siguiente_nodo][pos_destino]);
		
		siguiente_nodo = m_intm[siguiente_nodo][pos_destino];
		if ( siguiente_nodo == 0 )
			break;
	}
	camino.push_back(pos_destino);
	
	cout << "El camino es:" << endl;
	
	for (int nodo : camino) {
	    cout << g.vertices_[nodo].getData() << endl;
	}
	
	return;
}

void opcionCargarGrafoFichero(Grafo &grafo) {
    return;
}

void opcionMostrarGrafo(Grafo &grafo) {
    return;
}

void opcionAplicarFloyd(Grafo &grafo) {
    return;
}

/*! 
    \brief Detiene la ejecución del programa hasta que el usuario presione la
            la tecla ENTER. Además se lo indica mediante un mensaje en la parte
            inferior de la pantalla. 
            Puede recibir un parámetro cuyo valor por
            defecto es 0. En este caso dejará no borrará el contenido del
            terminal antes de imprimir el mensaje. En caso de que valga 1,
            si lo borrará.
	\params opc Si vale 1, borrará la pantalla pantalla antes de seguir
	\return Nada
*/
void esperarUsuario(int opc) {
    
    if (opc == 1) 
        BORRAR;
        
    LUGAR(23,25);
    printf("pulse ");
    SUBRAYADO;
    printf("ENTER");
    APAGA;
    printf(" para ");
    INVERSO;
    printf("continuar");
    APAGA;
    getchar();
    BORRAR;
}

} // Fin namespace ed
