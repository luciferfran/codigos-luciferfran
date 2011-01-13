/* interfaz_llse.h
 */
#if !defined(_INTERFAZ_LLSE_H)
#define _INTERFAZ_LLSE_H


// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Interfaz para manipular una llse //////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Número de elementos de la lista
int tamanyo(Elemento *p);

// Añadir un elemento en la posición i
int anyadir(int i, void *e, Elemento **lista);

// Añadir un elemento al principio de la lista
int anyadirAlPrincipio(void *e, Elemento **lista);

// Añadir un elemento al final de la lista
int anyadirAlFinal(void *e, Elemento **lista);

// Borrar el elemento i de la lista
void *borrar(int i, Elemento **lista);

// Borrar el primer elemento de la lista
void *borrarPrimero(Elemento **lista);

// Borrar el último elemento de la lista
void *borrarUltimo(Elemento **lista);

// Obtener el elemento i de la lista
void *obtener(int i, Elemento *lista);

// Obtener el primer elemento de la lista
void *obtenerPrimero(Elemento *lista);

// Obtener el último elemento de la lista
void *obtenerUltimo(Elemento *lista);


#endif // _INTERFAZ_LLSE_H