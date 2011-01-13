/* Matriz unidimensional
 *
 * Cap6\ejercicio9.c
 */

#include <stdio.h>                          
#define DIM 300
                          
typedef int tMatrizU[DIM];

int CrearMatrizUni( tMatrizU m, int fi, int co );
int Visualizar(int f, int c, tMatrizU m, int n );
 
void main()
{
  int i, j, n, MaxFil = 3, MaxCol = 3; // 3 filas y columnas por defecto
  static tMatrizU M;

  printf("¿Cuántas filas tiene la matriz? :");
  scanf("%d", &MaxFil);
  printf("¿Y cuántas columnas? :");
  scanf("%d", &MaxCol);

  printf("\nIntroduzca los valores de la matriz bidimensional :\n (0 por defecto)\n");
  n = CrearMatrizUni( M, MaxFil, MaxCol);

  printf("\n\nLa matriz es:\n\n");
  for (i = 0; i < MaxFil; i++)
  { 
    for (j = 0; j < MaxCol; j++)
      printf("%8d", Visualizar(i, j, M, n)); 
    printf("\n");
  }
}
 
int CrearMatrizUni( tMatrizU m, int fi, int co)
{
  int i, j, Num, n = 0;  
  for (i = 0; i < fi; i++)
    for (j = 0; j < co; j++)
    {
      Num = 0;
      printf("M[%d][%d] = ", i, j);
      scanf("%d", &Num);
      if (Num != 0)
      {
        m[n*3] = i; m[n*3+1] = j; m[n*3+2] = Num;
        n++; // contar un nuevo elemento no nulo
      }
      if( n*3 >= DIM)
      {
        printf("\n ¡Matriz llena!\n");
        return n;
      }
    }            
  return n;
}

int Visualizar(int f, int c, tMatrizU m, int n )
{
  int cont;
  for (cont = 0; cont < n*3; cont += 3)
    if(m[cont] == f && m[cont+1] == c)
      return m[cont+2];
  return 0;
}