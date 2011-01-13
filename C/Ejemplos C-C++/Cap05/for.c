/********************* Tablero de ajedrez *********************/
/* for.c
 */
#include <stdio.h>

main()
{
  int falfil, calfil;  // posición del alfil
  int fila, columna;   // posición actual

  printf("Posición del alfil (fila, columna): ");
  scanf("%d %d", &falfil, &calfil);
  printf("\n");  // dejar una línea en blanco

  // Pintar el tablero de ajedrez
  for (fila = 1; fila <= 8; fila++)
  {
    for (columna = 1; columna <= 8; columna++)
    {
      if ((fila + columna == falfil + calfil) ||
	       (fila - columna == falfil - calfil))
	      printf("* ");
      else if ((fila + columna) % 2 == 0)
	      printf("B ");
      else
	      printf("N ");
    }
    printf("\n");  // cambiar de fila
  }
}
