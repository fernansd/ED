/*!
  \mainpage
  \brief    Programa de prueba de las clases Donante, Lista y Donantes
  \author   Fernando Sánchez Delgado
  \date     1 / 6 / 2016
  \version  1.1
*/

// Necesario incluirlo para el uso de las macros del menu
#include <cstdio>
#include <iostream>
#include <limits>

#include "macros.hpp"
#include "funciones.hpp"
#include "donante.hpp"
#include "donantes.hpp"


using namespace std;
using namespace ed;

int main() {
    
    int opcion ;
    Donantes lista;
    
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
//        scanf("%d\n", &opcion);
        std::cin >> opcion;
        getchar();
        
        BORRAR;
        
        switch (opcion) {
            case 0: // Opción para acaba el programa
                LUGAR(10,10);
                INVERSO;
                printf("Fin del programa\n");
                APAGA;
                break;
                
            case 1: // Comprueba si hay donantes en lista
                    LUGAR(10,10);
                    if (lista.estaVacia()) {
                        printf("La lista está vacía");
                    } else {
                        printf("Hay donantes en la lista");
                    }
                    break;
                    
            case 2: // Carga lista desde un fichero
                    cargarLista(lista);                    
                    break;
                    
            case 3: // Graba la lista a un fichero
                    grabarLista(lista);
                    break;
                    
            case 4: // Pide un donante por teclado y lo inserta en la lista
                    insertarDonante(lista);
                    break;
            
            case 5: // Modifica la información de un donante
                    modificaDonante(lista);
                    break;
                    
            case 6: // Elimina un donante de la lista
                    eliminaDonante(lista);
                    break;
                    
            case 7: // Muestra por pantalla la lista de donantes
                    if (lista.estaVacia()) {
                        LUGAR(10,10);
                        printf("La lista está vacía");
                    } else {
                        LUGAR(10,10);
                        lista.escribirDonantes();
                    }
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
    
    // Limpia la pantalla y posiciona el cursor en la esquina superior izquierda
    BORRAR;
    LUGAR(0,0);

return 0;
}

