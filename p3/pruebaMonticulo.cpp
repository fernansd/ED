// Necesario incluirlo para el uso de las macros del menu
#include <cstdio>

// Cabecera que contiene las macros para dar formato a la salida de terminal
#include "../menu/macros.hpp"

#include <iostream>

#include "donante.hpp"
#include "monticuloDonantes.hpp"

using namespace ed;

// Función para detener la ejecución hasta que el usuario presione ENTER
void esperarUsuario(int opc = 0);

void leerMonticuloFichero(MonticuloDonantes& m);

void grabarMonticulo(MonticuloDonantes& m);

void simularDonaciones(MonticuloDonantes& m);

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
    
    BORRAR;
    LUGAR(0,0);

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

/*! 
    \brief Crea un monticulo a partir de un fichero que pide al usuario
    		y lo almacena en la referencia pasada.
    		El formato de los datos que se espera encontrar es:
    		"apellidos,nombre,grupo_sanguineo,factorRH,numero_donaciones"
	\params m referencia al monticulo donde se desea cargar el fichero
	\return Nada
*/
void leerMonticuloFichero(MonticuloDonantes& m) {
	return; // Falta por implementar
}

/*! 
    \brief Vuelca los datos del monticulo pasado por referencia a un fichero
    		texto de nombre "backup_monticulo.txt". El formato de los datos es:
    		"apellidos,nombre,grupo_sanguineo,factorRH,numero_donaciones"
	\params m referencia a el montículo que se desea grabar
	\return Nada
*/
void grabarMonticulo(MonticuloDonantes& m) {
	return; // Falta por implementar
}

/*! 
    \brief Simula la realización de varias donaciones de sangre, modificando
    		correspodientemente el montículo pasado por referencia. La simulación
    		es controlada mediante la interacción con el usuario.
	\params m referencia al montículo sobre el que realizar la simulación
	\return Nada
*/
void simularDonaciones(MonticuloDonantes& m) {
	return; // Falta por implementar
}

