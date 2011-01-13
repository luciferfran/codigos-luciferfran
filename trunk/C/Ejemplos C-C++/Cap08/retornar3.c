// retornar3.c
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct
{
  double **p; // dirección de comienzo de la matriz
  int filas;  // número de filas
  int cols;   // número de columnas
} tmatriz2D;  // tipo

tmatriz2D *AsignarMem2D(int, int);
void LiberarMem2D(tmatriz2D);
void Visualizar(tmatriz2D);

main()
{
  int filas = 2, cols = 3;
  tmatriz2D *m = NULL; // puntero a una estructura tmatriz2D

  // Crear una matriz bidimensional dinámicamente
  m = AsignarMem2D(filas, cols);
  if (m == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }

  // Operaciones con la matriz
  // ...

  // Visualizar la matriz
  Visualizar(*m);

  // Liberar la memoria asignada a la matriz
  LiberarMem2D(*m);

  return 0;
}

tmatriz2D *AsignarMem2D(int filas, int cols)
{
  static tmatriz2D x;
  int f = 0;
  x.p = NULL; x.filas = filas; x.cols = cols;

  // Crear una matriz bidimensional dinámicamente
  // Matriz de punteros a cada una de las filas
  x.p = (double **)malloc(filas * sizeof(double *));
  if ( x.p == NULL ) return NULL;
  // Iniciar la matriz de punteros con ceros
  memset(x.p, 0, filas * sizeof(double *));
  // Asignar memoria a cada fila
  for (f = 0; f < x.filas; f++)
  {
    x.p[f] = (double *)malloc(cols * sizeof(double));
    if ( x.p[f] == NULL )
    {
      LiberarMem2D(x);
      x.p = NULL;
      return NULL;
    }
    // Iniciar la fila con ceros
    memset(x.p[f], 0, cols * sizeof(double));
  }
  return &x;
}

void LiberarMem2D(tmatriz2D x)
{
  int f = 0;
  // Liberar la memoria asignada a la matriz
  for (f = 0; f < x.filas; f++)
  {
    free(x.p[f]);
  }
  free(x.p);
}

void Visualizar(tmatriz2D x)
{
  int f = 0, c = 0;
  for (f = 0; f < x.filas; f++)
  {
    for (c = 0; c < x.cols; c++)
      printf("%5g", x.p[f][c]);
    printf("\n");
  }
}
