/* Evalúa el polinomio: 3x^5 - 5x^3 + 2x - 7
 *
 * Cap4 - ejercicio4.c
 */

#include <stdio.h>
                 
main()
{                 
  float x, p;                                                           
  printf("Introduzca el valor de 'x' para obtener el resultado de:\n"
         "\t 3x^5 - 5x^3 + 2x - 7\n");
  printf("\nValor de x = ");
  scanf("%f", &x); 
  p = 3*x*x*x*x*x - 5*x*x*x + 2*x - 7;
  printf("\nPara x = %g,  3x^5 - 5x^3 + 2x - 7 = %g\n", x, p);     
}
