/* Funci�n "longcad":
 *   devuelve la longitud de una cadena.
 * longcad.c
 */
#include <stdio.h>

int longcad(char *);

main()
{
  char *cadena = "abcd"; // el car�cter de terminaci�n '\0'
                         // es a�adido autom�ticamente
  printf("%d\n", longcad(cadena)); // escribe: 4
}

int longcad(char *cad)
{
  char *p = cad;         // p apunta al primer car�cter
  while (*p != '\0')     // *p != 0 es equivalente
    p++;                 // siguiente car�cter
  return (p - cad);
}
