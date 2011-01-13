/*********** Conversión de minúsculas a mayúsculas ***********/
/* strupr.c
 */
#include <stdio.h>

#define LONG_MAX 81	    // longitud máxima de la cadena
void MinusculasMayusculas(char str[]);

main() // función principal
{
  char cadena[LONG_MAX];
  int i = 0;

  printf ("Introducir una cadena: ");
  gets(cadena);
  MinusculasMayusculas(cadena); // llamada a la función
  printf ("%s\n", cadena);
}

/**************************************************************
                 Función MinúsculasMayúsculas
**************************************************************/
// Convierte minúsculas a mayúsculas

void MinusculasMayusculas(char str[])
{
  int i = 0, desp = 'a' - 'A';

  for (i = 0; str[i] != '\0'; ++i)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - desp;
}
