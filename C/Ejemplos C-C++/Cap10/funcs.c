/****************************************************************
                            FUNCIONES
****************************************************************/
/* funcs.c
 *
 * La siguiente línea incluye el fichero especificado
 */
#include "declara2.h"
#include <string.h>
#include <stdio.h>

TipoReg LeerRegistro()
{
  TipoReg registro;

  printf("Denominación "); gets(registro.denominacion);
  printf("Existencias  "); scanf("%d", &registro.existencias);
  return registro;
}

void Verificar(TipoReg registro, char *mensaje)
{
  if (registro.existencias < 5)
    strcpy(mensaje, "Por debajo de mínimos");
  else
    strcpy(mensaje, "Por encima de mínimos");
}
