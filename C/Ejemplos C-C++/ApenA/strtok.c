/* strtok.c
 */
#include <stdio.h>
#include <string.h>

main(void)
{
  char cadena[] = "Esta cadena, está formada por varias palabras";
  char *elemento;
  elemento = strtok(cadena," ,");
  while (elemento != NULL)
  {
    printf("%s\n", elemento);
    elemento = strtok(NULL," ,");
  }
}
