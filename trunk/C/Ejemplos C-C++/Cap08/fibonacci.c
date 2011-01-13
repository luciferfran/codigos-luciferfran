// fibonacci.c
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
    return fibonacci(n-1) + fibonacci(n-2);
}
