// punteros2.c
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void Visualizar(double **, int, int);

main()
{
  int filas = 2, cols = 3; // número filas y columnas de la matriz
  int f = 0;
  // Crear una matriz bidimensional dinámicamente
  // Matriz de punteros a cada una de las filas
  double **m = (double **)malloc(filas * sizeof(double *));
  if ( m == NULL )
  {
    printf("Insuficiente memoria\n");
    return -1;
  }
  // Iniciar la matriz de punteros con ceros
  memset(m, 0, filas * sizeof(double *));
  // Asignar memoria a cada fila
  for (f = 0; f < filas; f++)
  {
    m[f] = (double *)malloc(cols * sizeof(double));
    if ( m[f] == NULL )
    {
      printf("Insuficiente memoria\n");
      return -1;
    }
    // Iniciar la fila con ceros
    memset(m[f], 0, cols * sizeof(double));
  }

  // ...

  // Visualizar la matriz
  Visualizar(m, filas, cols);
  // Liberar la memoria asignada a la matriz
  for (f = 0; f < filas; f++)
  {
    free(m[f]);
  }
  free(m);
  return 0;
}

void Visualizar(double **x, int filas, int cols)
{
  int f = 0, c = 0;
  for (f = 0; f < filas; f++)
  {
    for (c = 0; c < cols; c++)
      printf("%5g", x[f][c]);
    printf("\n");
  }
}

