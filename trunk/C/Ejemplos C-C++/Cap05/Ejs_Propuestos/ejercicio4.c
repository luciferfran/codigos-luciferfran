/* Averigua el número del Tarot
 *
 * Cap5 - ejercicio4.c
 */

#include <stdio.h>        

main()
{                         
  int dd, mm, aaaa, ddo, resto, tarot;

  printf("Si tecleas tu fecha de nacimiento, te calculo tu número de Tarot\n");
  do
  {
    printf("Día:  ");
    scanf("%d", &dd);
  }
  while (dd < 1 || dd > 31); // leer el día mientras no sea correcto
                               // (se supone que los días 29, 30 y 31 son posibles)
  do
  {
    printf("Mes:  ");
    scanf("%d", &mm);
  }
  while (mm < 1 || mm > 12); // leer el mes mientras no sea correcto
  
  do
  {
    printf("Año:  ");
    scanf("%d", &aaaa); 
  }
  while (aaaa < 0 || aaaa > 9000); // leer el año

  tarot = dd + mm + aaaa;

  while (tarot > 9)
  {
    ddo = tarot;
    tarot = 0;
    do
    {
      resto = ddo % 10;
      tarot += resto;
      ddo = ddo / 10;
    }
    while (ddo != 0);
  }

  printf("\nSu número de Tarot es: %d\n", tarot);
}
