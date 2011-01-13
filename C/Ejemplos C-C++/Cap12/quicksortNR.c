/* quicksortNR.c
 */
#include <stdio.h>
#include <stdlib.h>

#define NE 100
typedef struct
{
  int inf, sup;
} elemento_pila;

// Función no recursiva qs
void qs(int lista[], int inf, int sup)
{
  elemento_pila pila[NE];
  int izq, der;
  int mitad, x, p;
  
  // Inicializar la pila con los valores: inf, sup
  p = 1, pila[p].inf = inf, pila[p].sup = sup;
  do
  {
    // tomar los datos inf, sup de la parte superior de la pila
    inf = pila[p].inf, sup = pila[p].sup, p--;
    do
    {
      // División de la matriz en dos partes
      izq = inf; der = sup;
      mitad = lista[(izq+der)/2];
      do
      {
        while (lista[izq] < mitad && izq < sup) izq++;
        while (mitad < lista[der] && der > inf) der--;
        if (izq <= der)
        {
          x=lista[izq], lista[izq]=lista[der], lista[der]=x;
          izq++; der--;
        }
      }
      while (izq <= der);

      if (izq < sup)
      {
        // meter en la pila los valores: izq, sup
        p++, pila[p].inf = izq, pila[p].sup = sup;
      }
      /* inf = inf; */  sup = der;
    }
    while (inf < der);
  }
  while (p);
}

// Función quicksort
void quicksort(int lista[], int n_elementos)
{
  qs(lista, 0, n_elementos - 1);
}

void main()
{
  int lista[] = { 10, 3, 7, 5, 12, 1, 27, 3, 8, 13 };
  int n_elementos = sizeof(lista)/sizeof(int);

  int i;

  quicksort(lista, n_elementos);
  
  printf("Lista ordenada:\n");
  for (i = 0; i < n_elementos; i++)
    printf("%6d", lista[i]);
  printf("\n");
}
