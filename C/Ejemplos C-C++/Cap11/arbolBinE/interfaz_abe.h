/* interfaz_abe.h
 */
#if !defined(_INTERFAZ_ABB_H)
#define _INTERFAZ_ABB_H


// Tipo Nodo (un elemento del �rbol) /////////////////////////////
#include "nodo.h"

// Interfaz para manipular un �rbol binario equilibrado //////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Nodo *nuevoNodo();

// Leer los datos que ser�n referenciados por un nodo del �rbol.
void *leerDatos();

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

// Construye un �rbol de n nodos perfectamente equilibrado
Nodo *construirArbol(int n);

// Buscar un determinado nodo en el �rbol. Llama a buscarNodo
// para asegurar que inicialmente el valor de *res es NULL.
void buscar(void *datos, Nodo *raiz, void **res, int *pos);

// Buscar un determinado nodo en el �rbol.
void buscarNodo(void *datos, Nodo *raiz, void **res, int *pos, int *i);

// Recorrer el �rbol
void inorden(Nodo *raiz);

// Liberar la memoria asignada a los nodos del �rbol
void borrarArbol(Nodo **raiz);


#endif // _INTERFAZ_ABB_H