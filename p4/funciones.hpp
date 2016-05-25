#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <vector>

#include "vertice.hpp"
#include "grafo.hpp"

#include "macros.hpp"

namespace ed {

void aplicarFloyd(Grafo &g, vector<vector<double>> &m_dist, 
	vector<vector<double>> &m_intm);
	
void caminoMinimo(Grafo &g, vector<vector<double>> &m_dist,
	vector<vector<double>> &m_intm, Vertice<string> &origen, 
	Vertice<string> &destino);
	
void esperarUsuario(int opc = 0);

void opcionCargarGrafoFichero(Grafo &grafo);

void opcionMostrarGrafo(Grafo &grafo);

void opcionAplicarFloyd(Grafo &grafo);
	
} // Fin namespace ed
#endif
