/******************* Funciones malloc y free *******************/
/* malloc.c
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *p = NULL;
  int nbytes = 100;

  if ((p = (int *)malloc(nbytes)) == NULL )
  {
    printf("Insuficiente espacio de memoria\n");
    exit(-1);
  }

  printf("Se han asignado %d bytes de memoria\n", nbytes);
  // ...
  free(p);
  return 0;
}
