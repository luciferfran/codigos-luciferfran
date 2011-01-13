/* interfaz_llseo.h
 */
#if !defined(_INTERFAZ_LLSEO_H)
#define _INTERFAZ_LLSEO_H


// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Tipo tllseo (lista linea simplemente enlaza y ordenada) ///////
typedef struct
{
  Elemento *p;            // elemento de cabecera
  Elemento *elemAnterior; // elemento anterior
  Elemento *elemActual;   // elemento actual
} tllseo;

// Interfaz para manipular una llseo /////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Iniciar una lista
void iniciarLista(tllseo *lista);

// Indicar si la lista est� o no vac�a
int listaVacia(tllseo *lista);

// La funci�n siguiente debe ser definida en la aplicaci�n que
// utilice esta interfaz para que permita comparar dos elementos
// de la lista por el atributo que necesitemos en cada momento.
int comparar(void *datos1, void *datos2);

// A�adir un elemento en orden ascendente seg�n una clave
void anyadir(void *e, tllseo *lista);

// Buscar un elemento en la lista
int buscar(void *e, tllseo *lista);

// Borrar un elemento determinado de la lista
void *borrar(void *e, tllseo *lista);

// Borrar el elemento primero de la lista
void *borrarPrimero(tllseo *lista);

// Obtener el primer elemento de la lista
void *obtenerPrimero(tllseo *lista);

// Obtener el siguiente elemento al actual
void *obtenerSiguiente(tllseo *lista);


#endif // _INTERFAZ_LLSEO_H
