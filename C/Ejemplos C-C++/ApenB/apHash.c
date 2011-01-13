#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

typedef struct
{
  int matricula;
  char nombre[50];
} tAlumno;

//////////////////////////////////////////////////////////////////
// Para utilizar la interfaz hash abierto hay que definir jas
// funciones: fa (funci�n de acceso), comparar y liberarmem.
//
// Definir la funci�n de acceso
int fa(void *arg, tMatrizHash mh)
{
  tAlumno *a = (tAlumno *)arg;
  return a->matricula % mh.n_elementos;
}

// Comparar dos elementos de la matriz hash
int comparar(void *arg1, void *arg2)
{
  tAlumno *a1 = (tAlumno *)arg1;
  tAlumno *a2 = (tAlumno *)arg2;

  if (a1->matricula == a2->matricula)
    return 0;
  else
    return 1;
}

// Liberar la memoria del �rea de datos de cada
// elemento de la matriz.
void liberarmem(void *arg)
{
  free((tAlumno *)arg);
}
//////////////////////////////////////////////////////////////////

main()
{
  // Definici�n de variables
  int n_elementos = 101; // n�mero de elementos de la matriz hash

  tAlumno *x = NULL, a = {0, ""};
  tMatrizHash mh = {NULL, 0};

  // Crear una estructura de tipo tMatrizHash
  // (encapsula la matriz hash)
  printf("N�mero de elementos:  ");
  scanf("%d", &n_elementos);
  IniciarMatrizHash(&mh, n_elementos);
  printf("Se construye una matriz de %d elementos\n", mh.n_elementos);
  
  // Introducir datos
  printf("Introducir datos. Para finalizar, matr�cula = 0\n");
  printf("matr�cula:  "); scanf("%d", &a.matricula);
  fflush(stdin);
  while (a.matricula != 0)
  {
    printf("nombre:     "); gets(a.nombre);
    x = (tAlumno *)malloc(sizeof(tAlumno));
    if (x == NULL) error();
    x->matricula = a.matricula;
    strcpy(x->nombre, a.nombre);
    if (!hashIn(x, mh)) free(x);
    printf("matr�cula:  "); scanf("%d", &a.matricula);
    fflush(stdin);
  }
  
  // Buscar datos
  printf("Buscar datos. Para finalizar, matr�cula = 0\n");
  strcpy(a.nombre, "");
  printf("matr�cula:  "); scanf("%d", &a.matricula);
  while (a.matricula != 0)
  {
    x = (tAlumno *)hashOut(&a, mh);
    if (x != NULL)
      printf("nombre: %s\n", x->nombre);
    else
      printf("No existe\n");
    printf("matr�cula:  "); scanf("%d", &a.matricula);
  }
  borrarMatrizHash(mh);
}

