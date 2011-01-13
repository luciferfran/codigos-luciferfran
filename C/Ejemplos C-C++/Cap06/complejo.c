/*************** Matrices de números complejos ***************/
/* complejo.c
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 10 // máximo número de filas y columnas

typedef struct
{
  float r; // parte real de un número complejo
  float i; // parte imaginaria de un número complejo
} tcomplejo;

typedef struct
{
  int filas;    // filas que actualmente tiene la matriz
  int columnas; // columnas que actualmente tiene la matriz
  tcomplejo c[MAX][MAX]; // matriz de complejos
} tmatriz;

tmatriz LeerMatriz()
{
  tmatriz m;
  int f = 0, c = 0, r = 0;
  
  do
  {
    printf("\nNúmero de filas: ");
    r = scanf ("%d", &m.filas);
    fflush(stdin);
  }
  while (r != 1 || m.filas > MAX);

  do
  {
    printf("Número de columnas: ");
    r = scanf("%d", &m.columnas);
    fflush(stdin);
  }
  while (r != 1 || m.columnas > MAX);

  // Leer los datos para la matriz
  printf("\nIntroducir datos de la forma: x yj\n");
  printf("x e y son valores reales positivos o negativos\n\n");
  for (f = 0; f < m.filas; f++)
  {
    for (c = 0; c < m.columnas; c++)
    {
      do
      {
        printf("elemento [%d][%d] = ", f, c);
        r = scanf("%f %f", &m.c[f][c].r,&m.c[f][c].i);
        fflush(stdin);
      }
      while (r != 2);
    }
  }
  return m;
}

void VisualizarMatriz(tmatriz m)
{
  int f, c;

  printf("\n");
  for (f = 0; f < m.filas; f++)
  {
    for (c = 0; c < m.columnas; c++)
      printf ("%8.2f%+8.2fj", m.c[f][c].r, m.c[f][c].i);
    printf ("\n");
  }
}

tcomplejo MulCompl(tcomplejo a, tcomplejo b)
{
  tcomplejo c;

  c.r = a.r * b.r - a.i * b.i;
  c.i = a.r * b.i + a.i * b.r;
  return c;
}

tcomplejo SumCompl(tcomplejo a, tcomplejo b)
{
  tcomplejo c;

  c.r = a.r + b.r;
  c.i = a.i + b.i;
  return c;
}

tmatriz Multiplicar(tmatriz a, tmatriz b)
{
  tmatriz m;
  int f, c, k;

  if (a.columnas != b.filas)
  {
    printf ("No se pueden multiplicar las matrices.\n");
    exit(-1);
  }

  m.filas = a.filas;
  m.columnas = b.columnas;

  // Multiplicar las matrices
  for (f = 0; f < m.filas; f++)
  {
    for (c = 0; c < m.columnas; c++)
    {
      m.c[f][c].r = 0;
      m.c[f][c].i = 0;
      for (k = 0; k < a.columnas; k++)
        m.c[f][c] = SumCompl(m.c[f][c], MulCompl(a.c[f][k], b.c[k][c]));
    }
  }
  return m;
}

void main(void)
{
  static tmatriz a, b, c;

  a = LeerMatriz();
  b = LeerMatriz();
  c = Multiplicar(a, b);
  VisualizarMatriz(c);
}
