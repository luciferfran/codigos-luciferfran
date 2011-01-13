/*************** Macros y funciones ***************/
/* macros.c
 */
#include <stdio.h>

#define MENOR(x, y) ((x) < (y)) ? (x) : (y)

int menor(int x, int y)
{
  return ((x < y) ? x : y );
}

main()
{
  int m = 0, a = 10, b = 20;
  
  // Utilizando la macro
  m = MENOR(a--, b--); // efecto colateral: el valor menor
                       // se decrementa dos veces
                       
  printf("menor = %d, a = %d y b = %d\n", m, a, b);
  
  // Llamando a la función
  a = 10, b = 20;
  m = menor(a--, b--);
  printf("menor = %d, a = %d y b = %d\n", m, a, b);
}
