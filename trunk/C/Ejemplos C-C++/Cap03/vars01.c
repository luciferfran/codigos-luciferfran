/* vars01.c - Variables globales y locales
 */
#include <stdio.h>

/* Definici�n de var1 como variable GLOBAL */
int var1 = 50;

main()         
{ /* COMIENZO DE main Y DEL PROGRAMA */

  printf("%d\n", var1); /* se escribe 50 */
  
  { /* COMIENZO DEL BLOQUE 1 */
  
    /* Definici�n de var1 y var2 como variables
       LOCALES en el BLOQUE 1 y en el BLOQUE 2 */
    int var1 = 100, var2 = 200;
    
    printf("%d %d\n", var1, var2); /* escribe 100 y 200 */
    
    { /* COMIENZO DEL BLOQUE 2 */
      /* Redefinici�n de la variable LOCAL var1 */
      int var1 = 0;
      
      printf("%d %d\n", var1, var2); /* escribe 0 y 200 */
      
    } /* FINAL DEL BLOQUE 2 */

    printf("%d\n", var1); /* se escribe 100 */
  
  } /* FINAL DEL BLOQUE 1 */
  
  printf("%d\n", var1); /* se escribe 50 */
  
} /* FINAL DE main Y DEL PROGRAMA */
