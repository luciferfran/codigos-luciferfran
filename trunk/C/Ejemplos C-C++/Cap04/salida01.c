/* salida01.c
 */
#include <stdio.h>

main()
{
  int a = 12345;
  float b = 54.865F;
   
  printf("%d\n", a);       /* escribe 12345\n */
  printf("\n%10s\n%10s\n", "abc", "abcdef"); 
  printf("\n%-10s\n%-10s\n", "abc", "abcdef");
  printf("\n");            /* avanza a la siguiente línea */
  printf("%.2f\n", b);     /* escribe b con dos decimales */
}
