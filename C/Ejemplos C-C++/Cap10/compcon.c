#include <stdio.h>

#define MOSTRAR(s) \
        printf("Precio 1 = %g, precio 2 = %g\n", s ## 1, s ## 2);

main() 
{
  double precio1 = 0, precio2 = 0;

  precio1 = 1100.25;
  precio2 = 900;

  MOSTRAR(precio);
} 
