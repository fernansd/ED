#include "funciones.hpp"
void aplicarFloyd(Grafo &g, vector<vector<double>> &m_dist, 
	vector<vector<int>> &m_intm) {
	
	int n_vertices = g.numVertices();
	
	for (int k = 0; k < n_vertices; k++) {
		for (int i = 0; i < n_vertices; i++) {
			for (int j = 0; j < n_vertices; j++) {
			
				if ( m_dist[i,k] + m_dist[k,j] < m_dist[i,j] ) {
				
					m_dist[i,j] = m_dist[i,j] + m_dist[k,j];
					m_intm[i,j] = k;
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
	cout << m_dist[pos_origen,pos_destino] << endl;
	
	vector<int> camino;
	int siguiente_nodo = pos_origen;
	while (true) {
	
		camino.push_back(m_intm[siguiente_nodo, pos_destino]);
		
		siguiente_nodo = m_intm[siguiente_nodo, pos_destino];
		if ( siguiente_nodo == 0 )
			break;
	}
	camino.push_back(pos_destino);
	
	return;
}
