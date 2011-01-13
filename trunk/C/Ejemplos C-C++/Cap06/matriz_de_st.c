/********** Calcular el % de aprobados y suspendidos **********/
/* matriz_de_st.c
 */
#include <stdio.h>
#define NA 100      // número máximo de alumnos

typedef struct
{
  char nombre[60];
  float nota;
} tficha;

main()
{
  static tficha alumno[NA]; // matriz de estructuras o registros
  int n = 0, i = 0;
  char *fin = NULL; // para almacenar el valor devuelto por gets
  int aprobados = 0, suspendidos = 0;

  // Entrada de datos
  printf("Introducir datos. ");
  printf("Para finalizar teclear la marca de fin de fichero\n\n");

  printf("Nombre: ");
  fin = gets(alumno[n].nombre);
  while (n < NA && fin != NULL)
  {
    printf("Nota:   ");
    scanf("%f", &alumno[n++].nota);
    fflush(stdin); // eliminar el carácter \n
    // Siguiente alumno
    printf("Nombre: ");
    fin = gets(alumno[n].nombre);
  }

  // Contar los aprobados y suspendidos
  for (i = 0; i < n; i++)
    if (alumno[i].nota >= 5)
      aprobados++;
    else
      suspendidos++;

  // Escribir resultados
  printf("Aprobados:   %.4g %%\n", (float)aprobados/n*100);
  printf("Suspendidos: %.4g %%\n", (float)suspendidos/n*100);
}
