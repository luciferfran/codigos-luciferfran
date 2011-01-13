/* Evaluar el binomio (ax + by)^n
 * ejercicio07.c
 */

#include <stdio.h>
#include <stdlib.h>
                       
long factorial(int n);
long combinaciones(int n, int k);
double potencia(double base, int exponente);

main()
{
  // Valores predeterminados
  double a = 1, b = 1, m = 1, x = 1, y = 1, result = 0;
  int n = 1, k = 0;

  printf("Binomio (ax + by)^n:\n");
  printf("a = "); scanf("%lf", &a);
  printf("b = "); scanf("%lf", &b);
  printf("n = "); scanf("%lf", &m);
  n = (int)m; // asegurar qye se trata de un entero
  printf("x = "); scanf("%lf", &x);
  printf("y = "); scanf("%lf", &y);
  printf("Calcular (%g*%g + %g*%g)^%d:\n", a, x, b, y, n);

  for ( k = 0, result = 0; k <= n; k++)
    result += combinaciones(n, k) * potencia(a*x, n-k) * potencia (b*y, k);
  printf("Resultado: %g.\n", result);   
    
}

long factorial(int n)
{
  // Función no recursiva:
  long res;

  if (n < 0)
  {
    printf("error: número negativo\n");
    exit(-1);
  }
  if(n == 0) return 1;  // 0! == 1
  res = n;
  while (--n > 1) res *= n ;
  return res;
}

long combinaciones( int n, int k)
{
  return ( factorial(n) / (factorial (k) * factorial(n - k)) );
}

double potencia(double base, int exponente)
{
  double b;

  if (exponente == 0) 
    return 1;
  for (b = base; exponente > 1; exponente--)
    b *= base;
  return b;
}
