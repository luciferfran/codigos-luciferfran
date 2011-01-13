/******************* Copiar una matriz en otra *******************/
/* memxxx.c
 */
#include <stdio.h>
#include <string.h>

#define FILAS 3
#define COLS 3

main()
{
  float a[FILAS][COLS], c[FILAS][COLS];
  int fila = 0, col = 0;

  // Poner las matrices a y b a cero
  memset(a, 0, sizeof(a));
  memset(c, 0, sizeof(c));

  // Leer datos para la matriz a
  for (fila = 0; fila < FILAS; fila++)
  {
    for (col = 0; col < COLS; col++)
    {
      printf("a[%d][%d] = ", fila, col);
      scanf("%f", &a[fila][col]);
    }
  }

  // Copiar la matriz a en c
  memcpy(c, a, sizeof(a));

  if ( memcmp(a, c, sizeof(a)) == 0 )
    printf("Las matrices a y c contienen los mismos datos\n");
  else
    printf("Las matrices a y c no contienen los mismos datos\n");

  // Escribir los datos de la matriz c
  for (fila = 0; fila < FILAS; fila++)
  {
    // Escribir una fila
    for (col = 0; col < COLS; col++)
      printf("%10g", c[fila][col]);
    printf("\n"); // fila siguiente
  }
}
