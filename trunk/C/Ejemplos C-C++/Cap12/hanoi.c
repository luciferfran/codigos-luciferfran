/* hanoi.c
 */
#include <stdio.h>

int mover(int, char, char, char);

// Ejemplo de las Torres de Hanoi
main()
{
  int n_discos, movimientos;
  
  printf("Número de discos : ");
  scanf("%d", &n_discos);
  movimientos = mover(n_discos, 'A', 'B', 'C');
  printf("\nmovimientos efectuados: %d\n", movimientos);
}

// Función para mover discos de una torre a otra
int mover(int n_discos, char a, char b, char c)
{
  static int movimientos = 0;
  
  if (n_discos > 0)
  {
    mover(n_discos-1, a, c, b);
    printf("mover disco de %c a %c\n", a, c);
    movimientos++;
    mover(n_discos-1, b, a, c);
  }
  return movimientos;
}
