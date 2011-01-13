/****************************************************************
                         MÓDULO PRINCIPAL
****************************************************************/
/* modppal.c
 *
 * Las dos líneas siguientes incluyen los ficheros especificados
 */
#include "declara2.h"
#include "declara1.h"
#include <stdio.h>

main()    /* FUNCIÓN PRINCIPAL */
{
  char mensaje[25];
  TipoReg registro;

  registro = LeerRegistro();
  Verificar(registro, mensaje);
  putchar('\n');
  puts(mensaje);
}
 
