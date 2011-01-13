/* puts.c
 */
#include <stdio.h>

main()
{
  char *c = NULL; // para almacenar el valor retornado por gets
  char texto[80];

  printf("Introducir una línea de texto:\n");
  c = gets(texto);
  printf("\nEl texto introducido es:\n");
  puts(texto);    // equivalente a: printf("%s\n", texto);
  puts("\nSe escribe por segunda vez:");
  puts(c);
}
