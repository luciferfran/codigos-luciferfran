/* C�digo ASCII de cada uno de los caracteres de un texto
 * while04.c
 */
#include <stdio.h>
 
main() 
{ 
  char car = 0; // car = car�cter nulo (\0)

  printf("Introduzca una cadena de texto.\n"); 
  printf("Para terminar pulse Ctrl+z\n"); 
  while ((car = getchar()) != EOF)
  {
    if (car != '\n')
      printf("El c�digo ASCII de %c es %d\n", car, car);
  }
} 
