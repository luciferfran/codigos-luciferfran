/* Suma de m�ltiplos de 5
 *
 * Cap05 - ejercicio2.c
 */

#include <stdio.h>        

main()
{                 
  long int a, b, c, sum = 0;
  printf("Introduzca los l�mites a y b.\n");
  
    // Obs�rvese c�mo se ha empleado el operador coma en la siguiente expresi�n
  while(((printf("a = "), fflush(stdin), scanf("%ld", &a)) != 1) || a < 0);
    // Si a es negativo, pide de nuevo una entrada 
                           
  while(((printf("b = "), fflush(stdin), scanf("%ld", &b)) != 1) || b < 0);
    // Si b es negativo, pide de nuevo una entrada 
  
  if(a > b)       // Si a es mayor que b, intercambia los valores
  {
    long int temp = a;
    a = b;
    b = temp;
  }
  
  
  while (a % 5) a++; // primer m�ltiplo de 5
  for (c = a; c <= b; c+=5)
  {
    printf("%d\t", c); 
    sum += c;         // sum almacena los m�ltiplos de 5
  }                                                                 
  printf("\nLa suma de los m�ltiplos de 5 es: %d", sum);
}
