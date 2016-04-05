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
        printf("1) Leer un donante desde el teclado");
        LUGAR(6,10);
        printf("2) Escribir un donante por pantalla");
        LUGAR(7,10);
        printf("3) Modificar los datos de un donante");
        LUGAR(8,10);
        printf("4) Comparara lexicográficamente entre dos donantes");
        LUGAR(10,10);
        printf("0) Fin del programa");
        
        LUGAR(13,10);
        printf("Introduce la opcion -> ");
        scanf("%d", &opcion);
        getchar();
                
        BORRAR;
        
        switch (opcion) {
            case 0:
                LUGAR(10,10);
                INVERSO;
                printf("Fin del programa\n");
                APAGA;
                break;
            default:
                BORRAR;
                LUGAR(21,25);
                printf("Opción incorrecta");
        }
        
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
        
    } while(opcion != 0);

return 0;
}
