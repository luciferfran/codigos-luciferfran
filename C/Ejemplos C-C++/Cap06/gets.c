/* gets.c
 */
#include <stdio.h>

main()
{
  char *c = NULL; // para almacenar el valor retornado por gets
  char texto[80];

  printf("Introducir l�neas de texto.\n");
  printf("Para finalizar introducir la marca EOF\n\n");
  // Leer la primera l�nea de texto
  c = gets(texto);
  while (c != NULL)
  {
    // Operaciones con la l�nea de texto le�da
    // ...
    // Leer otra l�nea de texto
    c = gets(texto);
  }
}
