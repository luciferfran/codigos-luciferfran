/* interfaz_pila_cola.h
 */
#if !defined(_INTERFAZ_PILA_COLA_H)
#define _INTERFAZ_PILA_COLA_H


// Incluir el tipo Elemento y la interfaz lcse ///////////////////
#include "interfaz_lcse.h"

// Interfaz para manipular una pila //////////////////////////////
//
// Meter un elemento en la pila
void meterEnPila(void *e, Elemento **p);

// Sacar un elemento de la pila
void *sacarDePila(Elemento **p);

// Interfaz para manipular una cola //////////////////////////////
//
// Meter un elemento en la cola
void meterEnCola(void *e, Elemento **p);

// Sacar un elemento de la cola
void *sacarDeCola(Elemento **p);


#endif // _INTERFAZ_PILA_COLA_H