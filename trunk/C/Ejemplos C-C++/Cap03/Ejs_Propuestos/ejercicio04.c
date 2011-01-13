/* Paso de grados Centígrados a Fahrenheit (F=9/5*C+32)
 *
 * ejercicio04.c
 */
#include <stdio.h>

#define INF -50    /* límite inferior del intervalo de ºC */
#define SUP 50    /* límite superior */

float convertir(int c);

main()
{
  int nGradosCentigrados = 0;
  int incremento = 3;
  float GradosFahrenheit = 0;

  nGradosCentigrados = INF;
  while (nGradosCentigrados <= SUP)
  {
    GradosFahrenheit = convertir(nGradosCentigrados);
    printf("%10d C %10.2f F\n", nGradosCentigrados, GradosFahrenheit);
    nGradosCentigrados += incremento;
  }
}

float convertir(int gcent)
{
  float gfahr;

  gfahr = (float)9 / (float)5 * gcent + 32;
  return (gfahr);
}
