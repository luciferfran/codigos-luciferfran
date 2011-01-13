// Operaciones básicas con listas lineales.
// op_basicas.c
//
#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
  int dato;            // área de datos
  struct s *siguiente; // puntero al siguiente elemento
} ElementoLse;

void error()
{
  printf("Insuficiente memoria\n");
  exit(1);
}

ElementoLse *nuevoElemento()
{
  ElementoLse *q = (ElementoLse *)malloc(sizeof(ElementoLse));
  if (!q) error();
  return q;
}

main() 
{
  ElementoLse *p = NULL, *q = NULL, *r = NULL;
  int n = 0, x = 0;

  // Crear una lista de enteros
  printf("Introducir datos. Finalizar con eof.\n");

  printf("dato: ");
  while (scanf("%d", &n) != EOF)
  {
    q = nuevoElemento();
    q->dato = n;
    q->siguiente = p;
    p = q;
    printf("dato: ");
  }
  // Operaciones con la lista
  // ...
  q = p;              // q apunta el primer elemento de la lista
  printf("dato a buscar: "); scanf("%d", &x);
  while (q != NULL && q->dato != x)
    q = q->siguiente; // q apunta al siguiente elemento
  if (q) printf("%d\n", q->dato);

  // Liberar la memoria ocupada por la lista
  while (p != NULL)
  {
    q = p;            // q hace apunta al mismo elemento que p
    p = p->siguiente; // p apunta al siguiente elemento
    free(q);          // objeto apuntado por q a la basura
  }
} 

