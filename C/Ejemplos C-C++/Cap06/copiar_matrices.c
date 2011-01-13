/******************* Copiar matrices *******************/
/* copiar_matrices.c
 */
#include <stdio.h>

#define FILAS 3
#define COLS 3

void CopiarArray( float destino[][COLS], float origen[][COLS] );

main()
{
  static float a[FILAS][COLS], c[FILAS][COLS];
  int fila = 0, col = 0;
  
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
  CopiarArray(c, a);

  // Escribir los datos de la matriz c
  for (fila = 0; fila < FILAS; fila++)
  {
    // Escribir una fila
    for (col = 0; col < COLS; col++)
      printf("%10g", c[fila][col]);
    printf("\n"); // fila siguiente
  }
}

void CopiarArray( float destino[][COLS], float origen[][COLS] )
{
  int fila = 0, col = 0;
  for (fila = 0; fila < FILAS; fila++)
  {
    for (col = 0; col < COLS; col++)
      destino[fila][col] = origen[fila][col];
  }
}
