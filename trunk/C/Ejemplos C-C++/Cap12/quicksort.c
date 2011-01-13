/* quicksort.c
 */
#include <stdio.h>
#include <stdlib.h>

// Funci�n recursiva basada en el algoritmo quicksort
// que permite ordenar una lista de n�meros.
void qs(int lista[], int inf, int sup)
{
  int izq = 0, der = 0;
  int mitad = 0, x = 0;

  izq = inf; der = sup;
  mitad = lista[(izq+der)/2];
  do
  {
    while (lista[izq] < mitad && izq < sup) izq++;
    while (mitad < lista[der] && der > inf) der--;
    if (izq <= der)
    {
      x = lista[izq], lista[izq] = lista[der], lista[der] = x;
      izq++; der--;
    }
  }
  while (izq <= der);
  if (inf < der) qs(lista, inf, der);
  if (izq < sup) qs(lista, izq, sup);
}

// Funci�n quicksort
void quicksort(int lista[], int n_elementos)
{
  qs(lista, 0, n_elementos - 1);
}

main()
{
  static int lista[] = { 10, 3, 7, 5, 12, 1, 27, 3, 8, 13 };
  int n_elementos = sizeof(lista)/sizeof(int);

  register i;

  quicksort(lista, n_elementos);
  
  printf("Lista ordenada:\n");
  for (i = 0; i < n_elementos; i++)
    printf("%6d", lista[i]);
  printf("\n");
}

