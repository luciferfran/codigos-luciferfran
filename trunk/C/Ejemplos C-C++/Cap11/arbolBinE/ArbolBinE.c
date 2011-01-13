//////////////////////////////////////////////////////////////////
// Crear un �rbol binario perfectamente equilibrado.
// ArbolBinE.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_abe.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

/////////////////////////////////////////////////////////////////
// Definir las funciones: leerDatos, comparar, procesar y
// liberarmem, seg�n los prototipos especificados en
// interfaz_abe.h, para adaptarlas a nuestras necesidades.
//
// Leer los datos que ser�n referenciados por un nodo del �rbol.
void *leerDatos()
{
  char nombre[50];
  double nota;
  Datos *alumno = NULL;

  printf("nombre: ");
  gets(nombre);
  printf("nota:   ");
  scanf("%lf", &nota); fflush(stdin);
  // Crear un objeto de tipo Datos
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error();
  strcpy(alumno->nombre, nombre);
  alumno->nota = nota;
  return (void *)alumno;
}

// Permite comparar los datos de dos nodos.
int comparar(void *datos1, void *datos2)
{
  char *nom1 = ((Datos *)datos1)->nombre;
  char *nom2 = ((Datos *)datos2)->nombre;
  return strcmp(nom1, nom2);
}

// Permite mostrar los datos del nodo visitado.
void procesar(void *datos)
{
  Datos *alumno = (Datos *)datos;
  printf("%s %g\n", alumno->nombre, alumno->nota);
}

// Liberar la memoria del �rea de datos del nodo visitado.
void liberarmem(void *datos)
{
  free((Datos *)datos);
}
/////////////////////////////////////////////////////////////////

void mostrarArbol(Nodo *raiz)
{
  inorden(raiz);
}

int main()
{
  Nodo *raiz = NULL; // �rbol binario equilibrado
  Datos *alumno = NULL, *alumBuscado;
  int numeroDeNodos = 0, pos = 0;

  printf("N�mero de nodos: ");
  scanf("%d", &numeroDeNodos); fflush(stdin);
  raiz = construirArbol(numeroDeNodos);
  if (raiz == NULL) return 0; // �rbol vac�o

  // Mostrar el �rbol
  printf("\nArbol:\n");
  mostrarArbol(raiz);

  // Buscar datos
  printf("Buscar todas las ocurrencias de nombre en el �rbol.\n");
  alumno = leerDatos();
  buscar(alumno, raiz, &alumBuscado, &pos);
  if ( alumBuscado == NULL ) printf("La b�squeda fall�\n");
  while (alumBuscado != NULL)
  {
    printf("Nodo %2d, nota es %g\n", pos, alumBuscado->nota);
    pos++;
    buscar(alumno, raiz, &alumBuscado, &pos);
  }
  free(alumno);

  // Borrar el �rbol
  borrarArbol(&raiz);

  return 0;
}

