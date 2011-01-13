/* interfaz_abe.h
 */
#if !defined(_INTERFAZ_ABB_H)
#define _INTERFAZ_ABB_H


// Tipo Nodo (un elemento del árbol) /////////////////////////////
#include "nodo.h"

// Interfaz para manipular un árbol binario equilibrado //////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Nodo *nuevoNodo();

// Leer los datos que serán referenciados por un nodo del árbol.
void *leerDatos();

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

// Construye un árbol de n nodos perfectamente equilibrado
Nodo *construirArbol(int n);

// Buscar un determinado nodo en el árbol. Llama a buscarNodo
// para asegurar que inicialmente el valor de *res es NULL.
void buscar(void *datos, Nodo *raiz, void **res, int *pos);

// Buscar un determinado nodo en el árbol.
void buscarNodo(void *datos, Nodo *raiz, void **res, int *pos, int *i);

// Recorrer el árbol
void inorden(Nodo *raiz);

// Liberar la memoria asignada a los nodos del árbol
void borrarArbol(Nodo **raiz);


#endif // _INTERFAZ_ABB_H