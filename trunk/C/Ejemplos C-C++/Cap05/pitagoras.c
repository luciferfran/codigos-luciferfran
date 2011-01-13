/* Teorema de Pitágoras.
 * pitagoras.c
 */
#include <stdio.h>
#include <math.h>

void main()
{
  unsigned int x = 1, y = 1, z = 0;

  printf("%10s %10s %10s\n", "Z", "X", "Y");
  printf("      ___________________________\n");

  while (x <= 50)
  {
    /* Calcular z. Como z es un entero, almacena
       la parte entera de la raíz cuadrada */
    z = (int)sqrt(x * x + y * y);
    while (y <= 50 && z <= 50)
    {
      /* Si la raíz cuadrada anterior fue exacta,
         escribir z, x e y */
      if (z * z == x * x + y * y)
	      printf("%10d %10d %10d\n", z, x, y);
      y = y + 1;
      z = (int)sqrt(x * x + y * y);
    }
    x = x + 1; y = x;
  }
}
