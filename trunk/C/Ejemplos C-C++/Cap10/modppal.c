/****************************************************************
                         M�DULO PRINCIPAL
****************************************************************/
/* modppal.c
 *
 * Las dos l�neas siguientes incluyen los ficheros especificados
 */
#include "declara2.h"
#include "declara1.h"
#include <stdio.h>

main()    /* FUNCI�N PRINCIPAL */
{
  char mensaje[25];
  TipoReg registro;

  registro = LeerRegistro();
  Verificar(registro, mensaje);
  putchar('\n');
  puts(mensaje);
}
 
