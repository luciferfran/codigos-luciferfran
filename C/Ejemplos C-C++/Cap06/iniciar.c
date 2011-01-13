/* iniciar.c
 */
#include <stdio.h>
void VisualizarMatriz(int [], int);

main()
{
  int x[] = { 10, 20, 30, 40, 50 };
  VisualizarMatriz(x, 5);
}

void VisualizarMatriz(int m[], int n)
{
  int i = 0;
  for (i = 0; i < n; i++)
    printf("%d ", m[i]);
}
