/* Calcula la edad en el 2030
 *
 * Cap4 - ejercicio3b.c
 */

#include <stdio.h>
#include <time.h>
                 
/* Este programa usa un método mejor para calcular los años, basado en las funciones de 
   tiempo del capítulo 8. (Consúltense para más referencias)*/                
main()
{                                                                            
  char nombre[30];
  int edad;
  struct tm *tiempo;
  
  time_t segundos;
  time(&segundos);
  tiempo = localtime(&segundos);
  printf("Introduzca su nombre: ");
  scanf("%s", nombre); // 'nombre' es una cadena de caracteres
  printf("Introduzca su edad: ");
  scanf("%d", &edad);
  printf("Hola %s, en el año 2030 cumplirás %d años\n", nombre,
          edad + (2030 - (tiempo->tm_year + 1900) + 1) );
  // Ahora, calcula su edad estemos en el año en que estemos     
}
