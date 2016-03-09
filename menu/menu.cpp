/*!
	\file  menu.cpp
	\brief Programa que muestra el uso de macros de pantalla para mejorar el diseño de menús
*/

#include <stdio.h>
#include "macros.hpp"
#include "funciones.hpp"


/*!
	\fn     void main();
	\brief  Programa que muestra el uso de menús con macros de pantalla
*/
int main()
{

 int opcion;

 do{
	// Se muestran las opciones del menú
	BORRAR;
	LUGAR(5,10);
	printf("Opciones del menú");
	LUGAR(6,10);
	printf("1.- Erastótenes");
	LUGAR(7,10);
	printf("2.- Factorial");
	LUGAR(9,10);
	printf("0.- Salir");

	LUGAR(12,10);
	printf("Opción --> ");
	scanf("%d",&opcion);
	getchar();

	BORRAR;

	// Se ejecuta la opción del menú elegida
	switch(opcion)
	{
		case 0: LUGAR(10,10);
			INVERSO;
			printf("Fin del programa.\n");
			APAGA;
			break;

		case 1: 
			erastotenes();
			break;

		case 2: factorial();
			break;

		default: BORRAR;
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
  }while(opcion!=0);

  // Fin del programa
  return 0;
}

