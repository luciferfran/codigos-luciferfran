/******************** Punteros a funciones ********************/
/* puntsfns.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define FMAX 100 // número máximo de filas

char *compnu(char *px, char *py);
char *compal(char *px, char *py);
char *fmenor(int n, char **pa, char *(*pfn)());

int main(int argc, char *argv[])
{
  char *pcadena[FMAX];  // matriz de punteros a los datos
  char dato[81];        // dato
  char *p;
  int c = 0, longitud;

  // Leer la lista de datos numéricos o alfanuméricos
  printf("Introducir datos y finalizar con <Entrar>\n\n");
  while (c < FMAX)
  {
    printf("Dato %d: ", c + 1);
    if ((longitud = strlen(gets(dato))) == 0)
      break;
    else
    {
      pcadena[c] = (char *)malloc(longitud+1);
      if (pcadena[c] == NULL)
      {
        printf("Insuficiente espacio de memoria\n");
        return -1;
      }
      else
        strcpy(pcadena[c++], dato);
    }
  }
  // argv[1] != "-n" -> búsqueda en una lista alfanumérica,
  // argv[1]  = "-n" -> búsqueda en una lista numérica
  
  if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'n')
    p = fmenor(c, pcadena, compnu);
  else
    p = fmenor(c, pcadena, compal);
  printf("\nEl elemento menor de la lista es: %s\n", p);

  return 0;
}

char *fmenor(int c, char *pcadena[], char *(*comparar)())
{
  // Buscar el dato menor de una lista
  char *menor;

  menor = *pcadena;  // menor = primer dato
  while ( --c > 0)
    // comparar menor con el siguiente dato
    menor = comparar(menor, *++pcadena);

  return menor;
}

char *compnu(char *px, char *py)
{
  // Comparar dos datos numéricamente
  if (atof(px) > atof(py))
    return py;
  else
    return px;
}

char *compal(char *px, char *py)
{
  // Comparar dos datos alfanuméricamente
  if (strcmp(px, py) > 0)
    return py;
  else
    return px;
}
