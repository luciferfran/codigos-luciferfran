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

// Añadir un elemento al principio de la lista
void anyadirAlPrincipio(void *e, Elemento **lista);

// Obtener el elemento de la lista
void *obtener(int i, Elemento *q);

// Borrar todos los elementos de la lista
void borrarTodos(Elemento **lista);


#endif // _INTERFAZ_LLSE_H