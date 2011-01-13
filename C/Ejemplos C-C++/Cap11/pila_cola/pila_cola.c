//////////////////////////////////////////////////////////////////
// Pilas y colas
//
// pila_cola.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_pila_cola.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

void mostrarLista(Elemento **lista, int tipo)
{
  // Mostrar todos los elementos de la lista
  int i = 0 , tam = tamanyo(*lista);
  Datos *alumno = NULL;
  while (i < tam)
  {
    if (tipo == 0) // pila
      alumno = (Datos *)sacarDePila(lista);
    else // cola
      alumno = (Datos *)sacarDeCola(lista);
    printf("%s %g\n", alumno->nombre, alumno->nota);
    free(alumno);
    i++;
  }
  if (tam == 0 && tipo == 0)
    printf("pila vacía\n");
  if (tam == 0 && tipo == 1)
    printf("cola vacía\n");
}

void liberarMemoria(Elemento **lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = NULL;
  // borrar: borra siempre el primer elemento
  alumno = borrar(lista);
  while (alumno)
  {
    free(alumno); // borrar el área de datos del elemento eliminado
    alumno = borrar(lista); // borrar elemento de la lista
  }
}

main()
{
  char nombre[50];
  double nota;

  // Pila y cola vacías
  Elemento *pila = NULL;
  Elemento *cola = NULL;

  // Leer datos y añadirlos a la pila y a la cola
  Datos *alumno1 = NULL, *alumno2 = NULL;

  printf("Introducir datos. Finalizar con eof.\n");
  printf("Nombre: ");
  while (gets(nombre) != NULL)
  {
    printf("Nota:   ");
    scanf("%lf", &nota); fflush(stdin);
    // Crear dos objetos de tipo Datos, uno para la pila y otro
    // para la cola.
    alumno1 = (Datos *)malloc(sizeof(Datos));
    alumno2 = (Datos *)malloc(sizeof(Datos));
    if (!alumno1 && !alumno2) error();
    // Asignar los datos
    strcpy(alumno1->nombre, nombre);
    alumno1->nota = nota;
    *alumno2 = *alumno1;

    meterEnPila(alumno1, &pila);
    meterEnCola(alumno2, &cola);
    printf("\nNombre: ");
  }

  printf("\n");
  // Mostrar la pila
  printf("\nPila:\n");
  mostrarLista(&pila, 0);
  // Mostrar la pila por segunda vez
  printf("\nPila:\n");
  mostrarLista(&pila, 0);

  printf("\n");
  // Mostrar la cola
  printf("\nCola:\n");
  mostrarLista(&cola, 1);
  // Mostrar la cola por segunda vez
  printf("\nCola:\n");
  mostrarLista(&cola, 1);

  // Borrar la pila y la cola
  liberarMemoria(&pila);
  liberarMemoria(&cola);
}

