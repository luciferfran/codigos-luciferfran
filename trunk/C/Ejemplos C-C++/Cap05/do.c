/****** Raíz cuadrada de un número. Método de Newton ******/
/* do.c
 */
#include <stdio.h>
#include <math.h>

main()
{
  double n;        // número
  double aprox;    // aproximación a la raíz cuadrada
  double antaprox; // anterior aproximación a la raíz cuadrada
  double epsilon;  // coeficiente de error

  do
  {
    printf("Número: ");
    scanf("%lf", &n);
  }
  while ( n < 0 );

  do
  {
    printf("Raíz cuadrada aproximada: ");
    scanf("%lf", &aprox);
  }
  while ( aprox <= 0 );

  do
  {
    printf("Coeficiente de error: ");
    scanf("%lf", &epsilon);
  }
  while ( epsilon <= 0 );

  do
  {
    antaprox = aprox;
    aprox = (n/antaprox + antaprox) / 2;
  }
  while (fabs(aprox - antaprox) >= epsilon);

  printf("La raíz cuadrada de %.2lf es %.2lf\n", n, aprox);
}
