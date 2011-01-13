/******** Palabras con cuatro o m�s vocales diferentes ********/
/* vocales.c
 */
#include <stdio.h>

main()
{
  int np = 0;  // n�mero de palabras con 4 vocales distintas
  int a = 0, e = 0, i = 0, o = 0, u = 0;
  char car;

  printf("Introducir texto. ");
  printf("Para finalizar introducir la marca EOF\n\n");
  while ((car = getchar()) != EOF)
  {
    switch (car)
    {
      case 'A': case 'a': case '�':
        a = 1;
        break;
      case 'E': case 'e': case '�':
        e = 1;
        break;
      case 'I': case 'i': case '�':
        i = 1;
        break;
      case 'O': case 'o': case '�':
        o = 1;
        break;
      case 'U': case 'u': case '�':
        u = 1;
        break;
      default:
        if (car == ' ' || car == '\t' || car == '\n')
        {
          if ((a + e + i + o + u) >= 4) np++;
          a = e = i = o = u = 0;
        }
    } // fin del switch
  } // fin del while
  if ((a + e + i + o + u) >= 4) np++;
  printf("N�mero de palabras con 4 vocales distintas: %d\n", np);
}
