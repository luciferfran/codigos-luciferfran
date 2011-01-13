/**************** Ordenar cadenas de caracteres ****************/
/* ordcads.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX  25    // n�mero m�ximo de cadenas 
#define CMAX  81    // n�mero m�ximo de caracteres por cadena 

int  LeerCadena(char cad[][CMAX], char *pcad[], int nmc);
void Ordenar(char *pcad[], int nc);
void Visualizar(char *pcad[], int nc);

main()
{
  char cad[NMAX][CMAX];  // matriz de cadenas 
  char *pcad[NMAX];      // matriz de punteros a las cadenas 
  int  ncads = 0;        // n�mero de cadenas le�das 

  printf("Ordenaci�n de cadenas de caracteres.\n");
  printf("Introduzca las cadenas a ordenar.\n");
  printf("Pulse <Entrar> para salir.\n");
  if ((ncads = LeerCadena(cad, pcad, NMAX)) > 0)
  {
    printf("Cadenas le�das %d\n\n", ncads);
    printf("Proceso de ordenaci�n.\n\n");
    Ordenar(pcad, ncads);
    Visualizar(pcad, ncads);
  }
  else
    printf("Matriz vac�a\n");
}

/***************************************************************
                   Funci�n leer cadenas
***************************************************************/

int LeerCadena(char cad[][CMAX], char *pcad[], int nmc)
{
  // nmc = n�mero m�ximo de cadenas que se pueden leer 
  int longitud = 0, ncads = 0;
  if (nmc < 1) return -1; // error

  while ((longitud = strlen(gets(cad[ncads]))) > 0)
  {
    // guardar la direcci�n de comienzo de la cadena le�da en
    // en el siguiente elemento de la matriz de punteros
    pcad[ncads++] = cad[ncads];
    if (ncads == nmc) break; // matriz llena
  }

  return (ncads);  // n�mero de cadenas le�das 
}

/***************************************************************
                   Funci�n ordenar cadenas
***************************************************************/

void Ordenar(char *pcad[], int nc)
{
  char *aux = NULL;  // puntero auxiliar 
  int i = 0, s = 1;

  while ((s == 1) && (--nc > 0))
  {
    s = 0;  // no permutaci�n 
    for (i = 1; i <= nc; i++)
      if (strcmp(pcad[i-1], pcad[i]) > 0)
      {
        aux = pcad[i-1];
        pcad[i-1] = pcad[i];
        pcad[i] = aux;
        s = 1;  // permutaci�n 
      }
  }
}

/***************************************************************
                   Funci�n visualizar cadenas
***************************************************************/

void Visualizar(char *pcad[], int nc)
{
  // nc = n�mero de cadenas a visualizar 
  while (--nc >= 0)
    printf("%s\n", *pcad++);
}
