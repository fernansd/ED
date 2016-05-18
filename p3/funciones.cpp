#include "funciones.hpp"


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
	m.leerMonticulo("lista-donantes.txt");
	LUGAR(10,10);
	printf("Lista leida del fichero: lista-donantes.txt");

}

/*! 
    \brief Vuelca los datos del monticulo pasado por referencia a un fichero
    		texto de nombre "backup_monticulo.txt". El formato de los datos es:
    		"apellidos,nombre,grupo_sanguineo,factorRH,numero_donaciones"
	\params m referencia a el montículo que se desea grabar
	\return Nada
*/
void grabarMonticulo(MonticuloDonantes& m) {
	m.grabarMonticulo("guardado-lista-donantes.txt");
	LUGAR(10,10);
	printf("Lista escrita en el fichero: guardado-lista-donantes.txt");
	
}

/*! 
    \brief Simula la realización de varias donaciones de sangre, modificando
    		correspodientemente el montículo pasado por referencia. La simulación
    		es controlada mediante la interacción con el usuario.
	\params m referencia al montículo sobre el que realizar la simulación
	\return Nada
*/
void simularDonaciones(MonticuloDonantes& m) {

    if (m.vacio()) {
        LUGAR(10,10);
        printf("El montículo está vacío");
        return;
    }

	int n_donaciones;
	LUGAR(10,10);
	printf("Introduce el número de donanciones a realizar: ");
	scanf("%d", &n_donaciones);
	LUGAR(10,11);
	printf("Realizando donanciones...");
	for (int i = 0; i < n_donaciones; i++) {
		m.realizarDonacion();
	}
	LUGAR(10,12);
	printf("¡Donanciones realizadas!");
	
	BORRAR;
	LUGAR(10,10);
	SUBRAYADO;
	printf("El donante en la cima es: ");
	APAGA;
	m.cima().escribirDonante();
	
	esperarUsuario();

}

