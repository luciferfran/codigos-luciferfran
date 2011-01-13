/************* Valor m�ximo y m�nimo de una lista *************/
/* maxmin.c
 */
#include <stdio.h>
#define NMAX 100 // m�ximo n�mero de elementos de la matriz

main()
{
  float dato[NMAX];   // matriz de datos
  float max, min;     // valor m�ximo y valor m�nimo
  int nElementos = 0; // n�mero de elementos de la matriz le�dos
  int i = 0;          // �ndice

  // Entrada de datos
  printf("Introducir datos. Para finalizar introducir la marca EOF\n");
  printf("dato[%d] = ", i);
  while (i < NMAX && scanf("%f", &dato[i]) != EOF)
  {
    i++;
    printf("dato[%d] = ", i);
  }

  // Encontrar los valores m�ximo y m�nimo
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
    printf("Valor m�ximo: %g, valor m�nimo: %g\n", max, min);
  }
  else
    printf("No hay datos.\n");
}
