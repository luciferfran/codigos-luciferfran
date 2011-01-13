//////////////////////////////////////////////////////////////////
// Manipular una lista circular doblemente enlazada (lcde)
// interfaz_lcde.c
//
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_lcde.h"

// Interfaz para manipular una lcde //////////////////////////////
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

void iniciarLcde(tlcde *lcde)
{
  lcde->ultimo = lcde->actual = NULL;
  lcde->numeroDeElementos = 0;
  lcde->posicion = -1;
}

void insertar(void *e, tlcde *lcde)
{
  // Obtener los par�metros de la lcde
  Elemento *ultimo = lcde->ultimo;
  Elemento *actual = lcde->actual;
  int numeroDeElementos = lcde->numeroDeElementos;
  int posicion = lcde->posicion;

  // A�adir un nuevo elemento a la lista a continuaci�n
  // del elemento actual; el nuevo elemento pasa a ser el
  // actual
  Elemento *q = NULL;
               
  if (ultimo == NULL) // lista vac�a
  {
    ultimo = nuevoElemento();
    // Las dos l�neas siguientes inician una lista circular
    ultimo->anterior = ultimo;
    ultimo->siguiente = ultimo;
    ultimo->dato = e;      // asignar datos
    actual = ultimo;
    posicion = 0;          // ya hay un elemento en la lista
  }
  else // existe una lista
  {
    q = nuevoElemento();

    // Insertar el nuevo elemento despu�s del actual
    actual->siguiente->anterior = q;
    q->siguiente = actual->siguiente;
    actual->siguiente = q;
    q->anterior = actual;
    q->dato = e;

    // Actualizar par�metros.
    posicion++;
    
    // Si el elemento actual es el �ltimo, el nuevo elemento
    // pasa a ser el actual y el �ltimo.
    if( actual == ultimo )
      ultimo = q;
      
    actual = q; // el nuevo elemento pasa a ser el actual
  } // fin else

  numeroDeElementos++; // incrementar el n�mero de elementos

  // Actualizar par�metros de la lcde
  lcde->ultimo = ultimo;
  lcde->actual = actual;
  lcde->numeroDeElementos = numeroDeElementos;
  lcde->posicion = posicion;
}

void *borrar(tlcde *lcde)
{
  // Obtener los par�metros de la lcde
  Elemento *ultimo = lcde->ultimo;
  Elemento *actual = lcde->actual;
  int numeroDeElementos = lcde->numeroDeElementos;
  int posicion = lcde->posicion;

  // La funci�n borrar devuelve los datos del elemento
  // apuntado por actual y lo elimina de la lista.
  Elemento *q = NULL;
  void *datos = NULL;
    
  if( ultimo == NULL ) return NULL;  // lista vac�a.
  if( actual == ultimo ) // se trata del �ltimo elemento.
  {
    if( numeroDeElementos == 1 ) // hay un solo elemento
    {
      datos = ultimo->dato;
      free(ultimo);
      ultimo = actual = NULL;
      numeroDeElementos = 0;
      posicion = -1;
    }
    else // hay m�s de un elemento
    {    
      actual = ultimo->anterior;
      ultimo->siguiente->anterior = actual;
      actual->siguiente = ultimo->siguiente;
      datos = ultimo->dato;
      free(ultimo);
      ultimo = actual;
      posicion--;
      numeroDeElementos--;
    }  // fin del bloque else
  }    // fin del bloque if( actual == ultimo )
  else // el elemento a borrar no es el �ltimo
  {
    q = actual->siguiente;
    actual->anterior->siguiente = q;
    q->anterior = actual->anterior;
    datos = actual->dato;
    free(actual);
    actual = q;
    numeroDeElementos--;
  }

  // Actualizar par�metros de la lcde
  lcde->ultimo = ultimo;
  lcde->actual = actual;
  lcde->numeroDeElementos = numeroDeElementos;
  lcde->posicion = posicion;

  return datos;
}

void irAlSiguiente(tlcde *lcde)
{
  // Avanza la posici�n actual al siguiente elemento.
  if (lcde->posicion < lcde->numeroDeElementos - 1)
  {
    lcde->actual = lcde->actual->siguiente;
    lcde->posicion++;
  } 
}

void irAlAnterior(tlcde *lcde)
{
  // Retrasa la posici�n actual al elemento anterior.
  if ( lcde->posicion > 0 )
  {
    lcde->actual = lcde->actual->anterior;
    lcde->posicion--;
  }
}

void irAlPrincipio(tlcde *lcde)
{
  // Hace que la posici�n actual sea el principio de la lista.
  lcde->actual = lcde->ultimo->siguiente;
  lcde->posicion = 0;
}

void irAlFinal(tlcde *lcde)
{
  // El final de la lista es ahora la posici�n actual.
  lcde->actual = lcde->ultimo;
  lcde->posicion = lcde->numeroDeElementos - 1;
}

int irAl(int i, tlcde *lcde)
{
  int n = 0;
  if (i >= lcde->numeroDeElementos || i < 0) return 0;
  
  irAlPrincipio(lcde);
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
    irAlSiguiente(lcde);
  return 1;
}

void *obtenerActual(tlcde *lcde)
{
  // La funci�n obtener devuelve el puntero a los datos
  // asociados con el elemento actual.
  if ( lcde->ultimo == NULL ) return NULL; // lista vac�a

  return lcde->actual->dato;
}

void *obtener(int i, tlcde *lcde)
{
  // La funci�n obtener devuelve el puntero a los datos
  // asociados con el elemento de �ndice i.
  if (!irAl(i, lcde)) return NULL;
  return obtenerActual(lcde);
}

void modificar(void *pNuevosDatos, tlcde *lcde)
{
  // La funci�n modificar establece nuevos datos para el
  // elemento actual.
  if(lcde->ultimo == NULL) return; // lista vac�a
    
  lcde->actual->dato = pNuevosDatos;
}
//////////////////////////////////////////////////////////////////
