/*************************** ¿Resultados? ***************************/
// Cap2\ejercicio4.c 

#include <stdio.h>
main()
{
  int a = 10, b = 3, c, d, e;
  float x, y;
  x = a / b;        // x = 3 -> Por ser división de enteros
  c = a < b && 25;  // c = FALSE && TRUE = FALSE = 0
  d = a + b++;      // d = 10 + 3 = 13; b = b + 1 = 4
  e = ++a - b;      // a = a + 1 = 11; e = 11 - 4 = 7
  y = (float)a / b; // y = 11 / 4 = 2.75 -> a y b se transforman a float
                    // temporalmente para hacer la división
  printf("a=%d b=%d c=%d d=%d e=%d \nx=%f y=%f \n",a,b,c,d,e,x,y);
}