/****** Calcular las raíces de una ecuación de 2º grado ******/
/* ecu2gra.c
 */
#include <stdio.h>
#include <math.h>

main()
{
  double a, b, c;  // coeficientes de la ecuación
  double d;        // discriminante
  double re, im;   // parte real e imaginaria de la raíz

  printf("Coeficientes a, b y c de la ecuación: ");
  scanf("%lf %lf %lf", &a, &b, &c);
  printf("\n");

  if (a == 0 && b == 0)
    printf("La ecuación es degenerada\n");
  else if (a == 0)
    printf("La única raíz es: %.2lf\n", -c / b);
  else
  {
    re = -b / (2 * a);
    d = b * b - 4 * a * c;
    im = sqrt(fabs(d)) / (2 * a);
    if (d >= 0)
    {
      printf("Raíces reales:\n");
      printf("%.2lf    %.2lf\n", re + im, re - im);
    }
    else
    {
      printf("Raíces complejas:\n");
      printf("%.2lf + %.2lf j\n", re, fabs(im));
      printf("%.2lf - %.2lf j\n", re, fabs(im));
    }
  }
}
