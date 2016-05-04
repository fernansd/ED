#include "grafo.hpp"
namespace ed {

/// Observers
int adyacente();
bool cursorEnVertice();
Vertice<string> verticeCursor();
bool cursorEnLado();
int ladoCursor();

/// Mutators
void addVertice();
void addLado();
bool buscarVertice();
bool goTo();
bool buscarLado();
Vertice<string> verticeInicio();
Vertice<string> verticeSiguiente();
bool afterEndVertex();
int ladoInicio(Vertice<string> const& v);
int ladoSiguiente();
bool afterEndEdge();

}
