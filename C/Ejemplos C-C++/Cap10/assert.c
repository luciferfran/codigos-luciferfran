/********************** Macro ASSERT ***********************/
/* assert.c
 */
#include <stdio.h>
#include <stdlib.h>

#define N 10

#define ASSERT(expresion_de_bool) \
                     \
if( !(expresion_de_bool) )\
{ \
  printf("%s(%d): índice fuera de límites.\n", \
  __FILE__, __LINE__);\
  exit(1);\
}

main()
{
  int a[N], i = 0;
  // ...

  printf("Índice del elemento que desea modificar: ");
  scanf("%d", &i); 
  ASSERT(i >= 0 && i < N);

  printf("a[i] = "); scanf("%d", &a[i]);
  // ...
}
