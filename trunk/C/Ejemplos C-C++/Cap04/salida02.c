/* salida02.c
 */
#include <stdio.h>

main() 
{
  char car; 
  static char nombre[] = "La temperatura ambiente"; 
  int a, b, c;
  float x, y, z;
   
  car = 'C'; a = 20; b = 350; c = 4995;
  x = 34.5; y = 1234; z = 1.248;
   
  printf("\n%s es de ", nombre); 
  printf("%d grados %c\n", a, car); 
  printf("\n"); 
  printf("a = %6d\tb = %6d\tc = %6d\n", a, b, c); 
  printf("\nLos resultados son los siguientes:\n"); 
  printf("\n%5s\t\t%5s\t\t%5s\n", "x", "y", "z"); 
  printf("________________________________________\n"); 
  printf("\n%8.2f\t%8.2f\t%8.2f", x, y, z); 
  printf("\n%8.2f\t%8.2f\t%8.2f\n", x+y, y/5, z*2); 
  printf("\n\n"); 
  z *= (x + y); 
  printf("Valor resultante: %.3f\n", z); 
}
