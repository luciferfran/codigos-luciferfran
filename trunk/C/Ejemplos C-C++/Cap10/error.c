/****** Compilación condicional ******/
/* error.c
 *
 * Cuando intente compilar este programa obtendrá un error
 * "PAIS_ACTIVO no definido" por lo que indica el mensaje.
 */
#include <stdio.h>

#define USA 1   // Estados Unidos
#define ESP 2   // España
#define JPN 3   // Japón

main() 
{ 
  #if !defined(PAIS_ACTIVO)
    #error PAIS_ACTIVO no definido.
  #endif

  #if PAIS_ACTIVO == USA 
     char moneda[] = "dólar"; 
  #elif PAIS_ACTIVO == ESP 
     char moneda[] = "euro "; 
  #elif PAIS_ACTIVO == JPN 
     char moneda[] = "yen  "; 
  #endif 
 
  printf("%s\n", moneda); 
} 
