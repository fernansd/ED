#include <cstdio>

#include "../menu/macros.hpp"

#include "donante.hpp"

using namespace ed;

int main () {

    Donante d1("Paco","Fernandez"), d2(d1), d3;
    
    int opcion;
    // Se ejecutará el programa hasta que se introduzca la opción de salida
    do {
        BORRAR;
        
        // Opciones del menu
        LUGAR(5,10);
        printf("Leer un donante desde el teclado");
        LUGAR(6,10);
        printf("Escribir un donante por pantalla");
        LUGAR(7,10);
        printf("Modificar los datos de un donante");
        LUGAR(8,10);
        printf("Comparara lexicográficamente entre dos donantes");
        LUGAR(10,10);
        printf("Fin del programa");
        
        LUGAR(13,10);
        printf("Introduce la opcion");
        cin >> opcion;
        
        BORRAR;
        
        switch (opcion) {
        
            default:
                LUGAR(8,10);
                printf("Fin del programa")
        }
        
    } while(opcion != 0);

return 0;
}
