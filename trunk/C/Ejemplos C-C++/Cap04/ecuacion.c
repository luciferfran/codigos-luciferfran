/********** Soluci�n de una ecuaci�n de segundo grado **********/
/* ecuacion.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
  double a, b, c, d, x1, x2;

  system("cls");

  /* Entrada de datos */
  printf("Introducir los coeficientes a b c: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  /* Comprobar si las ra�ces son reales */
  d = b * b - 4 * a * c;
  (d < 0) ? printf("Las ra�ces son complejas\n"), exit(0)
          : printf("Las ra�ces reales son:\n");

  /* C�lculo de las soluciones */
  d = sqrt(d);
  x1 = (-b + d) / (2 * a);
  x2 = (-b - d) / (2 * a);

  /* Escribir resultados */
  printf("x1 = %g\nx2 = %g\n", x1, x2);
}
