/******* Números seudoaleatorios - Volumen de una esfera *******/
/* esfera.c
 */
#include <stdio.h>
#include <time.h>

double rnd(long *);
int DentroEsfera(const int);

main()
{
  const int TOTAL = 1000; // ensayos a realizar
  double Volumen_esfera;  // volumen de la esfera
  int dentro;             // número de puntos dentro de la esfera

  printf("Ensayos a realizar:  %d\n", TOTAL);
  dentro = DentroEsfera(TOTAL);
  // Es necesario poner 8.0 para que el resultado sea real
  Volumen_esfera =  8.0 * dentro / TOTAL;
  printf("\nVolumen estimado = %g\n", Volumen_esfera);
}

int DentroEsfera(const int total)
{
  // Calcular cuántos del total de puntos generados
  // están dentro de la esfera
  long random = time(NULL);
  int i, dentro = 0;
  double x, y, z;

  for (i = 1; i <= total; i++)
  {
    printf("Realizando cálculos... %d\r", i);
    x = rnd(&random); y = rnd(&random); z = rnd(&random);
    if (x*x + y*y + z*z <= 1)
      dentro = dentro + 1;
  }

  return dentro;
}

double rnd(long *prandom)
{
  // Generador de números seudoaleatorios
  *prandom = (25173 * *prandom + 13849) % 65536;
  return (double)*prandom / 65535;
}
