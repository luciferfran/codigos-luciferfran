#include <stdio.h>

main() 
{ 
  int n; 
  for (n = 0; n <= 100; n++)
  {
    // Si n no es m�ltiplo de 5, siguiente iteraci�n
    if (n % 5 != 0) continue;
    // Imprime el siguiente m�ltiplo de 5
    printf("%d  ", n);
  }
}
