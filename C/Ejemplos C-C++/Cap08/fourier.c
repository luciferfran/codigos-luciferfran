/*************** Transformada discreta de Fourier ***************/
/* fourier.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
  double real, imag;
} complejo;

complejo sumar( complejo a, complejo b )
{
  complejo temp;
  temp.real = a.real + b.real;
  temp.imag = a.imag + b.imag;
  return temp;
}

complejo multiplicar( complejo a, complejo b )
{
  complejo temp;
  temp.real = a.real * b.real - a.imag * b.imag;
  temp.imag = a.real * b.imag + a.imag * b.real;
  return temp;
}

void DFT( complejo *X, double *x, int N )
{
  int n, k;
  double t, pi = 3.141592654;
  complejo a, b;
  
  for ( k = 0; k < N; k++ )
  {
    X[k].real = 0; X[k].imag = 0;
    for ( n = 0; n < N; n++ )
    {
      a.real = x[n]; a.imag = 0;
      t = k * 2 * pi / N * n;
      b.real = cos( -t ); b.imag = sin( -t );
      b = multiplicar( a, b ); 
      X[k] = sumar( X[k], b );
    }
  }
}

main()
{
  complejo *X;
  double *x;
  int n, N;
  
  printf( "Cuántos valores reales desea introducir\n" );
  scanf( "%d", &N );

  // Asignar memoria para la matriz de complejos
  if ((X = (complejo *)malloc(N * sizeof(complejo))) == NULL)
  {
    printf( "Insuficiente memoria para asignación\n" );
    exit( 1 );
  }
  
  // Asignar memoria para la matriz que almacenará la secuencia
  // de números reales
  if ((x = (double *)malloc(N * sizeof(double))) == NULL)
  {
    printf( "Insuficiente memoria para asignación\n" );
    exit( 1 );
  }
  
  // Introducir la secuencia de números reales
  printf( "Introduzca los valores\n" );
  for ( n = 0; n < N; n++ )
    scanf( "%lf", &x[n] );
  
  // Calcular la transformada discreta de Fourier
  DFT(X, x, N);
  
  printf("Resultado:\n");
  for ( n = 0; n < N; n++ )
    printf( "%g%+g j\n", X[n].real, X[n].imag );
}
