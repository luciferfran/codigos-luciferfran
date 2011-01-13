//////////////////////////////////////////////////////////////////
// Trabajar con una lista lineal simplemente enlazada (llse)
// ListaLinealSE.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_llse.h"

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
}

void liberarMemoria(Elemento **lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = NULL;
  alumno = (Datos *)borrarPrimero(lista); // borrar elemento de la lista
  while (alumno)
  {
    free(alumno); // borrar el área de datos del elemento eliminado
    alumno = (Datos *)borrarPrimero(lista); // borrar elemento de la lista
  }
}

main()
{
  char nombre[50];
  double nota;

  // Definir una lista lineal vacía: llse
  Elemento *llse = NULL;
  
  // Leer los datos y añadirlos a la lista
  Datos *alumno = NULL;

  printf("Introducir datos. Finalizar con eof.\n");
  printf("Nombre: ");
  while (gets(nombre) != NULL)
  {
    printf("Nota:   ");
    scanf("%lf", &nota); fflush(stdin);
    // Crear un objeto de tipo Datos
    alumno = (Datos *)malloc(sizeof(Datos));
    if (!alumno) error();
    strcpy(alumno->nombre, nombre);
    alumno->nota = nota;
    anyadirAlFinal(alumno, &llse);
    printf("\nNombre: ");
  }

  // Añadir un objeto al principio
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error();
  strcpy(alumno->nombre, "alumno x");
  alumno->nota = 10;
  anyadirAlPrincipio(alumno, &llse);

  // Añadir un objeto en la posición 1
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error();
  strcpy(alumno->nombre, "alumno y");
  alumno->nota = 9.5;
  anyadir(1, alumno, &llse);

  printf("\n\n");
  // Mostrar el primero
  alumno = (Datos *)obtenerPrimero(llse);
  if (alumno)
    printf("Primero: %s %g\n", alumno->nombre, alumno->nota);
  
  // Mostrar el último
  alumno = (Datos *)obtenerUltimo(llse);
  if (alumno)
    printf("Último: %s %g\n", alumno->nombre, alumno->nota);

  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(llse);

  // Borrar el elemento de índice 2
  if (alumno = (Datos *)borrar(2, &llse))
  {
    free(alumno); // borrar área de datos
  }
  else
    printf("Índice fuera de límites\n");
  
  // Modificar el elemento de índice 1
  alumno = (Datos *)obtener(1, llse);
  if (alumno) alumno->nota = 9;

  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(llse);

  // Borrar la lista
  liberarMemoria(&llse);
}

