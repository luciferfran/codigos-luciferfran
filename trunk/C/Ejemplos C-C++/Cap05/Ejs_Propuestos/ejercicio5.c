/* Pir�mide de d�gitos
 *
 * Cap05 - ejercicio5.c
 */

#include <stdio.h> 
       
#define COLUMNAS 80  // Se definen las constantes COLUMNAS = 80

main()
{                         
  int a = 0, b = 1, c;
  int FILAS;

  do
  {
    printf("N�mero de filas entre 11 y 20: ");
    scanf("%d", &FILAS);
  }
  while (FILAS < 11 || FILAS > 20);

  for (c = 1; c < FILAS; c++)
  {
    int despl, d;
    printf("\n"); // Pone el cursor en una l�nea nueva
    for (despl = COLUMNAS/4 - b; despl >= 0; despl--) 
      printf("  "); // Desplaza el cursor lo necesario a la derecha
    for(d = 1; d <= b; d++) 
    { // Imprime n�meros hasta el centro del tri�ngulo
      a++; 
      if(a > 9) a = 0; 
      printf("%d ", a);
    }
    for(d = 1; d < b; d++) 
    { // Imprime n�meros hasta el final del tri�ngulo
      a--; 
      if(a < 0) a = 9; 
      printf("%d ", a);
    }
    b++;
  }
}
