/* Calcula la mediana
 *
 * Cap6\ejercicio5.c
 */

#include <stdio.h>        
  
main()
{                     
  int menores, mayores, i, j, cont;
  int numero[100]; // matriz de 100 elementos
  
  printf("Introduzca una cantidad impar de n�meros.\n"
         "Finalice introduciendo <Entrar> y despu�s eof\n");
  for (cont = 0; scanf("%d", &numero[cont]) == 1; cont++);
  if(cont % 2 == 0) 
  {
    printf("Ten�a que haber introducido un n�mero impar de n�meros.");
    printf("Se a�ade un 0.");
    numero[cont++] = 0;
  } 
  for (i = 0; i < cont; i++)
  {
    menores = mayores = 0;      
    for (j = 0; j < cont; j++)
    {      
      if ( j == i ) continue;
      if ( numero[i] <= numero[j] ) menores++;
      if ( numero[i] >= numero[j] ) mayores++;
    }
    if (menores == mayores ||
        menores >= cont/2 && mayores >= cont/2) // puede haber n�meros repetidos
    {
      printf("Mediana = %d\n", numero[i]);
      break;
    }
  }
}

