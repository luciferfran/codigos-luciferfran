// ejercicio02.c
//
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int);

int main()
{
  int n = 0, i = 0, *f;

  printf("¿Cuántos números de Fibonacci, a partir del ");
  printf("primero, se quieren calcular?\n");
  do
  {
    printf("n = ");
    i = scanf("%d", &n);
    fflush(stdin);
  }
  while ( i == 0 || n < 1);

  // Crear una matriz dinámicamente
  f = (int *)malloc(n * sizeof(int));
  if (f == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }

  // Obtener los números de la serie
  for (i = 0; i < n; i++)
    f[i] = fibonacci(i);

  // Visualizar la matriz
  for (i = 0; i < n; i++)
    printf("%5d", f[i]);
  printf("\n");

  // Liberar la memoria asignada a la matriz
  free(f);

  return 0;
}

int fibonacci(int n)
{
  if ( n == 0 )
    return 0;
  else if ( n == 1 )
    return 1;
  else
  {
    int n1 = 0, n2 = 0, n3 = 1, i;
    for (i = 2; i <= n; i++)
    {
      n1 = n2; n2 = n3; 
      n3 = n2 + n1;
    }
    return n3;
  }
}
