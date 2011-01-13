/* sprintf.c. Este programa utiliza sprintf para almacenar
 * en buffer la cadena de caracteres formada por:
 *
 *            Cadena:    ordenador
 *            Carácter:  /        
 *            Entero:    40       
 *            Real:      1.414214 
 */
#include <stdio.h>

main(void)
{
  char  buffer[200], s[] = "ordenador", c = '/';
  int   i = 40, j;
  float f = 1.414214F;

  j  = sprintf( buffer,     "\tCadena:    %s\n", s );
  j += sprintf( buffer + j, "\tCarácter:  %c\n", c );
  j += sprintf( buffer + j, "\tEntero:    %d\n", i );
  j += sprintf( buffer + j, "\tReal:      %f\n", f );
  printf( "Salida:\n%s\nNúmero de caracteres = %d\n", buffer, j );
}
