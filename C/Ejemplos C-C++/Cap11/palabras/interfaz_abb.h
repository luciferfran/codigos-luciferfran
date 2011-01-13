/* interfaz_abb.h
 */
#if !defined(_INTERFAZ_ABB_H)
#define _INTERFAZ_ABB_H


// Tipo Nodo (un elemento del �rbol) /////////////////////////////
#include "nodo.h"

// Interfaz para manipular un �rbol binario de b�squeda //////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Nodo *nuevoNodo();

// La funci�n siguiente debe ser definida para que permita
// comparar dos nodos del �rbol por el atributo que necesitemos
// en cada momento.
int comparar(void *datos1, void *datos2);

// La funci�n siguiente debe ser definida para que permita
// especificar las operaciones que se deseen realizar con
// el nodo visitado.
void procesar(void *datos);

// La funci�n siguiente debe ser definida para que permita
// especificar liberar la memoria referenciada por el
// miembro datos de Nodo.
void liberarmem(void *datos);

// Buscar un nodo
void *buscar(void *datos, Nodo *raiz);

// Insertar un nodo
int insertar(void *datos, Nodo **raiz);

// Borrar un nodo
void *borrar(void *datos, Nodo **raiz);

// Recorrer el �rbol
void inorden(Nodo *raiz);

// Liberar la memoria asignada a los nodos del �rbol
void borrarArbol(Nodo **raiz);


#endif // _INTERFAZ_ABB_H