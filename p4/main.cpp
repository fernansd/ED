/*!
  \mainpage
  \brief    Programa de prueba de la clase Grafo y funciones complementarias
  \author   Fernando Sánchez Delgado
  \date     18 / 5 / 2016
  \version  1.0
*/
#include <iostream>

#include "macros.hpp"
#include "vertice.hpp"
#include "grafo.hpp"
#include "funciones.hpp"


using namespace ed;

int main() {

    Grafo grafo;

	int opcion;
    // Se ejecutará el programa hasta que se introduzca la opción de salida
    do {
        BORRAR;
        
        // Opciones del menu
        LUGAR(5,10);
        printf("1) Cargar grafo desde fichero");
        LUGAR(6,10);
        printf("2) Mostrar grafo por pantalla");
        LUGAR(7,10);
        printf("3) Aplicar algoritmo de Floyd");
        
        LUGAR(9,10);
        printf("0) Fin del programa");
        
        LUGAR(11,10);
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
                
                
            case 1: // Cargar grafo desde fichero
                    opcionCargarGrafoFichero(grafo);
                    break;
                    
            case 2: // Mostrar grafo por pantalla
                    opcionMostrarGrafo(grafo);
                    break;
                    
            case 3: // Aplicar algoritmo de Floyd
                    LUGAR(10,0);
                    opcionAplicarFloyd(grafo);
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
