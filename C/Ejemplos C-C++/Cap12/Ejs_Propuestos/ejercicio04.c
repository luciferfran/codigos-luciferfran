/* Clasificación por inserción y búsqueda binaria
 *
 * ejercicio04.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
typedef struct 
{
  char nombre[40];
  unsigned int matricula;
  unsigned int nota;
} registro;                  

void Insercion(registro Fichas[], int cont);
int BusqBin(registro Fichas[], int cont, int unsigned matricula);

main(void)
{                             
  int cont = 0, i = 0;
  unsigned int matricula;
  registro Fichas[100];

  // Petición de datos:
  printf("Introducir datos para crear la lista.\n");
  printf("Puede finalizar con nombre igual a eof:\n");
  for (cont = 0; cont < 100; cont++)
  {
    fflush(stdin);
    printf("\nNombre = ");
    if (gets(Fichas[cont].nombre) == NULL) break;
    printf("Matrícula = ");
    if(scanf("%u", &Fichas[cont].matricula) != 1) break;
    printf("Nota = ");
    if(scanf("%u", &Fichas[cont].nota) != 1) break;
  }
  
  Insercion(Fichas, cont);

  for (i = 0; i < cont; i++)
    printf("Matrícula: %u\nNota: %u\n", Fichas[i].matricula, Fichas[i].nota);
  
  printf("\nEscriba un número de matrícula:\n");
  while(scanf("%u", &matricula) == 1)
  {
    i = BusqBin(Fichas, cont, matricula);
    if (i != -1)
      printf("Nombre: %s\nNota: %u\n", Fichas[i].nombre, Fichas[i].nota);
    else
      printf("No encontrado\n");
    printf("\nEscriba un número de matrícula:\n");
  }
}

void Insercion(registro lista[100], int n_elementos)
{
  registro x;
  int i, k;
  
  for(i = 1; i < n_elementos; i++)
  {
    x = lista[i];
    k = i - 1;
    while (k >= 0 && x.matricula < lista[k].matricula)
    {
      lista[k+1] = lista[k];
      k--;
    } 
    lista[k+1] = x;
  }
}

int BusqBin(registro Fichas[100], int max, unsigned int matricula)
{
  int med, min = 0;
  while(1)
  {
    med = (max + min) / 2;
    if(max == min && Fichas[med].matricula != matricula)
      return -1;
    if (Fichas[med].matricula < matricula)
    {
      min = med + 1;
      continue;
    }
    else if (Fichas[med].matricula > matricula)
    {
      max = med;
      continue;
    }
    else // Son iguales
      return med;
  }                 
}