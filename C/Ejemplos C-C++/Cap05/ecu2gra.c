/****** Calcular las ra�ces de una ecuaci�n de 2� grado ******/
/* ecu2gra.c
 */
#include <stdio.h>
#include <math.h>

main()
{
  double a, b, c;  // coeficientes de la ecuaci�n
  double d;        // discriminante
  double re, im;   // parte real e imaginaria de la ra�z

  printf("Coeficientes a, b y c de la ecuaci�n: ");
  scanf("%lf %lf %lf", &a, &b, &c);
  printf("\n");

  if (a == 0 && b == 0)
    printf("La ecuaci�n es degenerada\n");
  else if (a == 0)
    printf("La �nica ra�z es: %.2lf\n", -c / b);
  else
  {
    re = -b / (2 * a);
    d = b * b - 4 * a * c;
    im = sqrt(fabs(d)) / (2 * a);
    if (d >= 0)
    {
      printf("Ra�ces reales:\n");
      printf("%.2lf    %.2lf\n", re + im, re - im);
    }
    else
    {
      printf("Ra�ces complejas:\n");
      printf("%.2lf + %.2lf j\n", re, fabs(im));
      printf("%.2lf - %.2lf j\n", re, fabs(im));
    }
  }
}
