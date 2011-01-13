// centronum.c
//
#include <stdio.h>

//////////////////////////////////////////////////////////////////
// Calcular los centros numéricos entre 1 y n.
//
// Método de búsqueda binaria
//
// cn: centro numérico
// (1 a cn-1) cn (cn+1 a mitad)
// suma_grupo1 = suma de los valores desde 1 a cn-1
// suma_grupo2 = suma de los valores desde cn+1 a mitad
//
// La función devuelve como resultado el valor mitad.
// Si cn no es un centro numérico devuelve un valor 0.
//
long busquedaBin(long cn, long n)
{
  long suma_grupo1 = 0;
  long suma_grupo2 = 0;
  long mitad = 0;
  long inf = 0;         // límite inferior del grupo 2
  long sup = 0;         // límite superior del grupo 2

  if (cn <= 0 || n <= 0) return 0;
  
  suma_grupo1 = ((cn-1) * ((cn-1) + 1)) / 2;
  inf = cn+1;
  sup = n;
  
  // Búsqueda binaria
  do
  {
    mitad = (inf + sup) / 2;
    suma_grupo2 = (mitad * (mitad + 1)) / 2 - suma_grupo1 - cn;
    if (suma_grupo1 > suma_grupo2)
      inf = mitad + 1;
    else
      sup = mitad - 1;
  }
  while ( suma_grupo1 != suma_grupo2 && inf <= sup);

  if (suma_grupo2 == suma_grupo1)
    return mitad;
  else
    return 0;
}

main()
{
  long n;              // centros numéricos entre 1 y n
  long cn;             // posible centro numérico
  long lim_sup_grupo2; // límite superior del grupo 2

  printf("Centros numéricos entre 1 y ");
  scanf("%ld", &n);
  printf("\n");
  for (cn = 3; cn < n; cn++)
  {
    lim_sup_grupo2 = busquedaBin(cn, n); 
    if (lim_sup_grupo2 != 0)
      printf("%d es centro numérico de 1 a %d y %d a %d\n",
             cn, cn-1, cn+1, lim_sup_grupo2);
  }
}
