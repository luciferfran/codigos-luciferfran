/* Este programa muestra cómo los números almacenados como
 * cadenas de caracteres pueden ser convertidos a valores
 * numéricos utilizando las funciones atof, atoi, y atol.
 *
 * atof.c
 */
#include <stdio.h>
#include <stdlib.h>

main(void)
{
  char *s = NULL; double x = 0; int i = 0; long l = 0;
  s = "  -3208.15E-13";    // para ver como trabaja atof
  x = atof( s );
  printf( "atof: cadena ASCII: %-17s double: %e\n", s, x );
  s = "8.7195642337X120";  // para ver como trabaja atof
  x = atof( s );
  printf( "atof: cadena ASCII: %-17s double: %e\n", s, x );
  s = "  -8995 libros";    // para ver como trabaja atoi
  i = atoi( s );
  printf( "atoi: cadena ASCII: %-17s int  : %d\n", s, i );
  s = "89954 pesetas";     // para ver como trabaja atol
  l = atol( s );
  printf( "atol: cadena ASCII: %-17s long : %ld\n", s, l );
}
