/* Función para copiar una cadena en otra.
 * copicad1.c
 */
#include <stdio.h>

void copicad(char *, char *);

main()
{
  char cadena1[81], cadena2[81];

  printf("Introducir una cadena: ");
  gets(cadena1);
  copicad(cadena2, cadena1);    // copia la cadena1 en la cadena2
  printf("La cadena copiada es: %s\n", cadena2);
}

void copicad(char *p, char *q)  // copia la cadena q en p
{ 
  while ((*p = *q) != '\0') 
  {
    p++;
    q++;
  }
}
