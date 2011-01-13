/* interfaz_lcse.h
 */
#if !defined(_INTERFAZ_LCSE_H)
#define _INTERFAZ_LCSE_H


// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Interfaz para manipular una lcse //////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Número de elementos de la lista
int tamanyo(Elemento *p);

// Añadir un elemento al principio de la lista
void anyadirAlPrincipio(void *e, Elemento **p);

// Añadir un elemento al final de la lista
void anyadirAlFinal(void *e, Elemento **p);

// Borrar el elemento primero de la lista
void *borrar(Elemento **p);

// Obtener el elemento i de la lista
void *obtener(int i, Elemento *ultimo);


#endif // _INTERFAZ_LCSE_H