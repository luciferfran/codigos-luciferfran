/* C�lculo de centros num�ricos
 *
 * Cap05 - ejercicio6.c
 */

#include <stdio.h>

main()
{                         
  long int n = 1000, Cont, SumInf = 0, SumSup;

  printf("\nEscriba un n�mero: ");
  scanf("%ld", &n); // Si no se introduce un n�mero correcto, se toma 1000 por defecto
  printf("Los centros num�ricos que hay entre 1 y %ld son:\n", n);
  for (Cont = 1; Cont < n; Cont++)
  { // 'SumInf' tiene la suma de los n�meros anteriores a 'Cont' 
    long int Temp;
    for (Temp = Cont + 1, SumSup = 0; SumSup < SumInf; Temp++)
    { // 'SumSup' tiene la suma de los n�meros posteriores a 'Cont'
      SumSup += Temp;
      if (SumSup == SumInf) printf("%ld ", Cont); 
    }
    SumInf += Cont;
  }
}

/* Vea tambi�n "Ejercicios resueltos" en el cap�tulo 12 (Algoritmos) */
