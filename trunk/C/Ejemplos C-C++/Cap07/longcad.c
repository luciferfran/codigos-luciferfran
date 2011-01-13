/* Función "longcad":
 *   devuelve la longitud de una cadena.
 * longcad.c
 */
#include <stdio.h>

int longcad(char *);

main()
{
  char *cadena = "abcd"; // el carácter de terminación '\0'
                         // es añadido automáticamente
  printf("%d\n", longcad(cadena)); // escribe: 4
}

int longcad(char *cad)
{
  char *p = cad;         // p apunta al primer carácter
  while (*p != '\0')     // *p != 0 es equivalente
    p++;                 // siguiente carácter
  return (p - cad);
}
