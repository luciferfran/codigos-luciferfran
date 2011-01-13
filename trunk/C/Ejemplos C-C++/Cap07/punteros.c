/* punteros.c
 */
#include <stdio.h>

main()
{
  // Las dos l�neas siguientes declaran la variable entera a,
  // los punteros p y q a enteros y la variable real b.
  int a = 10, *p = NULL, *q = NULL;
  double b = 0.0;
  q = &a;  // asigna la direcci�n de a, a la variable q
           // q apunta a la variable entera a
  b = *q;  // asigna a b el valor de la variable a
  *p = 20; // error: asignaci�n no v�lida
           // �a d�nde apunta p?
  printf("En la direcci�n %.4X est� el dato %g\n", q, b);
  printf("En la direcci�n %.4X est� el dato %d\n", p, *p);
}
