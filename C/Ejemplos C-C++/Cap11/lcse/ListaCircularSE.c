//////////////////////////////////////////////////////////////////
// Crear una lista circular simplemente enlazada (lcse)
// ListaCircularSE.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_lcse.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

void mostrarLista(Elemento *lista)
{
  // Mostrar todos los elementos de la lista
  int i = 0 , tam = tamanyo(lista);
  Datos *alumno = NULL;
  while (i < tam)
  {
    alumno = (Datos *)obtener(i, lista);
    printf("%s %g\n", alumno->nombre, alumno->nota);
    i++;
  }
  if (tam == 0) printf("lista vacía\n");
}

void liberarMemoria(Elemento **lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = NULL;
  // borrar: borra siempre el primer elemento
  alumno = (Datos *)borrar(lista);
  while (alumno)
  {
    free(alumno); // borrar el área de datos del elemento eliminado
    alumno = (Datos *)borrar(lista);
  }
}

main()
{
  char nombre[50];
  double nota;
  // Lista circular vacía
  Elemento *lcse = NULL;
  // Leer datos y añadirlos a la lista
  Datos *alumno = NULL;

  printf("Introducir datos. Finalizar con eof.\n");
  printf("Nombre: ");
  while (gets(nombre) != NULL)
  {
    printf("Nota: ");
    scanf("%lf", &nota); fflush(stdin);
    // Crear un objeto de tipo Datos
    alumno = (Datos *)malloc(sizeof(Datos));
    if (!alumno) error();
    strcpy(alumno->nombre, nombre);
    alumno->nota = nota;
    anyadirAlFinal(alumno, &lcse);
    printf("\nNombre: ");
  }

  // Añadir un objeto al principio
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error();
  strcpy(alumno->nombre, "alumno x");
  alumno->nota = 10;
  anyadirAlPrincipio(alumno, &lcse);

  printf("\n\n");
  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(lcse);

  // Borrar el elemento primero
  if (alumno = (Datos *)borrar(&lcse))
    free(alumno); // borrar área de datos
  
  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(lcse);

  // Borrar la lista
  liberarMemoria(&lcse);
}

