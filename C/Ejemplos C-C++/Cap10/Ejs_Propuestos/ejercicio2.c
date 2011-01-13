/* Cifrado, descifrado de documentos
 * ejercicio2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ReflejarByte( c )\
         ((((c)&0x01) << 7) | (((c)&0x02) << 5) |\
          (((c)&0x04) << 3) | (((c)&0x08) << 1) |\
          (((c)&0x10) >> 1) | (((c)&0x20) >> 3) |\
          (((c)&0x40) >> 5) | (((c)&0x80) >> 7))

unsigned char cifrar(unsigned char byte, unsigned char clave);
unsigned char descifrar(unsigned char byte, unsigned char clave);

main(int argc, char *argv[])
{                                                 
  int clave, byte;
  if (argc < 3 || (strncmp( argv[1], "-c", 2) != 0 && strncmp( argv[1], "-d", 2) != 0))
  {
    printf("Sintaxis:\n%s -c clave\n (clave es un número del 0 al 255)\n", argv[0]);
    exit(-1);
  }                                                
  clave = atoi(argv[2]);
  if (strncmp( argv[1], "-c", 2) == 0)
    while ( (byte = fgetc(stdin)) != EOF)
    {
      if (ferror(stdin))
        perror("ERROR entrada estándar");
      if( fputc(cifrar((unsigned char) byte, (unsigned char) clave), stdout) == EOF)
        perror("ERROR salida estándar");
    }
  else
    while ( (byte = fgetc(stdin)) != EOF)
    {
      if (ferror (stdin))
        perror("ERROR entrada estándar");
      if( fputc(descifrar((unsigned char)byte, (unsigned char)clave), stdout) == EOF)
        perror("ERROR salida estándar");
    }
}

unsigned char cifrar(unsigned char byte, unsigned char clave)
{
  return (~ReflejarByte( byte ^ clave ));
}

unsigned char descifrar(unsigned char byte, unsigned char clave)
{
  return (ReflejarByte( ~byte ) ^ clave);
}
