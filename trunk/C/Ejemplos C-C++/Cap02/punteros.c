/* punteros.c
 */
#include <stdio.h>

main()
{
  int *px, x = 7, y = 0; // px es un puntero a un valor entero.
  px = &x;               // en el puntero px se almacena la
                         // direcci�n del entero x.
  y = *px;               // en y se almacena el valor localizado
                         // en la direcci�n almacenada en px.
  printf("direcci�n de memoria = %d, dato = %d\n", &x, x);
  printf("direcci�n de memoria = %d, dato = %d\n", px, *px);
}

