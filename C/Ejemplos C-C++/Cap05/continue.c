#include <stdio.h>

main() 
{ 
  int n; 
  for (n = 0; n <= 100; n++)
  {
    // Si n no es múltiplo de 5, siguiente iteración
    if (n % 5 != 0) continue;
    // Imprime el siguiente múltiplo de 5
    printf("%d  ", n);
  }
}
