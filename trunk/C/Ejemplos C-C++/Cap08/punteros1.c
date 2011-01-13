// punteros1.c
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void Visualizar(double *, int);

main()
{
  int elems = 6; // número de elementos de la matriz
  // Crear una matriz unidimensional dinámicamente
  double *m = (double *)malloc(elems * sizeof(double));
  if ( m == NULL )
  {
    printf("Insuficiente memoria\n");
    return -1;
  }
  // Iniciar la matriz con ceros
  memset(m, 0, elems * sizeof(double));

  // ...

  // Visualizar la matriz
  Visualizar(m, elems);

  free(m);
  return 0;
}

void Visualizar(double *x, int elems)
{
  int i = 0;
  for (i = 0; i < elems; i++)
    printf("%5g", x[i]);
  printf("\n");
}

