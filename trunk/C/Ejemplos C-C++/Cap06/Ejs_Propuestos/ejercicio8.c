/* Resultado del an�lisis
 *
 * Cap6\ejercicio8.c
 */
 
/*
   No, porque los operadores l�gicos para manejo de bits
   s�lo se pueden utilizar con enteros. 
*/

#include <stdio.h>

void presentar( float c );

void main()
{
  float f;
  
  printf("Introduce valor real: ");
  scanf("%f", &f);
  presentar(f);
}

void presentar( float c )
{
  int i = 0;

  for (i = 31; i>=0; i--)
    printf("%d", (c & (1 << i)) ? 1 : 0);
  printf("\n");
}
