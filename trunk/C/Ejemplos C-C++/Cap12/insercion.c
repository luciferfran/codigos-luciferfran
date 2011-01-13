/* insercion.c
 */
#include <stdio.h>
#include <stdlib.h>

// Ordenación por inserción
void insercion(double m[], int n_elementos)
{
  int i, k;
  double x;
  // Desde el segundo elemento
  for (i = 1; i < n_elementos; i++)
  {
    x = m[i];
    k = i-1;
    // Para k=-1, se ha alcanzado el extremo izquierdo.
    while (k >=0 && x < m[k])
    {
      m[k+1] = m[k]; // hacer hueco para insertar
      k--;
    }
    m[k+1] = x; // insertar x en su lugar
  }
}

main()
{
  double lista[] = { 46, 54, 12, 30, 84, 18, 10, 77 };
  int n_elementos = sizeof(lista)/sizeof(double);
  int i;

  insercion(lista, n_elementos);
  
  printf("Lista ordenada:\n");
  for (i = 0; i < n_elementos; i++)
    printf("%g ", lista[i]);
  printf("\n");
}
