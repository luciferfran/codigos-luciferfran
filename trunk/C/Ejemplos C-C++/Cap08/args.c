/*************** Argumentos en l�nea de �rdenes ***************/
/* args.c
 */
#include <stdio.h>
#include <string.h>
#define false 0
#define true 1

int main(int argc, char *argv[])
{
  // C�digo com�n a todos los casos
  printf("Argumentos:\n");
  if (argc == 0)
  {
    // Escriba aqu� el c�digo que s�lo se debe ejecutar cuando
    // no se pasan argumentos
    printf("    ninguno\n");
  }
  else
  {
    int argumento_k = false, argumento_l = false,
        argumento_n = false, i = 0;
  
    // �Qu� argumentos se han pasado?
    for (i = 0; i < argc; i++)
    {
      if (strcmp(argv[i], "-k") == 0) argumento_k = true;
      if (strcmp(argv[i], "-l") == 0) argumento_l = true;
      if (strcmp(argv[i], "-n") == 0) argumento_n = true;
    }

    if (argumento_k) // si se pas� el argumento -k:
    {
      // Escriba aqu� el c�digo que s�lo se debe ejecutar cuando
      // se pasa el argumento -k
      printf("    -k\n");
    }

    if (argumento_l) // si se pas� el argumento -l:
    {
      // Escriba aqu� el c�digo que s�lo se debe ejecutar cuando
      // se pasa el argumento -l
      printf("    -l\n");
    }

    if (argumento_n) // si se pas� el argumento -n:
    {
      // Escriba aqu� el c�digo que s�lo se debe ejecutar cuando
      // se pasa el argumento -n
      printf("    -n\n");
    }
  }
  // C�digo com�n a todos los casos
  return 0;
}
