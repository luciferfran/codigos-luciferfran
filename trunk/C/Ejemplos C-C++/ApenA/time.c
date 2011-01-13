/********** Generar un n�mero aleatorio cada segundo **********/
/* time.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
  long x, tm;
  time_t segundos;

  time(&segundos);
  printf("\n%s\n", ctime(&segundos));
  srand((unsigned)time(NULL));

  for (x = 1; x <= 5; x++)
  {
    do      // tiempo de espera igual a 1 segundo
      tm = clock();
    while (tm/CLOCKS_PER_SEC < x);
    // Se genera un n�mero aleatorio cada segundo
    printf("Iteraci�n %ld: %d\n", x, rand());
  }
}
