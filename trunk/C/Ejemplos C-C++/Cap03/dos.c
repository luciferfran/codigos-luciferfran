/***************************************************************
                      Fichero fuente dos.c
***************************************************************/
#include <stdio.h>

extern int var; /* declaración de var. Referencia a la variable var
                   definida en el fichero uno.c */
void funcion_2()
{
  var++;
  printf("%d\n", var); /* se escribe 8 */
}

