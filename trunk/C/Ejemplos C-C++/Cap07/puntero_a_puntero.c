/* Puntero a puntero.
 * puntero_a_puntero.c
 */
#include <stdio.h>
 
main() 
{
  int i, j;
  int a[5][5]; // matriz de dos dimensiones
  int *p[5];   // matriz de punteros
  int **q;     // puntero a puntero a un entero

  for (i = 0; i < 5; i++)
    p[i] = a[i]; // asignar a p las filas de a

  q = p;

  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++)
      scanf("%d", *(q+i)+j);

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 5; j++)
      printf("%7d", *(*(q+i)+j));
    printf("\n");
  }
}
