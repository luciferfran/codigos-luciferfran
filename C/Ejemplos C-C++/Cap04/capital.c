/********************* Capital e Intereses *********************/
/* capital.c
 */
#include <stdio.h>
#include <stdlib.h>

main()
{
  double c, intereses, capital;
  float r;
  int t;

  system("cls"); /* limpiar pantalla */

  /* Entrada de datos */
  printf("Capital invertido        ");
  scanf("%lf", &c);
  printf("\nA un %% anual del         ");
  scanf("%f", &r);
  printf("\nDurante cu�ntos d�as     ");
  scanf("%d", &t);
  printf("\n\n");

  /* C�lculos */
  intereses = c * r * t / (360L * 100);
  capital = c + intereses;

  /* Escribir resultados */
  printf("Intereses producidos...%10.0f\n", intereses);
  printf("Capital acumulado......%10.0f\n", capital);
}
