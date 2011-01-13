#include <stdio.h>

int max(int x, int y);

main()
{
  int a = 0, b = 0, c = 0;
  int mayor = 0;
  
  printf("Valores a, b y c: ");
  scanf("%d %d %d", &a, &b, &c);

  mayor = max(a, b);     /* mayor de a y b */
  mayor = max(mayor, c); /* mayor del resultado anterior y de c */
  printf("Mayor = %d\n", mayor);
}
