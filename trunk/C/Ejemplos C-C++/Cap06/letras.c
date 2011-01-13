/**** Frecuencia con la que aparecen las letras en un texto ****/
/* letras.c
 */
#include <stdio.h>
#define N_ELEMENTOS 'z'-'a'+1  // n�mero de elementos

main()
{ 
  int c[N_ELEMENTOS]; // matriz c
  char car;           // �ndice
  
  // Poner los elementos de la matriz a cero
  for (car = 'a'; car <= 'z'; car++)
    c[car - 'a'] = 0;

  // Entrada de datos y c�lculo de la tabla de frecuencias
  printf("Introducir texto.\n");
  printf("Para finalizar introducir la marca EOF\n\n");
  while ((car = getchar()) != EOF)
  {
    // Si el car�cter le�do est� entre la 'a' y la 'z'
    // incrementar el contador correspondiente
    if (car >= 'a' && car <= 'z')
      c[car - 'a']++;
  }

  // Escribir la tabla de frecuencias
  for (car = 'a'; car <= 'z'; car++)
    printf("  %c", car);
  printf("\n  ---------------------------------------"
         "-------------------------------------\n");
  
  for (car = 'a'; car <= 'z'; car++)
    printf("%3d", c[car - 'a']);
  putchar('\n');
}
