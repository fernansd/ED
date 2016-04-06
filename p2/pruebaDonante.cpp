#include <cstdio>

#include "../menu/macros.hpp"

#include "donante.hpp"

using namespace std;

using namespace ed;

// Prototipos
void opcionLeerDonante(Donante &d);

void opcionEscribirDonante(Donante &d);

void opcionModificarDonante(Donante &d);

void opcionCompararDonantes(Donante &d);

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
        
        switch (opcion) {
            case 0:
                LUGAR(10,10);
                INVERSO;
                printf("Fin del programa\n");
                APAGA;
                break;
                
            case 1: 
                    LUGAR(10,0);
                    d1.leerDonante();
                    break;
                    
            case 2: 
                    LUGAR(8,9);
                    d1.escribirDonante();
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

return 0;
}

/*! 
    \brief Permite introducir por teclado los datos de un donante
	\return Nada
	\pre El Donante debe existir
	\post Ninguna
	\sa opcionEscribirDonante() opcionModificarDonante() opcionCompararDonantes()
*/
void opcionLeerDonante(Donante &d) {
    
}

/*! 
    \brief Permite escribir por pantalla los datos de un donante
	\return Nada
	\pre El Donante debe existir
	\post Ninguna
	\sa opcionLeerDonante() opcionModificarDonante() opcionCompararDonantes()
*/
void opcionEscribirDonante(Donante &d) {
    
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


void opcionCompararDonantes(Donante &d) {

}

