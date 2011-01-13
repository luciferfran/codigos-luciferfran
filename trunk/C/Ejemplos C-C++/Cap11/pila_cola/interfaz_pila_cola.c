// interfaz_pila_cola.c
//
#include "interfaz_lcse.h"

//////////////////////////////////////////////////////////////////
// Pila: lista en la que todas las inserciones y supresiones se
// hacen en un extremo de la misma.
//
// Invoca a las funciones anyadirAlPrincipio y borrar
// de interfaz_lcse.c
//
void meterEnPila(void *e, Elemento **p)
{
  anyadirAlPrincipio(e, p);
}

void *sacarDePila(Elemento **p)
{
  return borrar(p);
}
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Cola: lista en la que todas las inserciones se hacen por un
// extremo de la lista (por el final) y todas las supresiones se
// hacen por el otro extremo (por el principio).
//
// Invoca a las funciones anyadirAlFinal y borrar
// de interfaz_lcse.c
//
void meterEnCola(void *e, Elemento **p)
{
  anyadirAlFinal(e, p);
}

void *sacarDeCola(Elemento **p)
{
  return borrar(p);
}
//////////////////////////////////////////////////////////////////
