/* Cálculo de una función
 * 
 * ejercicio4bis.c
 */

#include <stdio.h>
#include <math.h>   

#define  total 10000
    
double f(double x);
double rnd(double x);
                          
void main()
{                         
  double inc, x = 0, res = 0, cont;
  printf("Introduzca un valor para x: ");
  scanf("%lf", &x);
  if(x >= 0)
  { 
    inc = x / total; // inc == base de los rectángulos
    for (cont = 0; cont < x; cont += inc) // Este bucle se repite total veces
      res += f(cont); // Suma las alturas de total muestras  
  }
  else
    res = 0;
  printf("El resultado es:  %lf\n", res * inc); // Altura total * Base
}

double f(double x)
{
  return  exp(-(x*x));
}                     
