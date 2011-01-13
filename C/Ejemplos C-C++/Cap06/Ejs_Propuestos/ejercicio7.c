/* Resultado del an�lisis
 *
 * Cap6\ejercicio7.c
 */

/*
   El programa pedir� un car�cter y muestra su valor equivalente
   en binario.
   A continuaci�n muestra la cadena de bits anterior, invertida.
    
	 La funci�n Visualizar es la encargada de mostrar los bits uno
	 a uno del valor pasado c�mo argumento.
	 La funci�n fnxxx invierte el valor pasado como argumento,
	 utilizando operadores l�gicos a nivel de bits y devuelve
	 dicho resultado.
*/ 

#include <stdio.h>

void Visualizar( unsigned char c );
unsigned char fnxxx( unsigned char c );

main()
{
  unsigned char c;

  printf("Introducir un car�cter: ");
  c = getchar();
  Visualizar(c);

  printf("\nCar�cter resultante:\n");
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
