/* Cuenta caracteres
 *
 * Cap6\ejercicio6.c
 *
 * Utilizando las funciones de la bibliotca de C la solución sería:
 *
 * gets(cadena);
 * printf("\nLa línea leída es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
 *   cadena, strlen(cadena));
 *
 * Nosotros utilizaremos una función "longitud" propia.
 */
#include <stdio.h>
#include <string.h>

int longitud(char []);

main()
{                     
  char cadena[200]; // se reserva espacio para 100 caracteres
  printf("Introduzca una cadena de caracteres:\n");
  gets(cadena);
  printf("\nLa línea leída es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
    cadena, longitud(cadena));
}

int longitud(char str[])
{
  int i = 0;
  
  while (str[i++]);
  
  return --i; // para no contar el carácter '\0'
}
