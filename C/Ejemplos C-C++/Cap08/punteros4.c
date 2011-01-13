// punteros4.c
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

void AsignarMem2D(tmatriz2D *);
void LiberarMem2D(tmatriz2D);
void Visualizar(tmatriz2D);
void AsignarDatos(tmatriz2D);

main()
{
  tmatriz2D m = {NULL, 2, 3}; // estructura m

  // Crear una matriz bidimensional dinámicamente
  AsignarMem2D(&m);
  if (m.p == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }

  // Asignar datos desde el teclado a la matriz
  AsignarDatos(m);

  // Visualizar la matriz
  Visualizar(m);

  // Liberar la memoria asignada a la matriz
  LiberarMem2D(m);
  return 0;
}

void AsignarMem2D(tmatriz2D *x)
{
  double **p = NULL; // dirección del bloque de memoria a reservar
  int f = 0, filas = x->filas, cols = x->cols;

  // Crear una matriz bidimensional dinámicamente
  // Matriz de punteros a cada una de las filas
  p = (double **)malloc(filas * sizeof(double *));
  if ( p == NULL ) return;
  // Iniciar la matriz de punteros con ceros
  memset(p, 0, filas * sizeof(double *));
  x->p = p; // guardar la dirección de la matriz en el parámetro
            // pasado por referencia a esta función.
            // El tipo de *x es double **, igual que el de p.
  // Asignar memoria a cada fila
  for (f = 0; f < filas; f++)
  {
    p[f] = (double *)malloc(cols * sizeof(double));
    if ( p[f] == NULL )
    {
      LiberarMem2D(*x);
      x->p = NULL;
      return;
    }
    // Iniciar la fila con ceros
    memset(p[f], 0, cols * sizeof(double));
  }
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

void AsignarDatos(tmatriz2D x)
{
  int f = 0, c = 0;
  for (f = 0; f < x.filas; f++)
  {
    for (c = 0; c < x.cols; c++)
    {
      printf("elemento[%d][%d] = ", f, c);
      scanf("%lf", &x.p[f][c]);
    }
    printf("\n");
  }
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
