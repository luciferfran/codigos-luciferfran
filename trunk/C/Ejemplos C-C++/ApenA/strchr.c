/* Este programa ilustra como buscar un car�cter con strchr
 * (hacia adelante) o con strrchr (hacia atr�s).
/* strchr.c
 */
#include <stdio.h>
#include <string.h>

main( void )
{
  int  car = 'i';
  char cadena[] = "La biblioteca de C proporciona muchas funciones";
  char dec1[] =   "          1         2         3         4         ";
  char uni2[] =   "01234567890123456789012345678901234567890123456789";
  char *pdest;
  int resu;
   
  printf( "Cadena en la que se busca: \n%s\n", cadena );
  printf( "%s\n%s\n\n", dec1, uni2 );
  printf( "Buscar el car�cter: %c\n\n", car );
  
  // Buscar de adelante hacia atr�s
  pdest = strchr( cadena, car );
  resu = pdest - cadena;
  if ( pdest != NULL )
    printf( "La %c primera est� en la posici�n %d\n", car, resu );
  else
    printf( "%c no se encuentra en la cadena\n" );

  // Buscar desde atr�s hacia adelante
  pdest = strrchr( cadena, car );
  resu = pdest - cadena;
  if ( pdest != NULL )
    printf( "La �ltima %c est� en la posici�n %d\n\n", car, resu );
  else
    printf( "%c no se encuentra en la cadena\n" );
}


