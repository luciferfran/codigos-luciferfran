/***************** Medir tiempos de ejecución *****************/
/* tiempo.c
 */
#include "tiempo.h"

main()
{
  register unsigned long i;
  float k;

  T_INICIAL(lazo con variable register unsigned long);
    for (i = 0; i < 10000000; i++);
  T_FINAL;

  T_INICIAL(lazo con variable float);
    for (k = 0; k < 10000000; k++);
  T_FINAL;
}
