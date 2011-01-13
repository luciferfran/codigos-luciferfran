/********************** Búsqueda Binaria **********************/
/* busquedaBin.c
 */
#include <stdio.h>
#include <stdlib.h>

int busquedaBin(double m[], double v, int n_elementos)
{
  // El método búsquedaBin devuelve como resultado la posición
  // del valor v en m. Si el valor no se localiza devuelve -1.
  int mitad, inf = 0, sup = n_elementos - 1;

  if (n_elementos == 0) return -1;
  
  do
  {
    mitad = (inf + sup) / 2;
    if (v > m[mitad])
      inf = mitad + 1;
    else
      sup = mitad - 1;
  }
  while ( m[mitad] != v && inf <= sup);

  if (m[mitad] == v)
    return mitad;
  else
    return -1;
}

main()
{
  // Matriz ordenada
  double lista[] = { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30,
                     33, 36, 39, 42, 45, 48, 51, 54, 57, 60 };
  // Número de elementos de la matriz
  const int n_elementos = sizeof(lista)/sizeof(float);
  int posicion = 0;
  double valor = 0.0;

  printf("Introducir el valor a buscar ");
  scanf("%lf", &valor);

  posicion = busquedaBin(lista, valor, n_elementos-1);

  if (posicion != -1)
    printf("\nLa posición de %g es %d\n", valor, posicion);
  else
    printf("\nEl valor %g no está en la lista\n", valor);
}
