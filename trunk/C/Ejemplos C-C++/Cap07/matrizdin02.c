/************** Matriz dinámica de dos dimensiones **************/
/* matrizdin02.c
 */
#include <stdio.h>
#include <stdlib.h>
// #include <memory.h> // necesaria para memset

main() 
{
  int **m = NULL;
  int nFilas = 0, nCols = 0;
  int correcto = 0, f = 0, c = 0;

  do
  {
    printf("Número de filas de la matriz:    ");
    correcto = scanf("%d", &nFilas);
    fflush(stdin);
  }
  while ( !correcto || nFilas < 1 );

  do
  {
    printf("Número de columnas de la matriz: ");
    correcto = scanf("%d", &nCols);
    fflush(stdin);
  }
  while ( !correcto || nCols < 1 );

  // Asignar memoria para la matriz de punteros
  if ((m = (int **)malloc(nFilas * sizeof(int *))) == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }

  // Asignar memoria para cada una de las filas
  for (f = 0; f < nFilas; f++)
  {
    if ((m[f] = (int *)malloc(nCols * sizeof(int))) == NULL)
    {
      printf("Insuficiente espacio de memoria\n");
      return -1;
    }
  }

  // Iniciar la matriz a cero
  for ( f = 0; f < nFilas; f++ )
    for ( c = 0; c < nCols; c++ )
      m[f][c] = 0;

  // Los elementos de la matriz 2D pueden también ser puestos
  // a cero así:
  // for ( f = 0; f < nFilas; f++ )
  //   memset(m[f], 0, nCols * sizeof(int));

  // Operaciones
  // ...
  // Visualizar la matriz 2D
  for ( f = 0; f < nFilas; f++ )
  {
    for ( c = 0; c < nCols; c++ )
      printf("%d  ", m[f][c]);
    printf("\n");
  }
  
  // Liberar la memoria asignada a cada una de las filas
  for ( f = 0; f < nFilas; f++ )
    free(m[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(m);

  return 0;
}
