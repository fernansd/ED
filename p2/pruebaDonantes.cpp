// Necesario incluirlo para el uso de las macros del menu
#include <cstdio>

// Cabecera que contiene las macros para dar formato a la salida de terminal
#include "../menu/macros.hpp"

#include "donante.hpp"
#include "donantes.hpp"

using namespace std;
using namespace ed;

// Función para detener la ejecución hasta que el usuario presione ENTER
void esperarUsuario(int opc = 0);

int main() {
    
    int opcion;
    Donantes l;
    
    do {
        BORRAR;
        
        // Opciones del menu
        LUGAR(5,10);
        printf("1) Comprobar si hay donantes");
        LUGAR(6,10);
        printf("2) Cargar lista de donantes desde un fichero");
        LUGAR(7,10);
        printf("3) Grabar una lista de donantes a un fichero");
        LUGAR(8,10);
        printf("4) Insertar un nuevo donante");
        LUGAR(9,10);
        printf("5) Modificar información de un donante");
        LUGAR(10,10);
        printf("6) Borrar un donante de la lista");
        LUGAR(11,10);
        printf("7) Mostrar por pantalla los donantes de sangre");
        
        LUGAR(13,10);
        printf("0) Fin del programa");
        
        LUGAR(15,10);
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
                
            case 1: // Comprueba si hay donantes en lista
                    LUGAR(10,0);
                    
                    break;
                    
            case 2: // Opción para escribir los datos del donante d1 por teclado
                    LUGAR(8,9);
                    
                    
                    break;
                    
            case 3: // Opción para modificar los datos del donante d1
                    // de manera individual
                    break;
                    
            case 4: // Opción para comparar lexicográficamente los donante d1
                    // y d2. Si no se ha modificado d1 (es decir, no se han
                    // elegido otras opciones antes), deben de ser iguales.
                    
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
    BORRAR;
}
