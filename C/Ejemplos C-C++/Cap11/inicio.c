// Inciación a las listas dinámicas.
// inicio.c
//
#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
  // Miembros:
  // Defina aquí los datos o un puntero a los datos
  // ...
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
  ElementoLse *p = NULL, *q = NULL; // punteros a un elemento de la lista
  // Asignar memoria para un elemento
  p = nuevoElemento();
  // Este elemento no tiene un sucesor
  p->siguiente = NULL;
  // Operaciones cualesquiera
  q = nuevoElemento();        // crear un nuevo elemento
  q->siguiente = p; // localización del elemento siguiente
  p = q; // p hace referencia al principio de la lista
  // Liberar la memoria ocupada por la lista
  while (p != NULL)
  {
    q = p;
    p = p->siguiente;
    free(q);
  }
} 

