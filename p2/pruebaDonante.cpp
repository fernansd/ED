// Necesario incluirlo para el uso de las macros del menu
#include <cstdio>

// Cabecera que contiene las macros para dar formato a la salida de terminal
#include "../menu/macros.hpp"

#include "donante.hpp"

using namespace std;

using namespace ed;

/*
 * Prototipos para las funciones ejecutadas en las opciones del menú principal
 */
void opcionModificarDonante(Donante &d);

void opcionCompararDonantes(Donante &d1, Donante &d2);

int main () {

    Donante d1("Paco","Fernandez","0","negativo"), d2(d1), d3;
    
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
        
        // Evalúa la opción introducida por el usuario
        switch (opcion) {
            case 0: // Opción para acaba el programa
                LUGAR(10,10);
                INVERSO;
                printf("Fin del programa\n");
                APAGA;
                break;
                
            case 1: // Opción para leer los datos del donante d1 por pantalla
                    LUGAR(10,0);
                    d1.leerDonante();
                    break;
                    
            case 2: // Opción para escribir los datos del donante d1 por teclado
                    LUGAR(8,9);
                    d1.escribirDonante();
                    break;
                    
            case 3: // Opción para modificar los datos del donante d1
                    // de manera individual
                    opcionModificarDonante(d1);
                    break;
                    
            case 4: // Opción para comparar lexicográficamente los donante d1
                    // y d2. Si no se ha modificado d1 (es decir, no se han
                    // elegido otras opciones antes), deben de ser iguales.
                    opcionCompararDonantes(d1, d2);
                    break;
                    
            default: // Opción por defecto cuando se introduce un valor que no
                     // este presente entre las opciones del menú
                BORRAR;
                LUGAR(21,25);
                printf("Opción incorrecta");
        }
        
        // Tras acabar de ejecutar la opción elegida se presenta un pantalla de
        // transición hacia el menú principal que requiere que el usuario
        // presione la tecla ENTER para continuar
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
        
    } while(opcion != 0);

return 0;
}

/*! 
    \brief Invoca un menu que permite elegir un atributo de un donante
            y cambiar su valor
	\return Nada
	\pre El Donante debe existir
	\post Ninguna
	\sa opcionLeerDonante() opcionEscribirDonante() opcionCompararDonantes()
*/
void opcionModificarDonante(Donante &d) {
    int opcion;
    // Se ejecutará el bucle hasta que se introduzca la opción de salida
    do {
        BORRAR;
        
        // Opciones del menu
        LUGAR(5,10);
        printf("Elige que atributo del donante modificar: ");
        LUGAR(7,10);
        printf("1) Nombre");
        LUGAR(8,10);
        printf("2) Apellidos");
        LUGAR(9,10);
        printf("3) Grupo Sanguíneo");
        LUGAR(10,10);
        printf("4) Factor RH");
        
        LUGAR(12,10);
        printf("0) Fin modificación");
        
        LUGAR(15,10);
        printf("Introduce la opcion -> ");
        scanf("%d", &opcion);
        getchar();
                
        BORRAR;
        
        // Evalúa la opcion introducida y elige el comportamiento correspondiente
        switch (opcion) {
        
            case 0: // Acaba de modificar y vuelve al programa principal
                LUGAR(10,10);
                INVERSO;
                printf("Fin modificación\n");
                APAGA;
                break;
                
            case 1: {// Modifica el nombre
                string str;
                LUGAR(10,10);
                printf("Introduce el nombre: ");
                cin >> str;
                d.setNombre(str);
                break;
            }
            case 2: {// Modificar los apellidos
                string str;
                LUGAR(10,10);
                printf("Introduce los apellidos: ");
                cin >> str;
                d.setApellidos(str);
                break;
            }
            case 3: {// Modifica el grupo
                string str;
                LUGAR(10,10);
                printf("Introduce el nuevo grupo: ");
                cin >> str;
                d.setGrupo(str);
                break;
            }
            case 4: {// Modifica el factorRH
                string str;
                LUGAR(10,10);
                printf("Introduce el nuevo factorRH: ");
                cin >> str;
                d.setFactorRH(str);
                break;
            }      
            default: // Captura las opciones inválidas
                BORRAR;
                LUGAR(21,25);
                printf("Opción incorrecta");
        }
        
    } while(opcion != 0);
}


void opcionCompararDonantes(Donante &d1, Donante &d2) {

}

