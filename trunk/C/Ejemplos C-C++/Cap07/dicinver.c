/********************* Diccionario inverso *********************/
/* dicinver.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LeerPalabras(char **palabra, int nFilas);
int Comparar(char *cad1, char *cad2);
void OrdenarPalabras(char **palabra, int filas);
void VisualizarPalabras(char **palabra, int filas);

int main() 
{
  char **palabra = NULL;
  int nFilas = 0;
  int correcto = 0, filas = 0, f = 0;

  do
  {
    printf("Número de filas de la matriz:    ");
    correcto = scanf("%u", &nFilas);
    fflush(stdin);
  }
  while ( !correcto || nFilas < 1 );

  // Asignar memoria para la matriz de punteros
  if ((palabra = (char **)malloc(nFilas * sizeof(char *))) == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }

  // Operaciones
  filas = LeerPalabras(palabra, nFilas);
  OrdenarPalabras(palabra, filas);
  VisualizarPalabras(palabra, filas);
  
  // Liberar la memoria asignada a cada una de las filas
  for ( f = 0; f < filas; f++ )
    free(palabra[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(palabra);
  return 0;
}

int LeerPalabras(char **palabra, int nFilas)
{
  int f = 0, longitud = 0;
  char pal[81];
  
  printf("Introducir palabras.\n");
  printf("Para finalizar introduzca una palabra nula.\n");
  printf("Esto es, pulse sólo <Entrar>.\n");

  while (f < nFilas && (longitud = strlen(gets(pal))) > 0)
  {
    // Asignar espacio para una palabra
    if ((palabra[f] = (char *)malloc(longitud + 1)) == NULL)
    {
      printf("Insuficiente espacio de memoria disponible\n");
      return -1;	// terminar el proceso
    }
    // Copiar la palabra en el espacio de memoria asignado
    strcpy(palabra[f], pal);
    f++;
  }
  return f;
}

int Comparar(char *cad1, char *cad2)
{
  int i, j;
  
  i = strlen(cad1) - 1;
  j = strlen(cad2) - 1;
  // Comparar las palabras de atrás hacia adelante
  while( i > 0 && j > 0 )
  {
    if ( cad1[i] != cad2[j] )
      return (cad1[i] - cad2[j]);
    i--;
    j--;
  }
  return cad1[i] - cad2[j];
}

void OrdenarPalabras(char **palabra, int filas)
{
  char *aux;  // puntero auxiliar
  int i = 0, k = 0;
  
  // Método de inserción
  for ( i = 1; i < filas; i++ )
  {
    aux = palabra[i];
    k = i - 1;
    while ( (k >= 0) && (Comparar(aux, palabra[k]) < 0) )
    {
      palabra[k+1] = palabra[k];
      k--;
    }
    palabra[k+1] = aux;
  }
}

void VisualizarPalabras(char **palabra, int filas)
{
  int f = 0;

  for ( f = 0; f < filas; f++ )
    printf("%s\n", palabra[f]);
}
