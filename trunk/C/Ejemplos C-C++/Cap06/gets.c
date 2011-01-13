/* gets.c
 */
#include <stdio.h>

main()
{
  char *c = NULL; // para almacenar el valor retornado por gets
  char texto[80];

  printf("Introducir líneas de texto.\n");
  printf("Para finalizar introducir la marca EOF\n\n");
  // Leer la primera línea de texto
  c = gets(texto);
  while (c != NULL)
  {
    // Operaciones con la línea de texto leída
    // ...
    // Leer otra línea de texto
    c = gets(texto);
  }
}
