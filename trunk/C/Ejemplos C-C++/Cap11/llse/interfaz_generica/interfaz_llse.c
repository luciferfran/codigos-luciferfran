//////////////////////////////////////////////////////////////////
// Manipular una lista lineal simplemente enlazada (llse)
// interfaz_llse.c
//
#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"

// Interfaz para manipular una llse //////////////////////////////
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

int tamanyo(Elemento *lista)
{
  // Devuelve el n�mero de elementos de la lista
  Elemento *q = lista; // apunta al primer elemento
  int n = 0;           // n�mero de elementos
  while (q != NULL)
  {
    n++;
    q = q->siguiente;
  }
  return n;
}
  
int anyadir(int i, void *e, Elemento **lista)
{
  int n = 0;
  Elemento *q = NULL, *p = *lista; // lista es la cabecera
  Elemento *elemAnterior = p, *elemActual = p;

  // A�adir un elemento en la posici�n i
  int numeroDeElementos = tamanyo(p);
  if (i > numeroDeElementos || i < 0)
    return 0; // �ndice fuera de l�mites
  
  // Crear el elemento a a�adir
  q = nuevoElemento();
  q->dato = e; // asignar el puntero que referencia los datos
  q->siguiente = NULL;
  
  // Si la lista apuntada por p est� vac�a, a�adirlo sin m�s 
  if (numeroDeElementos == 0)
  {
    // A�adir el primer elemento
    *lista = q;
    return 1;
  }
  
  // Si la lista no est� vac�a, encontrar el punto de inserci�n.
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
  {
    elemAnterior = elemActual;
    elemActual = elemActual->siguiente;
  }
  // Dos casos:
  // 1) Insertar al principio de la lista
  // 2) Insertar despu�s del anterior (incluye insertar al final)
  if ( elemAnterior == elemActual ) // insertar al principio
  {
    q->siguiente = p;
    p = q; // cabecera
  }
  else // insertar despu�s del anterior
  {
    q->siguiente = elemActual;
    elemAnterior->siguiente = q;
  }

  *lista = p;

  return 1;
}

int anyadirAlPrincipio(void *e, Elemento **lista)
{
  // A�adir un elemento al principio
  return anyadir(0, e, lista);
}

int anyadirAlFinal(void *e, Elemento **lista)
{
  // A�adir un elemento al final
  return anyadir(tamanyo(*lista), e, lista);
}

void *borrar(int i, Elemento **lista)
{
  int n = 0;
  Elemento *p = *lista; // cabecera
  Elemento *elemAnterior = p, *elemActual = p;
  void *datos = NULL;

  // Borrar el elemento de la posici�n i
  int numeroDeElementos = tamanyo(p);
  if (i >= numeroDeElementos || i < 0)
    return NULL; // �ndice fuera de l�mites
  
  // Entrar en la lista y encontrar el �ndice del elemento.
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
  {
    elemAnterior = elemActual;
    elemActual = elemActual->siguiente;
  }
  // Dos casos:
  // 1) Borrar el primer elemento de la lista
  // 2) Borrar el siguiente a elemAnterior (elemActual)
  if ( elemActual == p ) // 1)
    p = p->siguiente; // cabecera
  else // 2)
    elemAnterior->siguiente = elemActual->siguiente;
  datos = elemActual->dato; // datos del elemento a borrar
  free(elemActual);

  *lista = p;

  // Devolver los datos del elemento borrado
  return datos;
}

void *borrarPrimero(Elemento **lista)
{
  // Borrar el primer elemento
  return borrar(0, lista);
}

void *borrarUltimo(Elemento **lista)
{
  // Borrar el �ltimo elemento
  return borrar(tamanyo(*lista) - 1, lista);
}

void *obtener(int i, Elemento *lista)
{
  int n = 0;
  Elemento *q = lista; // apunta al primer elemento
  // Obtener el elemento de la posici�n i
  int numeroDeElementos = tamanyo(lista);
  if (i >= numeroDeElementos || i < 0)
    return NULL; // �ndice fuera de l�mites
  
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
    q = q->siguiente;
  
  // Retornar los datos
  return q->dato;
}

void *obtenerPrimero(Elemento *lista)
{
  // Retornar el primer elemento
  return obtener(0, lista);
}

void *obtenerUltimo(Elemento *lista)
{
  // Retornar el �ltimo elemento
  return obtener(tamanyo(lista) - 1, lista);
}
//////////////////////////////////////////////////////////////////
