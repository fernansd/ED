/*!
  \mainpage
  \brief    Programa del ejemplo del monticulo
  \author   Fernando Sánchez Delgado
  \date     18 / 5 / 2016
  \version  1.0
*/

// Necesario incluirlo para el uso de las macros del menu
#include <cstdio>

// Cabecera que contiene las macros para dar formato a la salida de terminal
#include "../menu/macros.hpp"
// Funciones usadas para el menu del programa y otras auxiliares
#include "funciones.hpp"

#include <iostream>

#include "donante.hpp"
#include "monticuloDonantes.hpp"

using namespace ed;

int main() {

	MonticuloDonantes monticulo;
	
	int opcion;
    // Se ejecutará el programa hasta que se introduzca la opción de salida
    do {
        BORRAR;
        
        // Opciones del menu
        LUGAR(5,10);
        printf("1) Comprobar si el montículo esta vacío");
        LUGAR(6,10);
        printf("2) Crear un montículo de donantes de sangre a partir de un "
        		"fichero");
        LUGAR(7,10);
        printf("3) Grabar un montículo de donantes de sangre en un fichero");
        LUGAR(8,10);
        printf("4) Mostrar el donante que se encuentra en la cima del montículo");
        LUGAR(9,10);
        printf("5) Simular realización de una o más donaciones");
        
        LUGAR(11,10);
        printf("0) Fin del programa");
        
        LUGAR(14,10);
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
                
            case 1: // Comprobar si el montículo esta vacío
                    LUGAR(10,10);
                    if ( monticulo.vacio() )
                    	printf("El montículo esta vacío");
                    else
                    	printf("El montículo no esta vacío");
                    break;
                    
            case 2: // Crear montículo a partir de un fichero
                    leerMonticuloFichero(monticulo);
                    break;
                    
            case 3: // Grabar un montículo en un fichero
                    grabarMonticulo(monticulo);
                    break;
                    
            case 4: {// Mostra el Donante de la cima del montículo
                    Donante d = monticulo.cima();
                    d.escribirDonante();
                    break;
            }
            case 5: {// Simula la realización de donaciones
            		simularDonaciones(monticulo);
            		break;
            }        
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
