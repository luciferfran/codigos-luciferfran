#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash.h"

//////////////////////////////////////////////////////////////////
// Interfaz hash abierto: método hash abierto.
// Para utilizar las funciones proporcionadas por esta interfaz,
// tendremos que definir en la aplicación las funciones:
// fa (función de acceso) y comparar.
//
// Mostrar un mensaje de error y abortar el programa
void error()
{
  printf("Insuficiente memoria\n");
  exit(1);
}
// Buscar un número primo a partir de un número dado ///////////
int numeroPrimo(int n)
{
  int primo = 0;
  int i, r = (int)sqrt((double)n);
  
  if (n % 2 == 0) n++;
  while (!primo)
  {
    primo = 1;
    for (i = 3; i <= r; i += 2)
      if (n % i == 0) primo = 0;
    if (!primo) n += 2; // siguiente impar
  }
  return n;
}

// Iniciar la matriz hash
IniciarMatrizHash(tMatrizHash *mh, int n_elementos)
{
  if (n_elementos < 1)
    mh->n_elementos = 101;
  else
    mh->n_elementos = numeroPrimo(n_elementos);
  mh->matrizhash = (void **)malloc(mh->n_elementos * sizeof(void *));
  if (mh->matrizhash == NULL) error();
  memset(mh->matrizhash, 0, mh->n_elementos * sizeof(void *));
}

// Añadir un elemento a la matriz hash
int hashIn(void *x, tMatrizHash mh)
{
  int i;         // índice para acceder a un elemento
  int conta = 0; // contador
  int insertado = 0;
  
  i = fa(x, mh);     // función de acceso
  while (conta < mh.n_elementos)
  {
    if (mh.matrizhash[i] == NULL) // elemento libre
    {
      mh.matrizhash[i] = x;
      insertado = 1;
      break;
    }
    else // ¿clave duplicada?
      if (comparar(x, mh.matrizhash[i]) == 0)
      {
        printf("error: clave duplicada\n");
        insertado = 0;
        break;
      }
      else // colisión
      {
        // Siguiente elemento libre
        i++; conta++;
        if (i == mh.n_elementos) i = 0;
      }
  }
  if (conta == mh.n_elementos)
  {
    printf("error: matriz llena\n");
    insertado = 0;
  }
  return insertado;
}

// Buscar un objeto con una clave determinada
void *hashOut(void *x, tMatrizHash mh)
{
  // x proporcionará el atributo utilizado para buscar. El resto
  // de los atributos no interesan (son los que se desea conocer)

  int i;         // índice para acceder a un elemento
  int conta = 0; // contador
  int encontrado = 0;
  
  i = fa(x, mh);     // función de acceso
  while (!encontrado && conta < mh.n_elementos)
  {
    if (mh.matrizhash[i] == NULL) return NULL;
    if (comparar(x, mh.matrizhash[i]) == 0)
    {
      x = mh.matrizhash[i];
      encontrado = 1;
    }
    else // colisión
    {
      // Siguiente elemento libre
      i++; conta++;
      if (i == mh.n_elementos) i = 0;
    }
  }
  if (conta == mh.n_elementos) // no existe
    return NULL;
  else
    return x;
}

void borrarMatrizHash(tMatrizHash mh)
{
  // Liberar la memoria ocupada por la matriz.
  int i = 0;
  for ( i = 0; i < mh.n_elementos; i++ )
    liberarmem( mh.matrizhash[i] );
  free(mh.matrizhash);
}
//////////////////////////////////////////////////////////////////
