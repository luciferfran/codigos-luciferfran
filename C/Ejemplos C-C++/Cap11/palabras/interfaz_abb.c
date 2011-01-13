// interfaz_abb.c
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_abb.h" // estructura Nodo

/////////////////////////////////////////////////////////////////
// Interfaz abb: �rbol binario de b�squeda. Para utilizar las
// funciones proporcionadas por esta interfaz, tendremos que
// definir en la aplicaci�n que la utilice, las funciones:
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
  // La funci�n buscar permite acceder a un nodo determinado
  Nodo *actual = raiz;
  int nComp = 0;

  // Buscar un nodo que tenga asociados los datos especificados
  while ( actual != NULL )
  {
    if (( nComp = comparar( datos, actual->datos )) == 0)
      return( actual->datos ); // nodo encontrado
    else if ( nComp < 0 )      // buscar en el sub�rbol izquierdo
      actual = actual->izquierdo;
    else                       // buscar en el sub�rbol derecho
      actual = actual->derecho;
  }
  return NULL; // no existe
}

int insertar(void *datos, Nodo **raiz)
{
  // La funci�n insertar permite a�adir un nodo que a�n no est�
  // en el �rbol.
  Nodo *nuevo = NULL, *ultimo = NULL, *actual = *raiz;
  int nComp = 0;
  if ( datos == NULL ) return 1; // no datos

  // Comienza la b�squeda para verificar si existe un nodo con
  // estos datos en el �rbol
  while (actual != NULL)
  {
    if ((nComp = comparar( datos, actual->datos )) == 0)
      break; // se encontr� el nodo
    else
    {
      ultimo = actual;
      if ( nComp < 0 )  // buscar en el sub�rbol izquierdo
        actual = actual->izquierdo;
      else              // buscar en el sub�rbol derecho
        actual = actual->derecho;
    }
  }

  if ( actual == NULL ) // no se encontr� el nodo, a�adirlo
  {
    nuevo = nuevoNodo();
    nuevo->datos = datos;
    nuevo->izquierdo = nuevo->derecho = NULL;

    // El nodo a a�adir pasar� a ser la ra�z del �rbol total si
    // �ste est� vac�o, del sub�rbol izquierdo de "�ltimo" si la
    // comparaci�n fue menor, o del sub�rbol derecho de "�ltimo" si
    // la comparaci�n fue mayor.
    if ( ultimo == NULL ) // �rbol vac�o
      *raiz = nuevo;
    else if ( nComp < 0 )
      ultimo->izquierdo = nuevo;
    else
      ultimo->derecho = nuevo;
    return 0; // correcto
  } // fin del bloque if ( actual == NULL )
  else // el nodo ya existe en el �rbol
    return 2; // ya existe
}

void *borrar(void *datos, Nodo **raiz)
{
  // La funci�n borrar permite eliminar un nodo del �rbol.
  Nodo *ultimo = NULL, *actual = *raiz;
  Nodo *marcado = NULL, *sucesor = NULL;
  int nAnteriorComp = 0, nComp = 0;
  void *datosNodoBorrado = NULL;

  if (datos == NULL) return NULL; // no datos

  // Comienza la b�squeda para verificar si hay un nodo con
  // estos datos en el �rbol.
  while ( actual != NULL )
  {
    nAnteriorComp = nComp; // resultado de la comparaci�n anterior
    if (( nComp = comparar( datos, actual->datos )) == 0)
      break; // se encontr� el nodo
    else
    {
      ultimo = actual;
      if ( nComp < 0 )   // buscar en el sub�rbol izquierdo
        actual = actual->izquierdo;
      else               // buscar en el sub�rbol derecho
        actual = actual->derecho;
    }
  } // fin del bloque while ( actual != NULL )

  if ( actual != NULL ) // se encontr� el nodo
  {
    marcado = actual;
    if (( actual->izquierdo == NULL && actual->derecho == NULL ))
      // se trata de un nodo terminal (no tiene descendientes)
      sucesor = NULL;
    else if ( actual->izquierdo == NULL ) // nodo sin sub�rbol izq.
      sucesor = actual->derecho;
    else if ( actual->derecho == NULL ) // nodo sin sub�rbol dcho.
      sucesor = actual->izquierdo;
    else  // nodo con sub�rbol izquierdo y derecho
    {
      // Puntero al sub�rbol derecho del nodo a borrar
      sucesor = actual = actual->derecho;

      // Descender al nodo m�s a la izquierda en el sub�rbol
      // derecho de este nodo (el de valor m�s peque�o) y hacer
      // que el sub�rbol izquierdo del nodo a borrar sea ahora
      // el sub�rbol izquierdo de este nodo.
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
  else // el nodo buscado no est� en el �rbol
    return NULL; // no existe
}

void inorden(Nodo *raiz)
{
  // La funci�n recursiva inorden visita los nodos del �rbol
  // utilizando la forma inorden; esto es, primero visita
  // el sub�rbol izquierdo, despu�s visita la ra�z, y por
  // �ltimo, el sub�rbol derecho.
  Nodo *actual = raiz;

  if ( actual != NULL )
  {
    inorden( actual->izquierdo ); // visitar el sub�rbol izquierdo
    // Procesar los datos del nodo visitado
    procesar( actual->datos );
    inorden( actual->derecho );   // visitar el sub�rbol derecho
  }
}

void borrarArbol(Nodo **raiz)
{
  // La funci�n recursiva borrarArbol visita los nodos del �rbol
  // utilizando la forma postorden para liberar la memoria
  // asignada a cada uno de ellos.
  Nodo *actual = *raiz;

  if ( actual != NULL )
  {
    borrarArbol( &actual->izquierdo ); // sub�rbol izquierdo
    borrarArbol( &actual->derecho );   // sub�rbol derecho
    liberarmem( actual->datos );
    free( actual );
  }
  *raiz = NULL;
}
/////////////////////////////////////////////////////////////////
