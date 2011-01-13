/* burbuja.c
 */
#include <stdio.h>
#include <string.h>

/////////////////////////////////////////////////////////////////
// Ordenaci�n por el m�todo de la burbuja. La funci�n "ordenar"
// se presenta en dos versiones: una para ordenar una matriz de
// tipo double y otra para ordenar una matriz de cadenas.
//
void ordenar_n(double m[], int n_elementos)
{
  // Ordenaci�n num�rica
  double aux;
  int i, s = 1;

  while (s && (--n_elementos > 0))
  {
    s = 0; // no permutaci�n
    for (i = 1; i <= n_elementos; i++)
      // � el elemento (i-1) es mayor que el (i) ?
      if (m[i-1] > m[i])
      {
        // permutar los elementos (i-1) e (i)
        aux = m[i-1];
        m[i-1] = m[i];
        m[i] = aux;
        s = 1; // permutaci�n
      }
  }
}

void ordenar_a(char *m[], int n_elementos)
{
  // Ordenaci�n alfab�tica
  char *aux;
  int i, s = 1;

  while (s && (--n_elementos > 0))
  {
    s = 0; // no permutaci�n
    for (i = 1; i <= n_elementos; i++)
      // � el elemento (i-1) es mayor que el (i) ?
      if (strcmp(m[i-1], m[i]) > 0)
      {
        // permutar los elementos (i-1) e (i)
        // (se permutan sus direcciones)
        aux = m[i-1];
        m[i-1] = m[i];
        m[i] = aux;
        s = 1; // permutaci�n
      }
  }
}

main()
{
  int n_elementos = 5, i = 0;
  // Matriz num�rica
  double m[] = {3,2,1,5,4};
  // Matriz de punteros a cadenas de caracteres
  char *s[] = {"ccc","bbb","aaa","eee","ddd"};

  ordenar_n(m, n_elementos);
  for (i = 0; i < n_elementos; i++)
    printf("%g ", m[i]);
  printf("\n");
  
  ordenar_a(s, n_elementos);
  for (i = 0; i < n_elementos; i++)
    printf("%s ", s[i]);
  printf("\n");
}
