/* getchar.c
 */
#include <stdio.h>
#define LONG_CAD 41

main()
{
  unsigned char cadena[LONG_CAD]; // matriz de LONG_CAD caracteres
  int i = 0, car;

  printf("Introducir un texto: ");
  while ((car = getchar()) != '\n' && i < LONG_CAD-1)
  {
    cadena[i] = car;
    i++;
  }
  // Finalizar la cadena con 0
  cadena[i] = 0;

  printf("Texto introducido:  %s\n", cadena);
  printf("Longitud del texto: %d\n", i);
}
