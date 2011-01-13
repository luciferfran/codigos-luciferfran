/* Escribir el contenido de una matriz de cadenas de caracteres.
 * Versión con punteros.
 * punteros_a_cadenas.c
 */
#include <stdio.h>
 
main() 
{
  int i;
  char cad[5][81]; // matriz de cadenas de caracteres
  char *p[5];      // matriz de punteros
  char **q;        // puntero a puntero a un carácter

  for (i = 0; i < 5; i++)
    p[i] = cad[i];

  q = p;

  for (i = 0; i < 5; i++)
    gets(q[i]);

  for (i = 0; i < 5; i++)
    printf("%s\n", q[i]);
}
