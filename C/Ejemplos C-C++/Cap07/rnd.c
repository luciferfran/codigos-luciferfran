/********************* Valores entre 0 y 1 *********************/
/* rnd.c
 */
#include <stdio.h>
#include <time.h>

double rnd(long *prandom);

main()
{
  long inicio = time(NULL) % 65536;  // semilla
  long random = inicio; // random = número entre 0 y 65535
  double n;
  short i;

  for (i = 10; i; i--)
  {
    n = rnd(&random);
    printf("%.8g\n", n);
  }
}

double rnd(long *prandom)
{
  *prandom = (25173 * *prandom + 13849) % 65536;
  return((double)*prandom / 65535);
}
