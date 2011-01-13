/**** Cantidad a pagar en función de la cantidad comprada ****/
/* else_if.c
 */
#include <stdio.h>
#include <stdlib.h>

main()
{
  int ar, cc; /* código y cantidad */
  float pu;   /* precio unitario */

  printf("Código artículo....... ");
  scanf("%d", &ar);
  printf("Cantidad comprada..... ");
  scanf("%d", &cc);
  printf("Precio unitario....... ");
  scanf("%f", &pu);

  printf("\n\n%10s %10s %10s %10s %10s\n\n",
	     "Artículo", "Cantidad", "P. U.", "Dto.", "Total");

  printf("%10d %10d %10.2f", ar, cc, pu);

  if (cc > 100)
    printf(" %9d%% %10.2f\n", 40, cc * pu * 0.6);
  else if (cc >= 25)
    printf(" %9d%% %10.2f\n", 20, cc * pu * 0.8);
  else if (cc >= 10)
    printf(" %9d%% %10.2f\n", 10, cc * pu * 0.9);
  else
    printf(" %10s %10.2f\n", "--", cc * pu);
}
