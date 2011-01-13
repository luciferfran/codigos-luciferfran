/********************* Función realloc *********************/
/* realloc.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{ 
  int *p = NULL, *q = NULL;
  int nbytes = 100;

  // Asignar nbytes bytes
  if ((p = (int *)malloc(nbytes)) == NULL )
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }

  printf("Se han asignado %d bytes de memoria\n", nbytes);

  // Operaciones sobre el bloque de memoria
  // ...

  // Reasignar el bloque para que pueda contener más datos
  if (nbytes == 0)
  {
    free(p);
    printf("\nEl bloque ha sido liberado\n");
    return -1;
  }

  q = realloc(p, nbytes * 2); 
 
  if (q == NULL) 
  { 
    printf("La reasignación no ha sido posible\n");
    printf("Se conserva el bloque original\n");
  }
  else
  {
    p = q;
    printf("Bloque reasignado\n");
    printf("Nuevo tamaño %d bytes\n", nbytes * 2);
  }

  // Operaciones sobre el bloque de memoria
  // ...

  free(p);
  printf("\nEl bloque ha sido liberado\n");
  return 0;
}
