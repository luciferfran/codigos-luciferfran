/* C�digo ASCII de cada uno de los caracteres de un texto
 * while03.c
 */
#include <stdio.h>
 
main() 
{ 
  char car = 0; // car = car�cter nulo (\0)

  printf("Introduzca una cadena de texto: "); 
  while (1)
  {
    car = getchar();
    if (car != '\n')
      printf("El c�digo ASCII de %c es %d\n", car, car);
    else
      printf("Introduzca una cadena de texto: ");
  }
} 
