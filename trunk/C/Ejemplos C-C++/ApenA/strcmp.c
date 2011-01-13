/* strcmp.c
 */
#include <stdio.h>
#include <string.h>

main(void)
{
  char cadena1[] = "La Comunidad de Cantabria es muy bonita";
  char cadena2[] = "La Comunidad de CANTABRIA es muy bonita";
  char temp[20];
  int resu;

  // Se diferencian mayúsculas de minúsculas
  printf( "Comparar las cadenas:\n\n%s\n%s\n\n", cadena1, cadena2 );
  resu = strcmp( cadena1, cadena2 );
  if ( resu > 0 )
    strcpy( temp, "mayor que" );
  else if ( resu < 0 )
    strcpy( temp, "menor que" );
  else
    strcpy( temp, "igual a" );
  printf( "strcmp: cadena 1 es %s cadena 2\n", temp );
}
