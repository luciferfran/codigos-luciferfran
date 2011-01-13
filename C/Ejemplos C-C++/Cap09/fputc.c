/****** Escribir datos en un fichero carácter a carácter *******/
/* fputc.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  FILE *pf;
  char buffer[81];
  int i = 0;

  // Abrir el fichero "texto" para escribir
  if ((pf = fopen("texto", "w")) == NULL)
  {
    perror("El fichero no se puede abrir");
    exit(1);
  }
  strcpy(buffer, "Este es un texto escrito por fputc!!\n");

  while (!ferror(pf) && buffer[i])
    fputc(buffer[i++], pf);

  if (ferror(pf))
    perror("Error durante la escritura");

  fclose(pf);
}
