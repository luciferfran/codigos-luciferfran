// punteros3.c
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void AsignarMem2D(double ***, int, int);
void LiberarMem2D(double **, int);
void Visualizar(double **, int, int);

main()
{
  int filas = 2, cols = 3; // número filas y columnas de la matriz
  double **m = NULL;

  // Crear una matriz bidimensional dinámicamente
  AsignarMem2D(&m, filas, cols);
  if (m == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }

  // Operaciones con la matriz
  // ...

  // Visualizar la matriz
  Visualizar(m, filas, cols);

  // Liberar la memoria asignada a la matriz
  LiberarMem2D(m, filas);
  return 0;
}

void AsignarMem2D(double ***x, int filas, int cols)
{
  double **p = NULL; // dirección del bloque de memoria a reservar
  int f = 0;

  // Crear una matriz bidimensional dinámicamente
  // Matriz de punteros a cada una de las filas
  p = (double **)malloc(filas * sizeof(double *));
  if ( p == NULL ) return;
  // Iniciar la matriz de punteros con ceros
  memset(p, 0, filas * sizeof(double *));
  // Asignar memoria a cada fila
  for (f = 0; f < filas; f++)
  {
    p[f] = (double *)malloc(cols * sizeof(double));
    if ( p[f] == NULL )
    {
      LiberarMem2D(p, filas);
      *x = NULL;
      return;
    }
    // Iniciar la fila con ceros
    memset(p[f], 0, cols * sizeof(double));
  }
  *x = p; // guardar la dirección de la matriz en el parámetro
          // pasado por referencia a esta función.
          // El tipo de *x es double **, igual que el de p.
}

void LiberarMem2D(double **x, int filas)
{
  int f = 0;
  // Liberar la memoria asignada a la matriz
  for (f = 0; f < filas; f++)
  {
    free(x[f]);
  }
  free(x);
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

