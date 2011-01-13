/****** Contar caracteres, palabras y l�neas en un texto ******/
/* palabras.c
 */
#include <stdio.h>

main()   // funci�n principal
{
  const int SI = 1;
  const int NO = 0;

  char car;
  int palabra = NO;
  int ncaracteres = 0, npalabras = 0, nlineas = 0;

  printf("Introducir texto. ");
  printf("Pulse Entrar despu�s de cada l�nea.\n");
  printf("Para finalizar introducir la marca EOF.\n\n");
  while ((car = getchar()) != EOF)
  {
    ++ncaracteres;          // contador de caracteres
    // Eliminar blancos, tabuladores y finales de l�nea
    // entre palabras
    if (car == ' ' || car == '\n' || car == '\t')
      palabra = NO;
    else if (palabra == NO) // comienza una palabra
    {
      ++npalabras;          // contador de palabras
      palabra = SI;
    }

    if (car == '\n')        // finaliza una l�nea
      ++nlineas;            // contador de l�neas
  }
  printf("%d %d %d\n", ncaracteres, npalabras, nlineas);
}
