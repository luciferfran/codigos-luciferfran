//////////////////////////////////////////////////////////////////
// Crear una lista circular doblemente enlazada (lcde)
// ListaCircularDE.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_lcde.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

void mostrarLista(tlcde *lista)
{
  // Mostrar todos los elementos de la lista
  int i = 0 , tam = lista->numeroDeElementos;
  Datos *alumno = NULL;
  while (i < tam)
  {
    alumno = (Datos *)obtener(i, lista);
    printf("%s %g\n", alumno->nombre, alumno->nota);
    i++;
  }
  if (tam == 0) printf("lista vacía\n");
}

void liberarMemoria(tlcde *lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = NULL;

  // borrar: borra siempre el elemento actual
  irAlPrincipio(lista);
  alumno = (Datos *)borrar(lista);
  while (alumno)
  {
    free(alumno); // borrar el área de datos del elemento eliminado
    alumno = (Datos *)borrar(lista);
  }
}

Datos *leerDatosAlumno()
{
  Datos *alumno = NULL;
  char nombre[50];
  double nota;

  printf("\nNombre: ");
  gets(nombre);
  printf("Nota:   ");
  scanf("%lf", &nota); fflush(stdin);
  // Crear un objeto de tipo Datos
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error();
  strcpy(alumno->nombre, nombre);
  alumno->nota = nota;
  return alumno;
}

main()
{
  char resp = 's';
  Datos *alumno = NULL; // datos a almacenar
  
  tlcde lcde; // lista circular doblemente enlazada
  iniciarLcde(&lcde); // iniciar la lista

  // Leer datos y añadirlos a la lista
  while (resp == 's')
  {
    alumno = leerDatosAlumno();
    insertar(alumno, &lcde);

    printf("¿desea insertar otro alumno? (s/n) ");
    resp = getchar(); fflush(stdin);
  } 

  printf("\nEl elemento de la posición 2 será el actual:\n");
  if (!irAl(2, &lcde))
    printf("Índice fuera de límites\n");

  printf("Borrar el elemento actual.\n");
  if (alumno = (Datos *)borrar(&lcde))
    free(alumno); // borrar área de datos
  else
    printf("No es posible borrar el elemento\n");
  
  printf("\nIr al elemento 1 e insertar uno nuevo:\n");
  if (!irAl(1, &lcde))
    printf("Índice fuera de límites\n");
  printf("Posición actual: %d\n", lcde.posicion);
  alumno = leerDatosAlumno();
  insertar(alumno, &lcde);
  
  printf("Ir al final e insertar un nuevo alumno:\n");
  irAlFinal(&lcde);
  alumno = leerDatosAlumno();
  insertar(alumno, &lcde);
  
  printf("Ir al anterior e insertar un nuevo alumno:\n");
  irAlAnterior(&lcde);
  alumno = leerDatosAlumno();
  insertar(alumno, &lcde);
  
  // Mostrar la lista
  printf("\nLista:\n");
  mostrarLista(&lcde);

  // Borrar la lista
  liberarMemoria(&lcde);
}

