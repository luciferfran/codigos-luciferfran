/**** Tabla de frecuencias de letras adyacentes en un texto ****/
/* parejas.c
 */
#include <stdio.h>
#include <ctype.h>
#define DIM ('z' - 'a' + 1) // filas/columnas de la tabla

void main()
{
  static int tabla[DIM][DIM]; // tabla de contingencias
  char f, c;                  // �ndices
  char car;                   // car�cter actual
  char carant = ' ';          // car�cter anterior

  printf("Introducir texto. Para finalizar introducir la marca EOF\n");
  while ((car = getchar()) != EOF)
  {
    car = tolower(car); // convertir a min�sculas si procede
    if ((carant >= 'a' && carant <= 'z') && (car >= 'a' && car <= 'z'))
      tabla[carant - 'a'][car - 'a']++;
    carant = car;
  }

  // Escribir la tabla de frecuencias
  printf(" ");
  for (c = 'a'; c <= 'z'; c++)
    printf("  %c", c);
  putchar('\n');
  for (f = 'a'; f <= 'z'; f++)
  {
    putchar(f);
    for (c = 'a'; c <= 'z'; c++)
      printf("%3d", tabla[f - 'a'][c - 'a']);
    putchar('\n');
  }
}
