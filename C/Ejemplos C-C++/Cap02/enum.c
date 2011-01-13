/* enum.c
 */
#include <stdio.h>

enum colores
{
  azul, amarillo, rojo, verde, blanco, negro
};

main()
{
  enum colores color;
  
  /* Leer un color introducido desde el teclado */
  printf("Color: ");
  scanf("%d", &color);
  /* Visualizar un color */
  printf("%d\n", color);
}
