/* sizeof.c
 */
#include <stdio.h>

main()
{
  int a = 0, t = 0;
  t = sizeof a;
  printf("El tama�o del entero 'a' es: %d bytes\n", t);
  printf("El tama�o de un entero es: %d bytes\n", sizeof(int));
}

