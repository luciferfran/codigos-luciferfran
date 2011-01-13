/************* Comprimir/descomprimir un fichero *************/
/* compdesc.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  unsigned char pixel;
  unsigned char total_bytes;
} registro;

void comprimir( FILE *forigen, FILE *fcomprimido )
{
  unsigned char byte = 0, byteanterior = 0, total = 0;
  registro reg;
  int bytesreg = sizeof(registro);
  
  // Leer los bytes del fichero
  byte = fgetc( forigen );
  while ( !ferror( forigen ) && !feof( forigen ) )
  {
    total = 0;
    byteanterior = byte;
    
    // Contar bytes consecutivos repetidos
    do
    {
      total++;
      byte = fgetc( forigen );
    }  
    while ( byteanterior == byte && total < 255 &&
            !ferror( forigen ) && !feof( forigen ) );

    // Escribir el byte y el número de apariciones consecutivas
    reg.pixel = byteanterior;
    reg.total_bytes = total;
    fwrite( &reg, bytesreg, 1, fcomprimido );
  }
  if ( ferror( forigen ) )
    perror( "Error durante la lectura" );
}

void descomprimir( FILE *fcomprimido, FILE *fdestino )
{
  registro reg;
  int bytesreg = sizeof(registro);
  unsigned char i = 0;
  
  // Leer los datos del fichero comprimido
  fread( &reg, bytesreg, 1, fcomprimido );
  while ( !ferror( fcomprimido ) && !feof( fcomprimido ) )
  {
    // Descomprimir
    for ( i = 0; i < reg.total_bytes; i++ )
      fputc( reg.pixel, fdestino );
    
    fread( &reg, bytesreg, 1, fcomprimido );
  }
  if ( ferror( fcomprimido ) )
    perror( "Error durante la lectura" );
}

int main( int argc, char *argv[] )
{
  FILE *forigen = NULL, *fdestino = NULL;

  if ( argc != 4 )
  {
    printf( "Sintaxis: comp {-c|-d} forigen fdestino\n" );
    exit( 1 );
  }
  
  if ( (forigen = fopen( argv[2], "r" )) == NULL )
  {
    printf( "El fichero %s no puede abrirse\n", argv[2] );
    exit( 1 );
  }

  if ( (fdestino = fopen( argv[3], "w" )) == NULL )
  {
    printf( "El fichero %s no puede abrirse\n", argv[3] );
    exit( 1 );
  }
  
  if ( argv[1][0] == '-' && argv[1][1] == 'c' )
    comprimir( forigen, fdestino );
  else if ( argv[1][0] == '-' && argv[1][1] == 'd' )
    descomprimir( forigen, fdestino );
  else
    printf( "Opción incorrecta\n" );
    
  fclose( forigen );
  fclose( fdestino );
  return 0;
}
