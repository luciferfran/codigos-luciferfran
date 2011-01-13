/***************** Reflejar un byte *****************/
/* refejar.c
 */
#include <stdio.h>

#define ReflejarByte( c )\
         ((((c)&0x01) << 7) | (((c)&0x02) << 5) |\
          (((c)&0x04) << 3) | (((c)&0x08) << 1) |\
          (((c)&0x10) >> 1) | (((c)&0x20) >> 3) |\
          (((c)&0x40) >> 5) | (((c)&0x80) >> 7))

void Visualizar( unsigned char c );

main() 
{ 
  unsigned char c; 
 
  printf("Introducir un carácter: "); 
  c = getchar();
  Visualizar(c);
  
  c = ReflejarByte(c);
  printf("\nCarácter reflejado: %c\n", c); 
  Visualizar(c); 
} 

void Visualizar( unsigned char c )
{
  int i = 0;
  for (i = 7; i>=0; i--)
  {
    printf("\ni = %d ", i);
    printf("%d", (c & (1 << i)) ? 1 : 0);
  }
  printf("\n");
}
