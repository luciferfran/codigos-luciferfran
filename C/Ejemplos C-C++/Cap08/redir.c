/************** Redirección de la entrada-salida  **************/
/* redir.c
 */
#include <stdio.h>

int main( int argc, char *argv[] )
{
  int n;
  
  while (scanf("%d", &n) != EOF)
  {
    printf("%6d", n);
    if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'l')
      printf((n%2) ? " es impar" : " es par");
    printf("\n");
  }
  return 0;
}
