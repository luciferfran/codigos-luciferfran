/* referen.c - Paso de par�metros por referencia */
#include <stdio.h>

void intercambio(int *, int *); /* prototipo de la funci�n */

main()
{
  int a = 20, b = 30;
  intercambio(&a, &b); /* a y b son pasados por referencia */
  printf("a es %d y b es %d\n", a, b);
}

void intercambio(int *x, int *y)
{
  int z = *x; /* z = contenido de la direcci�n x */
  *x = *y;    /* contenido de x = contenido de y */
  *y = z;     /* contenido de y = z */
}
