/*************************** Media ***************************/
// Cap2\ejercicio07.c

#include <stdio.h>

/* La suma de 4 n�meros del tipo int es un valor que oscila 
   entre  (2e31-1)*4 y  -(2e31). Como el tama�o de un long
   es igual que el de un int, la suma podr�a ser un float o
   un double. Adem�s, la media puede tener decimales, por lo
   que los tipos posibles para la operaci�n podr�an ser
   float o double: */

/* (El uso de long double, puede hacer al programa dependiente de
   la arquitectura de los micros de Intel '80x87') */

main()
{                                                                            
  int a, b, c, d; 
  float suma, media;

  a = 12000, b = 32422, c = 123000, d = -1212;
  suma = a + b + c + d; 
  // El compilador debe transformar los int a float
  media = suma / 4;
  printf("a = %d\tb = %d\tc = %d\td = %d\nsuma = %g\nmedia = %g\n",
          a, b, c, d, suma, media);    
}
