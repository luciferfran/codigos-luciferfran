// entrada1.c
#include <stdio.h>

main()
{
  int a; float b; char c;
   
  scanf("%d %f %c", &a, &b, &c);
  printf("a = %d, b = %g, c = %c\n", a, b, c);
  scanf("%d , %f , %c", &a, &b, &c);
  printf("a = %d, b = %g, c = %c\n", a, b, c);
  scanf("%d : %f : %c", &a, &b, &c);
  printf("a = %d, b = %g, c = %c\n", a, b, c);
  
  scanf("%d%f%c", &a, &b, &c);
  printf("a = %d, b = %g, c = %c\n", a, b, c);
  scanf("%d,%f,%c", &a, &b, &c);
  printf("a = %d, b = %g, c = %c\n", a, b, c);
}
