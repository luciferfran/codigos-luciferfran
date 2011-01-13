/*********** Conversi�n de min�sculas a may�sculas ***********/
/* strupr.c
 */
#include <stdio.h>

#define LONG_MAX 81	    // longitud m�xima de la cadena
void MinusculasMayusculas(char str[]);

main() // funci�n principal
{
  char cadena[LONG_MAX];
  int i = 0;

  printf ("Introducir una cadena: ");
  gets(cadena);
  MinusculasMayusculas(cadena); // llamada a la funci�n
  printf ("%s\n", cadena);
}

/**************************************************************
                 Funci�n Min�sculasMay�sculas
**************************************************************/
// Convierte min�sculas a may�sculas

void MinusculasMayusculas(char str[])
{
  int i = 0, desp = 'a' - 'A';

  for (i = 0; str[i] != '\0'; ++i)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - desp;
}
