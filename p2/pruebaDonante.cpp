// Necesario incluirlo para el uso de las macros del menu
#include <cstdio>

// Cabecera que contiene las macros para dar formato a la salida de terminal
#include "macros.hpp"

#include "donante.hpp"

using namespace std;

using namespace ed;


// Función para detener la ejecución hasta que el usuario presione ENTER
void esperarUsuario(int opc = 0);

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
                    esperarUsuario();
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
        esperarUsuario();
        
    } while(opcion != 0);

return 0;
} // Fin del Main

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
    BORRAR;
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
                getline(cin, str);
                cin.ignore(256,'\n');
                d.setNombre(str);
                break;
            }
            case 2: {// Modificar los apellidos
                string str;
                LUGAR(10,10);
                printf("Introduce los apellidos: ");
                getline(cin, str);
                cin.ignore(256,'\n');
                d.setApellidos(str);
                break;
            }
            case 3: {// Modifica el grupo
                string str;
                LUGAR(10,10);
                printf("Introduce el nuevo grupo: ");
                getline(cin, str);
                d.setGrupo(str);
                break;
            }
            case 4: {// Modifica el factorRH
                string str;
                LUGAR(10,10);
                printf("Introduce el nuevo factorRH: ");
                getline(cin, str);
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

/*! 
    \brief Invoca un menu que permite elegir un atributo de un donante
            y cambiar su valor
	\return Nada
	\pre El Donante debe existir
	\post Ninguna
	\sa opcionLeerDonante() opcionEscribirDonante() opcionCompararDonantes()
*/
void opcionCompararDonantes(Donante &d1, Donante &d2) {
    LUGAR(8,10);
    printf("Los datos de los donantes a comparar son:");
    
    LUGAR(10,10);
    SUBRAYADO;
    printf("Donante 1: ");
    APAGA;
    LUGAR(12,10);
    d1.escribirDonante();
    esperarUsuario();
    
    LUGAR(10,10);
    SUBRAYADO;
    printf("Donante 2: ");
    APAGA;
    LUGAR(12,10);
    d2.escribirDonante();
    esperarUsuario();
    
    LUGAR(10,10);
    if ( d1 == d2 ) {
        printf("Los dos donantes son iguales.");
    } else if ( d1 <= d2 ) {
        printf("El primer donante es menor que el segundo.");
    } else {
        printf("El primer donante es mayor que el segundo.");
    }
}





