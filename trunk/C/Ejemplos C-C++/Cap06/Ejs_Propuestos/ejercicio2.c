/* Histograma de pesos
 *
 * Cap6\ejercicio2.c
 */

#include <stdio.h>

main()
{                         
  int peso = 0, alumnos[91]; // Se reserva espacio para 91 alumnos 
  int peso_bien = 0, peso_mal = 0, temp;
  for (temp = 0; temp < 91; temp++) 
    alumnos[temp] = 0; // iniciar la matriz a 0
  printf("\nEscriba los pesos de los alumnos separados por espacios.\n"
         "Cuando haya terminado escriba \"fin\" y pulse [Entrar]:\n");
  while(scanf("%d", &peso) == 1)                     
  {
    if (peso < 10 || peso > 100) 
    { // Si se introduce un peso no válido:
      peso_mal++;
      continue;
    }
    alumnos[peso - 10]++;             
  }
  printf("\nPeso  Número de alumnos\n" 
         "-----------------------");
  for (peso = 10; peso <= 100; peso++)
  {
    if (alumnos[peso - 10] != 0)
    {
      printf("\n%3d   ", peso);
      for (temp = alumnos[peso - 10]; temp > 0; temp--)
      {
        printf("*"); 
        peso_bien++;
      }                                  
    }
  }       
  printf("\n\nNúmero de pesos correctos: %d\n", peso_bien);
  printf("Número de pesos erróneos: %d\n", peso_mal);
}
