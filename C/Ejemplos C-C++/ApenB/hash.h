/* hash.h
 */
#if !defined(_HASH_H)
#define _HASH_H

typedef struct
{
  void **matrizhash;
  int n_elementos;
} tMatrizHash;

////////////////////////////////////////////////////////////////
// Interfaz hash abierto: método hash abierto.
//
// Mostrar mensaje de error y abortar el programa.
void error();

// Buscar un número primo a partir de un número dado ///////////
int numeroPrimo(int n);

// Funciones
IniciarMatrizHash(tMatrizHash *mh, int n_elementos);

// Función de acceso ///////////////////////////////////////////
// Esta función debe ser definida en la aplicación que utilice 
// esta interfaz para poder definir la función de acceso que el
// usuario desee aplicar.
int fa(void *arg, tMatrizHash mh);

// Función comparar ////////////////////////////////////////////
// Esta función debe ser definida en la aplicación para que
// permita comparar dos elementos de la matriz hash por el
// atributo que necesitemos en cada momento.
int comparar(void *arg1, void *arg2);

// Función liberarmem //////////////////////////////////////////
// Esta función debe ser definida en la aplicación para que
// permita liberar la memoria del área de datos de cada
// elemento de la matriz.
void liberarmem(void *arg);

// Añadir un elemento a la matriz hash.
int hashIn(void *x, tMatrizHash mh);

// Buscar un objeto con una clave determinada.
void *hashOut(void *x, tMatrizHash mh);

// Liberar la memoria ocupada por la matriz.
void borrarMatrizHash(tMatrizHash mh);


#endif // _HASH_H
