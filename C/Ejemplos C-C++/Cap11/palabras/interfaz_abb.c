// interfaz_abb.c
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_abb.h" // estructura Nodo

/////////////////////////////////////////////////////////////////
// Interfaz abb: árbol binario de búsqueda. Para utilizar las
// funciones proporcionadas por esta interfaz, tendremos que
// definir en la aplicación que la utilice, las funciones:
// comparar, procesar y liberarmem.
//
// Mostrar un mensaje de error y abortar el programa
void error()
{
  printf("Insuficiente memoria\n");
  exit(1);
}

// Crear un nuevo elemento
Nodo *nuevoNodo()
{
  Nodo *q = (Nodo *)malloc(sizeof(Nodo));
  if (!q) error();
  return q;
}

void *buscar(void *datos, Nodo *raiz)
{
  // La función buscar permite acceder a un nodo determinado
  Nodo *actual = raiz;
  int nComp = 0;

  // Buscar un nodo que tenga asociados los datos especificados
  while ( actual != NULL )
  {
    if (( nComp = comparar( datos, actual->datos )) == 0)
      return( actual->datos ); // nodo encontrado
    else if ( nComp < 0 )      // buscar en el subárbol izquierdo
      actual = actual->izquierdo;
    else                       // buscar en el subárbol derecho
      actual = actual->derecho;
  }
  return NULL; // no existe
}

int insertar(void *datos, Nodo **raiz)
{
  // La función insertar permite añadir un nodo que aún no está
  // en el árbol.
  Nodo *nuevo = NULL, *ultimo = NULL, *actual = *raiz;
  int nComp = 0;
  if ( datos == NULL ) return 1; // no datos

  // Comienza la búsqueda para verificar si existe un nodo con
  // estos datos en el árbol
  while (actual != NULL)
  {
    if ((nComp = comparar( datos, actual->datos )) == 0)
      break; // se encontró el nodo
    else
    {
      ultimo = actual;
      if ( nComp < 0 )  // buscar en el subárbol izquierdo
        actual = actual->izquierdo;
      else              // buscar en el subárbol derecho
        actual = actual->derecho;
    }
  }

  if ( actual == NULL ) // no se encontró el nodo, añadirlo
  {
    nuevo = nuevoNodo();
    nuevo->datos = datos;
    nuevo->izquierdo = nuevo->derecho = NULL;

    // El nodo a añadir pasará a ser la raíz del árbol total si
    // éste está vacío, del subárbol izquierdo de "último" si la
    // comparación fue menor, o del subárbol derecho de "último" si
    // la comparación fue mayor.
    if ( ultimo == NULL ) // árbol vacío
      *raiz = nuevo;
    else if ( nComp < 0 )
      ultimo->izquierdo = nuevo;
    else
      ultimo->derecho = nuevo;
    return 0; // correcto
  } // fin del bloque if ( actual == NULL )
  else // el nodo ya existe en el árbol
    return 2; // ya existe
}

void *borrar(void *datos, Nodo **raiz)
{
  // La función borrar permite eliminar un nodo del árbol.
  Nodo *ultimo = NULL, *actual = *raiz;
  Nodo *marcado = NULL, *sucesor = NULL;
  int nAnteriorComp = 0, nComp = 0;
  void *datosNodoBorrado = NULL;

  if (datos == NULL) return NULL; // no datos

  // Comienza la búsqueda para verificar si hay un nodo con
  // estos datos en el árbol.
  while ( actual != NULL )
  {
    nAnteriorComp = nComp; // resultado de la comparación anterior
    if (( nComp = comparar( datos, actual->datos )) == 0)
      break; // se encontró el nodo
    else
    {
      ultimo = actual;
      if ( nComp < 0 )   // buscar en el subárbol izquierdo
        actual = actual->izquierdo;
      else               // buscar en el subárbol derecho
        actual = actual->derecho;
    }
  } // fin del bloque while ( actual != NULL )

  if ( actual != NULL ) // se encontró el nodo
  {
    marcado = actual;
    if (( actual->izquierdo == NULL && actual->derecho == NULL ))
      // se trata de un nodo terminal (no tiene descendientes)
      sucesor = NULL;
    else if ( actual->izquierdo == NULL ) // nodo sin subárbol izq.
      sucesor = actual->derecho;
    else if ( actual->derecho == NULL ) // nodo sin subárbol dcho.
      sucesor = actual->izquierdo;
    else  // nodo con subárbol izquierdo y derecho
    {
      // Puntero al subárbol derecho del nodo a borrar
      sucesor = actual = actual->derecho;

      // Descender al nodo más a la izquierda en el subárbol
      // derecho de este nodo (el de valor más pequeño) y hacer
      // que el subárbol izquierdo del nodo a borrar sea ahora
      // el subárbol izquierdo de este nodo.
      while ( actual->izquierdo != NULL )
        actual = actual->izquierdo;
      actual->izquierdo = marcado->izquierdo;
    }

    // Eliminar el nodo y rehacer los enlaces
    if ( ultimo != NULL )
    {
      if ( nAnteriorComp < 0 )
        ultimo->izquierdo = sucesor;
      else
        ultimo->derecho = sucesor;
    }
    else
      *raiz = sucesor;
    
    datosNodoBorrado = marcado->datos;
    free(marcado); // eliminar el nodo
    return datosNodoBorrado; // correcto
  }
  else // el nodo buscado no está en el árbol
    return NULL; // no existe
}

void inorden(Nodo *raiz)
{
  // La función recursiva inorden visita los nodos del árbol
  // utilizando la forma inorden; esto es, primero visita
  // el subárbol izquierdo, después visita la raíz, y por
  // último, el subárbol derecho.
  Nodo *actual = raiz;

  if ( actual != NULL )
  {
    inorden( actual->izquierdo ); // visitar el subárbol izquierdo
    // Procesar los datos del nodo visitado
    procesar( actual->datos );
    inorden( actual->derecho );   // visitar el subárbol derecho
  }
}

void borrarArbol(Nodo **raiz)
{
  // La función recursiva borrarArbol visita los nodos del árbol
  // utilizando la forma postorden para liberar la memoria
  // asignada a cada uno de ellos.
  Nodo *actual = *raiz;

  if ( actual != NULL )
  {
    borrarArbol( &actual->izquierdo ); // subárbol izquierdo
    borrarArbol( &actual->derecho );   // subárbol derecho
    liberarmem( actual->datos );
    free( actual );
  }
  *raiz = NULL;
}
/////////////////////////////////////////////////////////////////
