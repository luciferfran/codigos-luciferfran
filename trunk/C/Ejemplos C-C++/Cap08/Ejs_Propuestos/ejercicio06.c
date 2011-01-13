/* Matriz dinámica de dos dimensiones
 * ejercicio06.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                      
                       
void Leer(float **m, int fi, int co);
float **AsigMem(int fi, int co);

main()
{       
	int fi = 3, co = 3; // valores predeterminados
  int i = 0, j = 0;      
	float **m = NULL;

	printf("Número de filas y de columnas de la matriz: ");
	scanf("%d %d", &fi, &co);
	m = AsigMem( fi, co);

	printf("Elementos de la matriz\n");
	Leer(m, fi, co);

  printf("La matriz leída es:\n");
	for (i = 0; i < fi; i++)
	{
		for (j = 0; j < co; j++)
		 	printf("%8g", m[i][j]);
		printf("\n"); 
	}

  // Liberar la memoria
  for ( i = 0; i < fi; i++ )
    free(m[i]);;
	free(m);
}

void Leer(float **m, int fi, int co)
{
  int i, j;
	for (i = 0; i < fi; i++)
		for (j = 0; j < co; j++)
		{
		 	printf("elemento [%d][%d] = ", i, j);
		 	scanf("%f", &m[i][j]);
		}
}

float **AsigMem(int fi, int co)
{
	float **m;
  int f = 0, c = 0;
  // Asignar memoria para la matriz de punteros
  if ((m = (float **)malloc(fi * sizeof(float *))) == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    exit(-1);
  }

  // Asignar memoria para cada una de las filas
  for (f = 0; f < fi; f++)
  {
    if ((m[f] = (float *)malloc(co * sizeof(float))) == NULL)
    {
      printf("Insuficiente espacio de memoria\n");
      exit(-1);
    }
  }

  // Iniciar la matriz a cero
  for ( f = 0; f < fi; f++ )
    memset(m[f], 0, co * sizeof(int));

  return m;
}
