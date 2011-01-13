/* acos.c
 */
#include <stdio.h>
#include <math.h>

main()
{
  double valor = 0;
  do
  {
    printf("%lf %lf\n", acos(valor), atan2(valor, 1.0));
    valor += 0.1;
  }
  while (valor <= 1.0);
}
