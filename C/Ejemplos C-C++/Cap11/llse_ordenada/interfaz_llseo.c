//////////////////////////////////////////////////////////////////
// Manipular una lista lineal simplemente enlazada ordenada
// interfaz_llseo.c
//
#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "interfaz_llseo.h"

// Interfaz para manipular una llseo /////////////////////////////
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

// Iniciar una lista
void iniciarLista(tllseo *lista)
{
  lista->p = lista->elemActual = lista->elemAnterior = NULL;
}

// Indicar si la lista est� o no vac�a
int listaVacia(tllseo *lista)
{
  return lista->p == NULL;
}

int buscar(void *e, tllseo *lista)
{
  int r = 0;

  // Buscar el punto de inserci�n de un elemento en una lista
  // ordenada. La funci�n almacena en elemActual un puntero al
  // elemento buscado, si existe, o al siguiente, si no existe,
  // y en elemAnterior un puntero al elemento anterior.

  // Si la lista apuntada por p est� vac�a, retornar.
  if ( listaVacia(lista) ) return 0;
  // Si la lista no est� vac�a, encontrar el elemento.
  lista->elemAnterior = lista->p;
  lista->elemActual = lista->p;
  // Posicionarse en el elemento buscado.
  while (lista->elemActual != NULL &&
         (r = comparar(e, lista->elemActual->datos)) > 0)
  {
    lista->elemAnterior = lista->elemActual;
    lista->elemActual = lista->elemActual->siguiente;
  }

  return !r; // 1 = encontado, 0 = no encontrado
}

void anyadir(void *e, tllseo *lista)
{
  // A�adir un elemento en orden ascendente seg�n una clave
  // proporcionada por e.
  Elemento *q = nuevoElemento(); // crear el elemento
  q->datos = e;
  q->siguiente = NULL;
  
  // Si la lista apuntada por p est� vac�a, a�adirlo sin m�s 
  if ( listaVacia(lista) )
  {
    // A�adir el primer elemento
    lista->p = lista->elemAnterior = lista->elemActual = q;
    return;
  }
  
  // Si la lista no est� vac�a, encontrar el punto de inserci�n.
  // Buscar establece los valores de elemAnterior y elemActual.
  buscar(e, lista);

  // Dos casos:
  // 1) Insertar al principio de la lista
  // 2) Insertar despu�s del anterior (incluye insertar al final)
  if ( lista->elemAnterior == lista->elemActual )
  {
    // Insertar al principio
    q->siguiente = lista->p;
    lista->p = q; // cabecera
    // Actualizar punteros
    lista->elemAnterior = lista->elemActual = lista->p;
  }
  else // insertar despu�s del anterior
  {
    q->siguiente = lista->elemActual;
    lista->elemAnterior->siguiente = q;
    lista->elemActual = q; // actualizar puntero
  }
}

void *borrar(void *e, tllseo *lista)
{
  // Borrar un determinado elemento.
  void *datosElemBorrado = NULL;

  // Si la lista est� vac�a, retornar.
  if ( listaVacia(lista) ) return NULL;

  // Si la lista no est� vac�a, buscar el elemento y
  // establecer los valores de elemAnterior y elemActual.
  if (buscar(e, lista) == 0) return NULL; // no est�

  // Dos casos:
  // 1) Borrar el primer elemento de la lista
  // 2) Borrar el siguiente a elemAnterior (elemActual)
  if ( lista->elemActual == lista->p ) // 1)
    lista->elemAnterior = lista->p = lista->p->siguiente; // cabecera
  else // 2)
    lista->elemAnterior->siguiente = lista->elemActual->siguiente;
  // Borrar
  datosElemBorrado = lista->elemActual->datos;
  free(lista->elemActual);

  // Actualizar puntero
  if (lista->p == NULL) // hab�a un s�lo elemento
    iniciarLista(lista);
  else
    lista->elemActual = lista->elemAnterior->siguiente;

  // Retornar los datos del elemento borrado
  return datosElemBorrado;
}

void *borrarPrimero(tllseo *lista)
{
  void *datosElemBorrado = NULL;

  // Si la lista est� vac�a, retornar.
  if ( listaVacia(lista) ) return NULL;

  // Borrar el primer elemento de la lista
  lista->elemActual = lista->p;
  lista->p = lista->p->siguiente; // cabecera
  datosElemBorrado = lista->elemActual->datos;
  // Borrar
  free(lista->elemActual);
  // Actualizar punteros
  lista->elemAnterior = lista->elemActual = lista->p;
  // Retornar los datos del elemento borrado
  return datosElemBorrado;
}

void *obtenerPrimero(tllseo *lista)
{
  // Devolver un puntero a los datos del primer elemento
  // Si la lista est� vac�a, devolver NULL
  if ( listaVacia(lista) ) return NULL;
  lista->elemActual = lista->elemAnterior = lista->p;
  return lista->p->datos;
}

void *obtenerSiguiente(tllseo *lista)
{
  // Devolver un puntero a los datos del elemento siguiente
  // al actual y hacer que �ste sea el actual.
  // Si la lista est� vac�a o se intenta ir m�s all� del �ltimo,
  // devolver NULL.
  if ( listaVacia(lista) || lista->elemActual == NULL)
    return NULL;
  // Avanzar un elemento
  lista->elemAnterior = lista->elemActual;
  lista->elemActual = lista->elemActual->siguiente;
  if ( lista->elemActual != NULL )
    return lista->elemActual->datos;
  else
    return NULL;
}
//////////////////////////////////////////////////////////////////
