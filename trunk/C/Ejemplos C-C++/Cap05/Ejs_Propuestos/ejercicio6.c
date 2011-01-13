/* Cálculo de centros numéricos
 *
 * Cap05 - ejercicio6.c
 */

#include <stdio.h>

main()
{                         
  long int n = 1000, Cont, SumInf = 0, SumSup;

  printf("\nEscriba un número: ");
  scanf("%ld", &n); // Si no se introduce un número correcto, se toma 1000 por defecto
  printf("Los centros numéricos que hay entre 1 y %ld son:\n", n);
  for (Cont = 1; Cont < n; Cont++)
  { // 'SumInf' tiene la suma de los números anteriores a 'Cont' 
    long int Temp;
    for (Temp = Cont + 1, SumSup = 0; SumSup < SumInf; Temp++)
    { // 'SumSup' tiene la suma de los números posteriores a 'Cont'
      SumSup += Temp;
      if (SumSup == SumInf) printf("%ld ", Cont); 
    }
    SumInf += Cont;
  }
}

/* Vea también "Ejercicios resueltos" en el capítulo 12 (Algoritmos) */
