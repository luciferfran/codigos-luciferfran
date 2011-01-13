/* Cálculo de una función
 * 
 * ejercicio4.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>   
#include <time.h>   

#define  total 10000

double f(double x);
double rnd(long *);
                          
void main()
{                         
  double x = 0, res = 0, cont;
  unsigned long dentro = 0, fuera = 0;
  long random = 0;

  printf("Introduzca un valor para x: ");
  scanf("%lf", &x);
  if(x >= 0)
  { 
    for (cont = 0; cont < total; cont++)
    {
      if ( f(rnd(&random) * x) > rnd(&random) )
        dentro++;
    }                                           
    // probabilidad = superficie / (1 * x)
    // superficie = x * probabilidad
    res = x * dentro/total;
  }
  else
    res = 0;
  printf("El resultado es:  %lf\n", res);
}

double f(double x)
{
  return exp(-x*x);
}

double rnd(long *prandom)
{               
  *prandom = (25173 * *prandom + 13849) % 65536;
  return (double) *prandom / 65535;
}

/*
  Como se llega a la expresión: f(rnd(&random) * x) > rnd(&random)

  x1 = rnd(...) * x --> valor entre 0 y x
  y1 = rnd(...)     --> valor entre 0 y 1

  área del rectángulo conocido:                      a1 = x1 * y1
  área del réctangulo limitado por f(x) = exp(-x*x): a2 = x1 * f(x1)
  Si a2 > a1 el punto de coordenadas (x1, y1) está dentro del área
  delimitada por f(x)
  a2 > a1 es lo mismo que
  x1 * f(x1) > x1 * y1 que simplificado queda f(x1) > y1 lo que se
  traduce en: f(rnd(&random * x)) > rnd(&random)

  probabilidad p = superficie irregular (si) / superficie conocida (1 * x)
  p = si / x
  si = x * p
*/
