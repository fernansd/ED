#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <cstdio>

#include "macros.hpp"
#include "lista.hpp"
#include "donantes.hpp"

using namespace std;

namespace ed {

// Función para detener la ejecución hasta que el usuario presione ENTER
void esperarUsuario(int opc = 0);

// Opciones del menú
void cargarLista(Donantes& lista);                    
void grabarLista(Donantes& lista);
void insertarDonante(Donantes& lista);
void modificaDonante(Donantes& lista);
void eliminaDonante(Donantes& lista);

} // Fin namespace ed
#endif
