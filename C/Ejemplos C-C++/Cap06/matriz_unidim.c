/************* Creaci�n de una matriz unidimensional *************/
/* matriz_unidim.c
 */
#include <stdio.h>
#define N_ELEMENTOS 10 // n�mero de elementos de la matriz *

main()
{
  int m[N_ELEMENTOS]; // crear la matriz m
  int i = 0;          // sub�ndice

  printf("Introducir los valores de la matriz.\n");

  // Entrada de datos
  for (i = 0; i < N_ELEMENTOS; i++)
  {
    printf("m[%d] = ", i);
    scanf("%d", &m[i]);
  }

  // Salida de datos
  printf("\n\n");
  for (i = 0; i < N_ELEMENTOS; i++)
    printf("%d  ", m[i]);
  printf("\n\nFin del proceso.\n");
}
