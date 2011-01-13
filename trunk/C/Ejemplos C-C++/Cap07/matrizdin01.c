/*************** Matriz dinámica de una dimensión ***************/
/* matrizdin01.c
 */
#include <stdio.h>
#include <stdlib.h>
// #include <memory.h> // necesaria para memset

main() 
{
  int *m = NULL;
  int nBytes = 0, correcto = 0, nElementos = 0, i = 0;
  
  do
  {
    printf("Número de elementos de la matriz: ");
    correcto = scanf("%d", &nElementos);
    fflush(stdin);
  }
  while ( !correcto || nElementos < 1 );

  // Tamaño del bloque de memoria
  nBytes = nElementos * sizeof(int);

  if ((m = (int *)malloc(nBytes)) == NULL )
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }
  printf("Se han asignado %u bytes de memoria\n", nBytes);
  
  // Iniciar los elementos de la matriz a cero
  for ( i = 0; i < nElementos; i++ )
    m[i] = 0;

  // Los elementos de la matriz pueden también ser puestos
  // a cero así:
  // memset(m, 0, nBytes);

  // Operaciones
  
  free(m);
  return 0;
}
 
