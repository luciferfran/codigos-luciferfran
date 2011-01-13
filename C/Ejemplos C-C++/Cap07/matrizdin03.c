/*********** Matriz dinámica de cadenas de caracteres ***********/
/* matrizdin03.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LeerCadenas(char **nombre, int nFilas);
void OrdenarCadenas(char **nombre, int filas);
void VisualizarCadenas(char **nombre, int filas);

main() 
{
  char **nombre = NULL;
  int nFilas = 0;
  int correcto = 0, filas = 0, f = 0;

  do
  {
    printf("Número de filas de la matriz:    ");
    correcto = scanf("%d", &nFilas);
    fflush(stdin);
  }
  while ( !correcto || nFilas < 1 );

  // Asignar memoria para la matriz de punteros
  if ((nombre = (char **)malloc(nFilas * sizeof(char *))) == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }

  // Operaciones
  filas = LeerCadenas(nombre, nFilas);
  if ( filas == -1 ) return -1;
  OrdenarCadenas(nombre, filas);
  VisualizarCadenas(nombre, filas);
  
  // Liberar la memoria asignada a cada una de las filas
  for ( f = 0; f < filas; f++ )
    free(nombre[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(nombre);

  return 0;
}

int LeerCadenas(char **nombre, int nFilas)
{
  int f = 0, longitud = 0;
  char cadena[81];
  
  printf("Introducir cadenas de caracteres.\n");
  printf("Para finalizar introduzca una cadena nula.\n");
  printf("Esto es, pulse sólo <Entrar>.\n\n");

  while (f < nFilas && (longitud = strlen(gets(cadena))) > 0)
  {
    // Asignar espacio para una cadena de caracteres
    if ((nombre[f] = (char *)malloc(longitud + 1)) == NULL)
    {
      printf("Insuficiente espacio de memoria disponible\n");
      return -1;	// terminar el proceso
    }
    // Copiar la cadena en el espacio de memoria asignado
    strcpy(nombre[f], cadena);
    f++;
  }
  return(f);
}

void OrdenarCadenas(char **nombre, int filas)
{
  char *aux;  // puntero auxiliar
  int i = 0, s = 1;

  while ((s == 1) && (--filas > 0))
  {
    s = 0;  // no permutación
    for (i = 1; i <= filas; i++)
      if (strcmp(nombre[i-1], nombre[i]) > 0)
      {
        aux = nombre[i-1];
        nombre[i-1] = nombre[i];
        nombre[i] = aux;
        s = 1;  // permutación
      }
  }
}

void VisualizarCadenas(char **nombre, int filas)
{
  int f = 0;

  for ( f = 0; f < filas; f++ )
    printf("%s\n", nombre[f]);
}
