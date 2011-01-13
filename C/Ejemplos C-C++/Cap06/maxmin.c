/************* Valor máximo y mínimo de una lista *************/
/* maxmin.c
 */
#include <stdio.h>
#define NMAX 100 // máximo número de elementos de la matriz

main()
{
  float dato[NMAX];   // matriz de datos
  float max, min;     // valor máximo y valor mínimo
  int nElementos = 0; // número de elementos de la matriz leídos
  int i = 0;          // índice

  // Entrada de datos
  printf("Introducir datos. Para finalizar introducir la marca EOF\n");
  printf("dato[%d] = ", i);
  while (i < NMAX && scanf("%f", &dato[i]) != EOF)
  {
    i++;
    printf("dato[%d] = ", i);
  }

  // Encontrar los valores máximo y mínimo
  nElementos = i;
  if (nElementos > 0)
  {
    max = min = dato[0];
    for (i = 0; i < nElementos; i++)
    {
      if (dato[i] > max)
	      max = dato[i];
      if (dato[i] < min)
	      min = dato[i];
    }
    // Escribir resultados
    printf("Valor máximo: %g, valor mínimo: %g\n", max, min);
  }
  else
    printf("No hay datos.\n");
}
