//////////////////////////////////////////////////////////////////
// Manipular una lista circular simplemente enlazada (lcse)
// interfaz_lcse.c
//
#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

// Interfaz para manipular una lcse //////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error()
{
  printf("Insuficiente memoria\n");
  exit(1);
}

// Crear un nuevo elemento
Elemento *nuevoElemento()
{
  Elemento *q = (Elemento *)malloc(sizeof(Elemento));
  if (!q) error();
  return q;
}

int tamanyo(Elemento *ultimo)
{
  // Devuelve el número de elementos de la lista
  Elemento *q = NULL;    // apunta al primer elemento
  int n = 1;             // número de elementos

  if (ultimo == NULL) return 0;
  q = ultimo->siguiente; // apunta al primer elemento
  while (q != ultimo)
  {
    n++;
    q = q->siguiente;
  }
  return n;
}
  
void anyadirAlPrincipio(void *e, Elemento **p)
{
  // Añade un elemento al principio de la lista.
  // Crear el nuevo elemento
  Elemento *ultimo = *p;

  Elemento *q = nuevoElemento();
  q->dato = e;
  q->siguiente = NULL;

  if( ultimo != NULL ) // existe una lista
  {         
    q->siguiente = ultimo->siguiente;
    ultimo->siguiente =  q;
  }    
  else  // inserción del primer elemento
  {
    ultimo = q;
    ultimo->siguiente = q;
  }

  *p = ultimo;
}

void anyadirAlFinal(void *e, Elemento **p)
{
  // Añade un elemento al final de la lista.
  // Por lo tanto, último referenciará este nuevo elemento. 
  // Crear el nuevo elemento.
  Elemento *ultimo = *p;

  Elemento *q = nuevoElemento();
  q->dato = e;
  q->siguiente = NULL;
    
  if( ultimo != NULL ) // existe una lista
  {       
    q->siguiente = ultimo->siguiente;
    ultimo = ultimo->siguiente =  q;
  }      
  else  // inserción del primer elemento
  {
    ultimo = q;
    ultimo->siguiente = q;
  }

  *p = ultimo;
}

void *borrar(Elemento **p)
{
  // Borra el primer elemento de la lista.
  // Devuelve NULL si la operación de borrar fracasa.
  Elemento *q = NULL, *ultimo = *p;
  void *datos = NULL;

  if( ultimo == NULL )
    return NULL; // lista vacía

  q = ultimo->siguiente;
  if( q == ultimo )
    *p = NULL;
  else
    ultimo->siguiente = q->siguiente;
  datos = q->dato;
  free(q);

  return datos;
}

void *obtener(int i, Elemento *ultimo)
{
  // Obtener el elemento de la posición i
  int n = 0;
  Elemento *q = NULL;

  int numeroDeElementos = tamanyo(ultimo);
  if (i >= numeroDeElementos || i < 0)
    return NULL; // índice fuera de límites

  q = ultimo->siguiente; // primer elemento
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
    q = q->siguiente;
  
  // Retornar los datos
  return q->dato;
}
//////////////////////////////////////////////////////////////////
