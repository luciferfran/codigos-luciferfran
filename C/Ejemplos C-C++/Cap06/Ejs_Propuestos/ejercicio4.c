/* Cambia a minúsculas.
 * Utilizando la función strlwr de la biblioteca de C, la solución es inmediata.
 * Por eso, nosotros vamos a realizar una función de conversión propia.
 *
 * Cap6\ejercicio4.c
 */

#include <stdio.h>
#include <string.h>

char *MayusculasMinusculas(char *);

main()
{                     
  char cadena[100]; // se reserva espacio para 100 caracteres
  printf ("Introduzca una cadena de caracteres:\n");
  gets(cadena); 
  printf("La cadena en minúsculas es:\n%s\n", MayusculasMinusculas(cadena));
    // No se podría poner tilde a las mayúsculas   
}

char *MayusculasMinusculas(char *str)
{
  int i = 0, desp = 'a' - 'A';
  
  for (i = 0; str[i] != 0; i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += desp;
  return str;
}
