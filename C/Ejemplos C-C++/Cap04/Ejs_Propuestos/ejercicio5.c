/* Evalúa el polinomio: ax^5 - bx^3 + cx - 7
 *
 * Cap4 - ejercicio5.c
 */

#include <stdio.h>
                 
main()
{                 
  double a = 0, b = 0, c = 0, x = 0, p = 0;
  // Se inicializan los valores a 0 (opcional)
                                                          
  printf("Introduzca los coeficientes y el valor de x para obtener el resultado de:\n"
         "\tax^5 - bx^3 + cx - 7\n\n");
  printf("a = ");
  scanf("%lf", &a);    // Si se escriben todos los datos secuencialmente, 
  printf("b = ");      // también los acepta
  scanf("%lf", &b);    // Si no se quisiera esto, poner 'fflush(stdin);'
  printf("c = ");      // detrás de cada 'scanf()'
  scanf("%lf", &c); 
  printf("x = ");
  scanf("%lf", &x); 
  p = a*x*x*x*x*x - b*x*x*x + c*x - 7;
  printf("\nPara x = %g,  %gx^5 - %gx^3 + %gx - 7 = %g\n", x, a, b, c, p);     
}
