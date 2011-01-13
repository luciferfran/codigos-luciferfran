/* operadores.c
 */
#include <stdio.h>

main()
{
  float x = 0, a = 20, b = 10, d = 4;

  x = (a - b);
  --b;
  x *= (b - d) * b / (b - d);
  b++;
  b++;
  printf("x = %g, b = %g\n", x, b);
}

