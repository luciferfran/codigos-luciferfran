/* Evaluación de una serie
 *
 * Cap5 - ejercicio3.c
 */

#include <stdio.h>        
#include <stdlib.h>        

main()
{                         
  int a, b = 0;
  float x = 0, y = 0, sum = 0;
  printf("      b\n");  // Se visualiza un sumatorio
  printf("    -----\n");
  printf("    \\        1           Introduzca las variables\n");
  printf("     \\    -------\n");
  printf("     /     x + ay         para evaluar esta serie:\n");
  printf("    /\n");
  printf("    -----\n");
  printf("    a = 0\n");
  
  printf("\n");
  printf("b = ");
  scanf("%d", &b);
  printf("x = ");
  scanf("%f", &x);
  printf("y = ");
  scanf("%f", &y);
    
  for(a = 0; a <= b; a++)
  { // Este bucle recorre todos los valores de a
    if ((x + a*y) == 0)
      printf("*** El denominador de la división ha dado 0 ***"), exit(-1);
    sum += 1 / (x + a*y);
  }
  printf("El resultado es = %g", sum);
}
