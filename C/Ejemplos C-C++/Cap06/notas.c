/******************** Nota media del curso ********************/
/* notas.c
 */
#include <stdio.h>

#define N_ALUMNOS 100  // número máximo de alumnos

main()
{
  float notas[N_ALUMNOS]; // matriz notas
  int i = 0;              // índice
  int nalumnos = 0;       // número real de alumnos
  float suma = 0;         // suma total de todas las notas medias

  do
  {
    printf("Número de alumnos: ");
    scanf("%d", &nalumnos);
  }
  while (nalumnos < 1 || nalumnos > N_ALUMNOS);

  // Entrada de datos
  for (i = 0; i < nalumnos; i++)
  {
    printf("Alumno número %3d, nota media: ", i+1);
    scanf("%f", &notas[i]);
  }

  // Sumar las notas
  for (i = 0; i < nalumnos; i++)
    suma += notas[i];

  // Escribir resultados
  printf("\n\nNota media del curso: %5.2f\n", suma / nalumnos);
}
