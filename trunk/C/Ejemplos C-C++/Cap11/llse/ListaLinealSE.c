//////////////////////////////////////////////////////////////////
// Crear una lista lineal simplemente enlazada (llse)
// ListaLinealSE.c
//
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_llse.h"

main()
{
  int i = 0;

  // Definir una lista lineal vacía: llse
  Elemento *llse = NULL;
  
  // Leer los datos y añadirlos a la lista
  double *n = NULL, d = 0;

  printf("Introducir datos. Finalizar con eof.\n");
  printf("Valor double: ");
  while (scanf("%lf", &d) != EOF)
  {
    n = (double *)malloc(sizeof(double));
    if (!n) error();
    *n = d;
    anyadirAlPrincipio(n, &llse);
    printf("Valor double: ");
  }

  // Mostrar la lista de datos
  printf("\n");
  n = (double *)obtener(i, llse);
  i = 0;
  while (n != NULL)
  {
    printf("%g ", *n);
    i++;
    n = (double *)obtener(i, llse);
  }
  printf("\n");

  // Borrar las áreas de datos referenciadas por los elementos
  // de la lista.
  i = 0;
  n = (double *)obtener(i, llse);
  while (n != NULL)
  {
    free(n);
    i++;
    n = (double *)obtener(i, llse);
  }
  // Borrar la lista
  borrarTodos(&llse);
}
