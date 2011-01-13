/* valor.c - Paso de parámetros por valor */
#include <stdio.h>

void intercambio(int, int); /* prototipo de la función */

main()
{
  int a = 20, b = 30;
  intercambio(a, b); /* a y b son pasados por valor */
  printf("a vale %d y b vale %d\n", a, b);
}

void intercambio(int x, int y)
{
  int z = x;
  x = y;
  y = z;
}
