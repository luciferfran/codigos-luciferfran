/* Resultado del análisis
 *
 * Cap6\ejercicio7.c
 */

/*
   El programa pedirá un carácter y muestra su valor equivalente
   en binario.
   A continuación muestra la cadena de bits anterior, invertida.
    
	 La función Visualizar es la encargada de mostrar los bits uno
	 a uno del valor pasado cómo argumento.
	 La función fnxxx invierte el valor pasado como argumento,
	 utilizando operadores lógicos a nivel de bits y devuelve
	 dicho resultado.
*/ 

#include <stdio.h>

void Visualizar( unsigned char c );
unsigned char fnxxx( unsigned char c );

main()
{
  unsigned char c;

  printf("Introducir un carácter: ");
  c = getchar();
  Visualizar(c);

  printf("\nCarácter resultante:\n");
  c = fnxxx(c);
  Visualizar(c);
}

void Visualizar( unsigned char c )
{
  int i = 0;
  for (i = 7; i>=0; i--)
    printf("%d", (c & (1 << i)) ? 1 : 0);
  printf("\n");
}

unsigned char fnxxx( unsigned char c )
{

  return ((((c)&0x01) << 7) | (((c)&0x02) << 5) |
          (((c)&0x04) << 3) | (((c)&0x08) << 1) |
          (((c)&0x10) >> 1) | (((c)&0x20) >> 3) |
          (((c)&0x40) >> 5) | (((c)&0x80) >> 7));
}
