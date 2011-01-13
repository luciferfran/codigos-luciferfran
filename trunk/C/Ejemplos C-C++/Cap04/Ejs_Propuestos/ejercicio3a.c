/* Calcula la edad en el 2030
 *
 * Cap4 - ejercicio3a.c
 */

#include <stdio.h>

main()
{                                                                            
  char nombre[30]; // Se reservan 30 caracteres para el nombre
  int edad, anyo;

  printf("Introduzca su nombre: ");
  scanf("%s", nombre); // 'nombre' es una cadena de caracteres
  printf("Introduzca su edad: ");
  scanf("%d", &edad);
  printf("Introduzca el año actual ####: ");
  scanf("%d", &anyo);
  printf("Hola %s, en el año 2030 cumplirás %d años\n", nombre, edad + (2030 - anyo) + 1);
}
