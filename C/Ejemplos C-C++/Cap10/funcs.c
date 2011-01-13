/****************************************************************
                            FUNCIONES
****************************************************************/
/* funcs.c
 *
 * La siguiente l�nea incluye el fichero especificado
 */
#include "declara2.h"
#include <string.h>
#include <stdio.h>

TipoReg LeerRegistro()
{
  TipoReg registro;

  printf("Denominaci�n "); gets(registro.denominacion);
  printf("Existencias  "); scanf("%d", &registro.existencias);
  return registro;
}

void Verificar(TipoReg registro, char *mensaje)
{
  if (registro.existencias < 5)
    strcpy(mensaje, "Por debajo de m�nimos");
  else
    strcpy(mensaje, "Por encima de m�nimos");
}
