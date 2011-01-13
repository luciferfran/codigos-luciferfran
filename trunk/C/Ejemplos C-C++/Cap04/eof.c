/* eof.c
 */
#include <stdio.h>

main()
{
  int r = 0, opcion;
  float precio = 0;

  printf("Precio: ");
  r = scanf("%g", &precio);

  (r == EOF) ? printf("Fin de la entrada de datos\n")
             : printf("%g\n", precio);

  //clearerr(stdin);
  
  printf("Opción: ");
  r = scanf("%d", &opcion);
  printf("%d\n", r);
}
