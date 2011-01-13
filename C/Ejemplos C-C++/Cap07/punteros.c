/* punteros.c
 */
#include <stdio.h>

main()
{
  // Las dos líneas siguientes declaran la variable entera a,
  // los punteros p y q a enteros y la variable real b.
  int a = 10, *p = NULL, *q = NULL;
  double b = 0.0;
  q = &a;  // asigna la dirección de a, a la variable q
           // q apunta a la variable entera a
  b = *q;  // asigna a b el valor de la variable a
  *p = 20; // error: asignación no válida
           // ¿a dónde apunta p?
  printf("En la dirección %.4X está el dato %g\n", q, b);
  printf("En la dirección %.4X está el dato %d\n", p, *p);
}
