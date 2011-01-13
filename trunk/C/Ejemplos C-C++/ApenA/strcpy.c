/* Este programa utiliza strcpy y strcat
 * strcpy.c
 */
#include <stdio.h>
#include <string.h>

main(void)
{
  char cadena[81];
  strcpy( cadena, "Hola, " );
  strcat( cadena, "strcpy " );
  strcat( cadena, "y " );
  strcat( cadena, "strcat te saludan!" );
  printf( "cadena = %s\n", cadena );
}


