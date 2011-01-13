/* hash.h
 */
#if !defined(_HASH_H)
#define _HASH_H

typedef struct
{
  int clave;
  int numReg;
} tRegInd;

typedef struct
{
  FILE *pfInd;
  FILE *pfDat;
  int n_regs;
} tMatrizHash;

////////////////////////////////////////////////////////////////
// Interfaz hash abierto: m�todo hash abierto.
//
// Mostrar mensaje de error y abortar el programa.
void error();

// Buscar un n�mero primo a partir de un n�mero dado ///////////
int numeroPrimo(int n);

// Iniciar la estructura de tipo tMatrizHash
// (encapsula los punteros a los ficheros �ndice y datos
// y el n�mero de registros)
iniciarFicheros(tMatrizHash *mh);

// Las dos funciones siguientes dan acceso al �ndice.

// A�adir un elemento a la matriz hash.
// Devielve 1 si se jecuta satisfactoriamente y 0 en otro caso.
int hashIn(tRegInd x, tMatrizHash mh);

// Buscar un objeto con una clave determinada.
// Devuelve el n�mero del registro encontrado (el primero es el 0)
// o -1 si no se encuentra.
int hashOut(tRegInd x, tMatrizHash mh);


#endif // _HASH_H
