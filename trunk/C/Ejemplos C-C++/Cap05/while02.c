#include <stdio.h>
#include <conio.h>

main()
{
  char car = '\0'; 

  printf("Desea continuar s/n (s� o no) "); 
  while ((car = getchar()) != 's' && car != 'n')
  { 
    fflush(stdin);
    printf("Desea continuar s/n (s� o no) ");
  }
}
