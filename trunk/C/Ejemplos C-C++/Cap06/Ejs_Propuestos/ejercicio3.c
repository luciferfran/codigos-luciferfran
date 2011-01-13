/* Rotación de caracteres
 *
 * Cap6\ejercicio3.c
 */

#include <stdio.h>
#include <string.h>

main()
{                         
  int n_car = 0, n_caracteres = 0; // número de caracteres
  char car, frase[50], stemp[50];  // 50 caracteres como máximo
  printf("Introduzca una frase:\n");
  gets(frase);
  strcpy(stemp, frase);
  n_caracteres = strlen(frase);
  printf("%s", frase);
  do
  { // Repite el bucle mientras la cadena no vuelva a ser la original
    car = frase[n_caracteres - 1];
    for (n_car = n_caracteres - 2; n_car >= 0; n_car--)
    {
      frase[n_car + 1] = frase[n_car];
    }
    frase[0] = car;
    printf("-%s", frase);           
  }               
  while( strcmp(frase, stemp) );               
  printf("\n");
}
