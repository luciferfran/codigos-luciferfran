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
// Interfaz hash abierto: m�todo hash abierto.
//
// Mostrar mensaje de error y abortar el programa.
void error();

// Buscar un n�mero primo a partir de un n�mero dado ///////////
int numeroPrimo(int n);

// Funciones
IniciarMatrizHash(tMatrizHash *mh, int n_elementos);

// Funci�n de acceso ///////////////////////////////////////////
// Esta funci�n debe ser definida en la aplicaci�n que utilice 
// esta interfaz para poder definir la funci�n de acceso que el
// usuario desee aplicar.
int fa(void *arg, tMatrizHash mh);

// Funci�n comparar ////////////////////////////////////////////
// Esta funci�n debe ser definida en la aplicaci�n para que
// permita comparar dos elementos de la matriz hash por el
// atributo que necesitemos en cada momento.
int comparar(void *arg1, void *arg2);

// Funci�n liberarmem //////////////////////////////////////////
// Esta funci�n debe ser definida en la aplicaci�n para que
// permita liberar la memoria del �rea de datos de cada
// elemento de la matriz.
void liberarmem(void *arg);

// A�adir un elemento a la matriz hash.
int hashIn(void *x, tMatrizHash mh);

// Buscar un objeto con una clave determinada.
void *hashOut(void *x, tMatrizHash mh);

// Liberar la memoria ocupada por la matriz.
void borrarMatrizHash(tMatrizHash mh);


#endif // _HASH_H
