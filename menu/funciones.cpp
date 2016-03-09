/*!
	\file  funciones.cpp
	\brief Código de las funciones utilizadas en el menú
*/

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include "macros.hpp"

void erastotenes()
{
 int *primos, n, i, j, linea;

 /* Peticion del valor de n */
do {
    BORRAR;
    LUGAR(5,10);
    printf("Cálculo de los número primos menores que un número dado");
    LUGAR(6,10);
    printf("Introduce un numero natural:  n --> ");
    scanf("%d",&n); 
    getchar();
  } while (n<1);

 /* Reserva de memoria */
 primos = (int *) malloc (n * sizeof(int));

 /* Inicializacion del vector */
 for (i=0; i<n; i++) *(primos+i) = i+1;

/**********************************************************************
 Criba de Erastotenes 
 Version optimizada: solo se criba con los numeros primos 
                     menores o iguales que la raiz cuadrada de n 
************************************************************************/

 for (i=1; *(primos+i)<=sqrt(n); i++)
   if (*(primos+i) != 0) 
        for (j= 2 * *(primos+i) - 1; j<n; j+= *(primos+i))
             *(primos+j) = 0;

/* Presentacion de los numeros primos menores que n */
 BORRAR;
 LUGAR(1,5);
 INTENSIDAD;
 printf("Numeros primos menores que %d",n);
 APAGA;

 for(i=0,linea=1;i<n;i++)
    { 
     if (*(primos+i)!=0) 
            {
             LUGAR(linea+2,10);
             printf("%d", *(primos+i)); 
             linea++; 
            }
     if (linea%20==0) 
           {
//	    LUGAR(linea+22,30);


            LUGAR(linea+1,25);
            printf("pulse ");
	    SUBRAYADO;
  	    printf("ENTER");
	    APAGA;
	    printf(" para ");
	    INVERSO;
	    printf(" continuar"); 
	    APAGA;

            getchar();
            BORRAR; 

            linea = 1;
            LUGAR(linea,10);
	    INTENSIDAD;
            printf("Numeros primos menores que %d (continuación)",n);
	    APAGA;
           }
    }
}


/*******************************************/
/*******************************************/
/*******************************************/

void factorial()
{
 int n;
 int resultado=1;
 int i;

 /* Peticion del valor de n */
 do {
    BORRAR;
    LUGAR(5,10);
    printf("Cálculo del factorial de un número");
    LUGAR(6,10);
    printf("Introduce un numero natural: n --> ");
    scanf("%d",&n); 
    getchar();
  } while (n<1);

 if ((n==0) || (n==1))
	resultado = 1;
 else {
	for(i=2;i<=n;i++)
	  resultado = resultado * i;
	}
}







