/****** Ra�z cuadrada de un n�mero. M�todo de Newton ******/
/* do.c
 */
#include <stdio.h>
#include <math.h>

main()
{
  double n;        // n�mero
  double aprox;    // aproximaci�n a la ra�z cuadrada
  double antaprox; // anterior aproximaci�n a la ra�z cuadrada
  double epsilon;  // coeficiente de error

  do
  {
    printf("N�mero: ");
    scanf("%lf", &n);
  }
  while ( n < 0 );

  do
  {
    printf("Ra�z cuadrada aproximada: ");
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

  printf("La ra�z cuadrada de %.2lf es %.2lf\n", n, aprox);
}
