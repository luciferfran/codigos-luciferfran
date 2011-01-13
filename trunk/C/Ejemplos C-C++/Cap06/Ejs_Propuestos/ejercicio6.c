/* Cuenta caracteres
 *
 * Cap6\ejercicio6.c
 *
 * Utilizando las funciones de la bibliotca de C la soluci�n ser�a:
 *
 * gets(cadena);
 * printf("\nLa l�nea le�da es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
 *   cadena, strlen(cadena));
 *
 * Nosotros utilizaremos una funci�n "longitud" propia.
 */
#include <stdio.h>
#include <string.h>

int longitud(char []);

main()
{                     
  char cadena[200]; // se reserva espacio para 100 caracteres
  printf("Introduzca una cadena de caracteres:\n");
  gets(cadena);
  printf("\nLa l�nea le�da es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
    cadena, longitud(cadena));
}

int longitud(char str[])
{
  int i = 0;
  
  while (str[i++]);
  
  return --i; // para no contar el car�cter '\0'
}
