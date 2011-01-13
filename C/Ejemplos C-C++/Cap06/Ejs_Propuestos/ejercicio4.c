/* Cambia a min�sculas.
 * Utilizando la funci�n strlwr de la biblioteca de C, la soluci�n es inmediata.
 * Por eso, nosotros vamos a realizar una funci�n de conversi�n propia.
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
  printf("La cadena en min�sculas es:\n%s\n", MayusculasMinusculas(cadena));
    // No se podr�a poner tilde a las may�sculas   
}

char *MayusculasMinusculas(char *str)
{
  int i = 0, desp = 'a' - 'A';
  
  for (i = 0; str[i] != 0; i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += desp;
  return str;
}
