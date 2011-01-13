//////////////////////////////////////////////////////////////////
// Frecuencia con la que aparecen las palabras en un texto.
// palabras.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_abb.h"

typedef struct
{
  char *palabra;
  int contador;
} Datos;

int totalPalabras = 0;
int totalPalabrasDiferentes = 0;

/////////////////////////////////////////////////////////////////
// Definir las funciones: comparar, procesar y liberarmem, según
// los prototipos especificados en interfaz_abb.h, para
// adaptarlas a nuestras necesidades.
//
// Permite comparar los datos de dos nodos.
int comparar(void *datos1, void *datos2)
{
  return strcmp(((Datos *)datos1)->palabra,
                ((Datos *)datos2)->palabra);
}

// Permite mostrar los datos del nodo visitado.
void procesar(void *datos)
{
  Datos *ocurrencia = (Datos *)datos;
  printf("%s = %d\n", ocurrencia->palabra, ocurrencia->contador);
}

// Liberar la memoria del área de datos del nodo visitado.
void liberarmem(void *datos)
{
  free(((Datos *)datos)->palabra);
  free((Datos *)datos);
}
/////////////////////////////////////////////////////////////////

void mostrarArbol(Nodo *raiz)
{
  inorden(raiz);
}

int esAlfa(int c) // es una letra entre la A - Z o a - z
{
  return (tolower(c) >= 'a' && tolower(c) <= 'z');
}

int esVocalAc(int c) // c ¿es una vocal acentuada?
{
  // Valores ASCII de á, é, í, ó, ú: 160, 130, ...
  return c == 160 || c == 130 || c == 161 || c == 162 || c == 163;
}

char *leerPalabra(FILE *pf)
{
  // Leer una palabra del fichero referenciado por pf. La palabra
  // queda finalmente apuntada por "palabra"
  int c;
  char *palabra = NULL, *inicio = NULL;
  
  // Eliminar los caracteres que no forman parte de la palabra
  while ((c = fgetc(pf)) != EOF && !esAlfa(c) && !esVocalAc(c));
  if (c == EOF) return NULL;
  
  // Leer una palabra
  palabra = (char *)malloc(256);
  if (!palabra) error();
  inicio = palabra;
  *palabra++ = c;
  while ((c = fgetc(pf)) != EOF && esAlfa(c) || esVocalAc(c))
    *palabra++ = c;
  *palabra = '\0';
  // Ajustar el tamaño del bloque de memoria a la palabra
  palabra = realloc(inicio, palabra - inicio + 1);

  // Incrementar el contador de palabras leídas
  totalPalabras++;
  return palabra;
}

int main(int argc, char *argv[])
{
  Nodo *raiz = NULL; // árbol binario de búsqueda
  Datos *ocurrencia = NULL, *encontrado = NULL;

  char *palabra = NULL;
  FILE *pf = NULL;

  // Analizar la línea de órdenes y abrir el fichero
  if (argc < 2)
    pf = stdin;
  else if ((pf = fopen(argv[1], "r")) == NULL)
  {
    perror(argv[1]);
    return -1;
  }

  // Leer las palabras del fichero y construir el árbol binario de
  // búsqueda
  while (palabra = leerPalabra(pf))
  {
    // Crear una estructura de tipo Datos
    ocurrencia = (Datos *)malloc(sizeof(Datos));
    if (!ocurrencia) error();
    ocurrencia->palabra = palabra;
    encontrado = (Datos *)buscar(ocurrencia, raiz);
    ocurrencia->contador = 1;
    if (!encontrado)
    {
      insertar(ocurrencia, &raiz);
      totalPalabrasDiferentes++;
    }
    else
    {
      encontrado->contador++;
      free(ocurrencia->palabra);
      free(ocurrencia);
    }
  }
	
  // Mostrar la árbol
  printf("\nArbol:\n");
  mostrarArbol(raiz);
  printf("\nTotal palabras = %d\n", totalPalabras);
  printf("Total palabras diferentes = %d\n", totalPalabrasDiferentes);

  // Borrar el árbol
  borrarArbol(&raiz);

  // Cerrar el fichero
  fclose(pf);
  return 1;
}

