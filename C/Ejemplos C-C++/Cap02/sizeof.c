/* sizeof.c
 */
#include <stdio.h>

main()
{
  int a = 0, t = 0;
  t = sizeof a;
  printf("El tamaño del entero 'a' es: %d bytes\n", t);
  printf("El tamaño de un entero es: %d bytes\n", sizeof(int));
}

