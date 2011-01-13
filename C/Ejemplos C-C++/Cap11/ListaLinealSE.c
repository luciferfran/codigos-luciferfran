//////////////////////////////////////////////////////////////////
// Crear una lista lineal simplemente enlazada (llse)
// ListaLinealSE.c
//
#include <stdio.h>
#include <stdlib.h>

// Tipo Elemento (un elemento de la lista) ///////////////////////
typedef struct s
{
  double dato;         // �rea de datos
  struct s *siguiente; // puntero al siguiente elemento
} Elemento;
//////////////////////////////////////////////////////////////////

// Interfaz para manipular una llse //////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error()
{
  printf("Insuficiente memoria\n");
  exit(1);
}

// Crear un nuevo elemento
Elemento *nuevoElemento()
{
  Elemento *q = (Elemento *)malloc(sizeof(Elemento));
  if (!q) error();
  return q;
}

// A�adir un elemento al principio de la lista
void anyadirAlPrincipio(double n, Elemento **lista)
{
  Elemento *p = *lista;

  Elemento *q = nuevoElemento();
  q->dato = n;      // asignaci�n de valores
  q->siguiente = p; // reasignaci�n de punteros
  p = q;

  *lista = p;
}

/*
// Mostrar todos los elementos de la lista
void mostrarTodos(Elemento *p)
{
  // Recorrer la lista
  Elemento *q = p; // puntero al primer elemento
  while (q != NULL)
  {
    printf("%g ", q->dato);
    q = q->siguiente;
  }
}
*/

// Obtener el elemento de la lista
Elemento *obtener(int i, Elemento *q)
{
  int n = 0;

  if (q == NULL)
  {
    printf("lista vac�a\n");
    return NULL;
  }
  
  if (i >= 0)
  {
    // Posicionarse en el elemento i
    for (n = 0; q != NULL && n < i; n++)
      q = q->siguiente;

    // Retornar el elemento
    if (q != NULL) return q;
  }

  // �ndice fuera de l�mites
  return NULL;
}

// Borrar todos los elementos de la lista
void borrarTodos(Elemento **lista)
{
  Elemento *p = *lista, *q = NULL;

  // Recorrer la lista
  while (p != NULL)
  {
    q = p;
    p = p->siguiente;
    free(q); // eliminar el elemento apuntado por q
  }

  *lista = NULL; // lista vac�a
}
//////////////////////////////////////////////////////////////////

// Aplicaci�n ListaLinealSE //////////////////////////////////////
main()
{
  int i = 0;

  // Definir una lista lineal vac�a: llse
  Elemento *llse = NULL, *q = NULL;
  
  // Leer los datos y a�adirlos a la lista
  double n;

  printf("Introducir datos. Finalizar con eof.\n");
  printf("Valor double: ");
  while (scanf("%lf", &n) != EOF)
  {
    anyadirAlPrincipio(n, &llse);
    printf("Valor double: ");
  }

  // Mostrar la lista de datos
  printf("\n");
  i = 0;
  q = obtener(i, llse);
  while (q != NULL)
  {
    printf("%g ", q->dato);
    i++;
    q = obtener(i, llse);
  }

  // Borrar la lista
  borrarTodos(&llse);
}
