#include <cstdio>

#include "../menu/macros.hpp"

#include "donante.hpp"

using namespace ed;

void opcionLeerDonante(Donante &d);

void opcionEscribirDonante(Donante &d);

void opcionModificarDonante(Donante &d);

void opcionCompararDonantes(Donante &d);

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
        printf("4) Compara lexicográficamente entre dos donantes");
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
                
            case 1: opcionLeerDonante(d1);
                    break;
                    
            case 2: opcionEscribirDonante();
                    break;
                    
            case 3: opcionModificarDonante();
                    break;
                    
            case 4: opcionCompararDonantes();
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

void opcionLeerDonante(Donante &d) {
    d.leerDonante();
}

void opcionEscribirDonante(Donante &d) {
    d.escribirDonante();
}

void opcionModificarDonante(Donante &d) {
    int opcion;
    // Se ejecutará el programa hasta que se introduzca la opción de salida
    do {
        BORRAR;
        
        // Opciones del menu
        LUGAR(5,10);
        printf("Elige el atributo a modificar:");
        LUGAR(7,10);
        printf("1) Escribir un donante por pantalla");
        LUGAR(8,10);
        printf("2) Modificar los datos de un donante");
        LUGAR(9,10);
        printf("3) Comparara lexicográficamente entre dos donantes");
        LUGAR(10,10);
        printf("0) Fin modificación");
        
        LUGAR(13,10);
        printf("Introduce la opcion -> ");
        scanf("%d", &opcion);
        getchar();
                
        BORRAR;
        
        switch (opcion) {
            case 0:
                LUGAR(10,10);
                INVERSO;
                printf("Fin modificación\n");
                APAGA;
                break;
                
            case 1: opcionLeerDonante(d1);
                    break;
                    
            case 2: opcionEscribirDonante(d1);
                    break;
                    
            case 3: opcionModificarDonante(d1);
                    break;
                    
            case 4: opcionCompararDonantes(d1);
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
}

void opcionCompararDonantes(Donante &d) {

}

