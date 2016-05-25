#include "funciones.hpp"

#include <cstdio> // Librería para uso de las macros
#include <iostream> // Entrada y salida por consola
#include <fstream> // Manejar ficheros
#include <sstream> // Leer de fichero con stream

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
			
				if ( (m_dist[i][k] + m_dist[k][j]) < m_dist[i][j] ) {
				
					m_dist[i][j] = m_dist[i][k] + m_dist[k][j];
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
		
		if ( siguiente_nodo == -1 )
			break;
		
	}
	camino.push_back(pos_destino);
	
	cout << "El camino es:" << endl;
	
	for (size_t i = 0; i < camino.size(); i++) {
	    cout << g.vertices_[camino[i]].getData() << endl;
	}
	
	return;
}

void opcionCargarGrafoFichero(Grafo &grafo) {

    LUGAR(10,10);
    cout << "Introduce el nombre del fichero: " << endl;
    LUGAR(11,10);
    cout << "Grafos ejemplo: grafo_andalucia.txt / grafo_peninsula.txt" << endl;
    LUGAR(12,10);
    cout << "Elección -> ";
    
    string nombre_fichero;
    cin >> nombre_fichero;
    
    std::ifstream fichero(nombre_fichero);
    
    // Variable para almacenar las líneas leidas
    string linea;
    std::getline(fichero, linea);
    int num_vertices = atoi(linea.c_str());
    
    std::getline(fichero, linea);
    int dirigido = atoi(linea.c_str());
    if ( dirigido == 0 ) {
        grafo.hacerNoDirigido();
    } else {
        grafo.hacerDirigido();
    }
    
    for (int i = 0; i < num_vertices; i++) {
        std::getline(fichero, linea);
        Vertice<string> aux(linea);
        grafo.addVertice(aux);
    }
    if (grafo.numVertices() != num_vertices) {
        cout << "Error insertando vértices, reinicie el programa" << endl;
        return;
    }
    
    string origen, destino;
    double peso;
    while (std::getline(fichero, linea)) {
        std::istringstream stream_linea(linea);
        stream_linea >> origen >> destino >> peso;
        Vertice<string> aux1(origen), aux2(destino);
        grafo.addLado(aux1, aux2, peso);
    }
    
}

void opcionMostrarGrafo(Grafo &grafo) {
    LUGAR(2,0);
    cout << "Impresión del grafo (nodos: " << grafo.numVertices();
    cout << ", lados: " << grafo.numLados() << "):" << endl;
    
    LUGAR(4,2);
    grafo.verticeInicio();
    int n_lineas = 0;
    do {
        cout << "El nodo " << grafo.verticeCursor().getData();
        cout << " conecta con:" << endl;
        n_lineas += 2;
        
        vector<Vertice<string>> ady = grafo.obtenerAdyacentes();
        for (size_t i = 0; i < ady.size(); i++) {
            if ( i == (ady.size() -1)) {
                cout << ady[i].getData() << endl << endl;
                n_lineas++;
            } else {
                cout << ady[i].getData() << ",";
            }
        }
//        // Cuando se llena la pantalla se requiere que el usuario siga
//        // apretando enter para continuar
//        if ( n_lineas > 80 ) {
//            getchar();
//        }
        grafo.verticeSiguiente();
    // El bucle se detiene cuando se devuelven vertices inválidos
    } while (grafo.quedanVertices());
    
    cout << "El nodo " << grafo.verticeCursor().getData();
    cout << " conecta con:" << endl;
    vector<Vertice<string>> ady = grafo.obtenerAdyacentes();
    for (size_t i = 0; i < ady.size(); i++) {
        if ( i == (ady.size() -1)) {
            cout << ady[i].getData() << endl << endl;
            n_lineas++;
        } else {
            cout << ady[i].getData() << ",";
        }
    }
}

void opcionAplicarFloyd(Grafo &grafo) {
    vector<vector<double>> matriz_dist = grafo.devuelveMatriz();
    size_t dim = grafo.numVertices();
    
    vector<vector<int>> matriz_int(dim, vector<int>(dim, -1));
    
    // Usamos la función que aplica el algoritmo de Floyd-Warshall
    aplicarFloyd(grafo, matriz_dist, matriz_int);
    
    vector<double> suma_dist;
    size_t menor = 0;
    for (size_t i = 0; i < dim; i++) {
        int suma = 0;
        for (size_t j = 0; j < dim; j++) {
            if (matriz_dist[i][j] != std::numeric_limits<double>::infinity())
                suma += matriz_dist[i][j];
        }
        suma_dist.push_back(suma);
        if (suma < suma_dist[menor])
            menor = i;
    }
    
    cout << "El vértice con menor suma de distancias es: ";
    grafo.setCursor(menor);
    cout << grafo.verticeCursor().getData() << endl << endl;
    
    cout << "Suma de distancias para cada vértice:" << endl;
    grafo.verticeInicio();
    
    do {
        cout << "Suma para " << grafo.verticeCursor().getData() << " es ";
        cout << suma_dist[grafo.getCursor()] << endl << endl;
        grafo.verticeSiguiente();
    // El bucle se detiene cuando se devuelven vertices inválidos
    } while (grafo.quedanVertices());
    
    cout << "Suma para " << grafo.verticeCursor().getData() << " es ";
    cout << suma_dist[grafo.getCursor()] << endl << endl;
    
    /*
     *  Aquí empieza la segunda parte del apartado 3
     *  Pide mostrar la distancia y camino entre dos nodos proporcionados
     *  por el usuario a través del teclado.
     */
    
    cout << "Introduce el nombre de un vértice: ";
    string nombre1;
    cin >> nombre1;
    
    cout << "Introduce el nombre de otro vértice: ";
    string nombre2;
    cin >> nombre2;
    
    // Este método devuelve true en caso de que encuentre el vértice y
    // deja el cursor apuntandole
    if (grafo.buscarVertice(nombre1)) {
        Vertice<string> v1 = grafo.verticeCursor();
        
        if (grafo.buscarVertice(nombre2)) {
            // Si entra aquí existen los dos vértices
            Vertice<string> v2 = grafo.verticeCursor();
            
            // Busca el camino mínimo entre los vértices proporcionados
            // e imprime los datos por pantalla
            caminoMinimo(grafo, matriz_dist, matriz_int, v1, v2);
                    
        } else {
            cout << "No existe un vértice que tenga como nombre " << nombre2 << endl;
        }
    } else {
        cout << "No existe un vértice que tenga como nombre " << nombre1 << endl;
    }
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
}

} // Fin namespace ed
