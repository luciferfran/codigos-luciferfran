/* interfaz_abb.h
 */
#if !defined(_INTERFAZ_ABB_H)
#define _INTERFAZ_ABB_H


// Tipo Nodo (un elemento del árbol) /////////////////////////////
#include "nodo.h"

// Interfaz para manipular un árbol binario de búsqueda //////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Nodo *nuevoNodo();

// La función siguiente debe ser definida para que permita
// comparar dos nodos del árbol por el atributo que necesitemos
// en cada momento.
int comparar(void *datos1, void *datos2);

// La función siguiente debe ser definida para que permita
// especificar las operaciones que se deseen realizar con
// el nodo visitado.
void procesar(void *datos);

// La función siguiente debe ser definida para que permita
// especificar liberar la memoria referenciada por el
// miembro datos de Nodo.
void liberarmem(void *datos);

// Buscar un nodo
void *buscar(void *datos, Nodo *raiz);

// Insertar un nodo
int insertar(void *datos, Nodo **raiz);

// Borrar un nodo
void *borrar(void *datos, Nodo **raiz);

// Recorrer el árbol
void inorden(Nodo *raiz);

// Liberar la memoria asignada a los nodos del árbol
void borrarArbol(Nodo **raiz);


#endif // _INTERFAZ_ABB_H