/******* Escribir y leer datos con formato en un fichero *******/
/* fprintf.c
 */
#include <stdio.h>
#include <stdlib.h>

main()
{
  char buffer[128];
  FILE *ptabla = NULL;
  long entl = 0, total_entl = 0;
  float real = 0.0F, total_real = 0.0F;
  int i = 0, c = 'A';

  // Abrir un fichero para leer. Si no existe lo creamos
  if ((ptabla = fopen("tabla.d", "r")) != NULL)
  {
    // Leer datos del fichero y totalizarlos
    printf("RESULTADOS:\n\n");
    for (i = 0, total_entl = 0, total_real = 0.0F; i < 10; i++)
    {
      fscanf(ptabla, "%s %c: %ld %f", buffer, &c, &entl, &real);
      total_entl += entl;
      total_real += real;
      printf("\t%s %c: %7ld %9.2f\n", buffer, c, entl, real);
    }
    printf("\n\tTotal:   %7ld %9.2f\n", total_entl, total_real);
  }
  else
  {
    // Si el fichero no existe lo creamos
    if ((ptabla = fopen( "tabla.d", "w" )) == NULL)
      exit(1);

    // Se escribe la tabla deseada en el fichero
    for (i = 0, entl = 99999, real = 3.14F; i < 10; i++)
      fprintf(ptabla, "\tLínea %c: %7ld %9.2f\n",
		             c++, entl /= 2, real *= 2);
    printf("El fichero no existía y lo hemos creado.\n");
    printf("\nEjecute de nuevo el programa.\n");
  }
  fclose(ptabla);
}
