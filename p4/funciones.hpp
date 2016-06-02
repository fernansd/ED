#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <vector>

#include "vertice.hpp"
#include "grafo.hpp"

#include "macros.hpp"

namespace ed {

/*!
	\brief Función que aplica el algoritmo de Floyd sobre un grafo. Para 
			devolver los resultados se le pasan por referencia una matriz de
			distancias y una matriz de intermedios.
*/
void aplicarFloyd(Grafo &g, vector<vector<double>> &m_dist, 
	vector<vector<double>> &m_intm);

/*!
	\brief Función que imprime por pantalla la distancia entre dos nodos que
			pide al usuario. Luego muestra el camino que se debe recorrer
			para llegar del inicio al fin.
*/
void caminoMinimo(Grafo &g, vector<vector<double>> &m_dist,
	vector<vector<double>> &m_intm, Vertice<string> &origen, 
	Vertice<string> &destino);

/*!
	\brief Opción del menú principal que se encarga de cargar un grafo 
			desde un fichero que pregunta al usuario.
*/
void opcionCargarGrafoFichero(Grafo &grafo);

/*!
	\brief Opción del menú principal que se encarga de mostrar el grafo
			por pantalla. Si el grafo está vacío dará el mensaje correspondiente.
*/
void opcionMostrarGrafo(Grafo &grafo);

/*!
	\brief Opción que se encarga de usar las funciones relacionadas con el
			algoritmo de Floyd.
	\sa aplicarFloyd(), caminoMinimo()
*/
void opcionAplicarFloyd(Grafo &grafo);

/*! 
    \brief Detiene la ejecución del programa hasta que el usuario presione la
            la tecla ENTER. Además se lo indica mediante un mensaje en la parte
            inferior de la pantalla. 
            Puede recibir un parámetro cuyo valor por
            defecto es 0. En este caso dejará no borrará el contenido del
            terminal antes de imprimir el mensaje. En caso de que valga 1,
            si lo borrará.
	\param opc Si vale 1, borrará la pantalla pantalla antes de seguir
	\return Nada
*/
void esperarUsuario(int opc = 0);
	
} // Fin namespace ed
#endif
