/***************************************************************
                      Fichero fuente uno.c
***************************************************************/
#include <stdio.h>

void funcion_1();
void funcion_2();

extern int var; /* declaración de var que hace referencia a la
                   variable var definida a continuación */
main()
{
  var++;
  printf("%d\n", var); /* se escribe 6 */
  funcion_1();
}

int var = 5; /* definición de var */

void funcion_1()
{
  var++;
  printf("%d\n", var); /* se escribe 7 */
  funcion_2();
}
