/* tolower
 */
#include <stdio.h>
#include <stdlib.h>

main()
{
  char car;
  do
  {
    printf("¿Desea continuar? s/n ");
    car = getchar();
    fflush(stdin);
  }
  while (tolower(car) != 'n' && tolower(car) != 's');
}
