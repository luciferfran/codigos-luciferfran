/*************************** Evaluaci�n ***************************/
// Cap2\ejercicio08.c

#include <stdio.h>

main()
{                                                                            
  float a = 1, b = 5, c = 2, result; // Se inician a, b, c en la propia declaraci�n
  result = (b*b - 4*a*c) / (2*a);    // El uso de par�ntesis es conveniente cuando 
									                   // se dude de la prioridad de los operadores.  
									                   // No se genera m�s c�digo por emplear muchos
									                   // par�ntesis. En nuestro caso es necesario.
  printf("a = %g\tb = %g\tc = %g\nResultado = %g\n", a, b, c, result);
  // Observe la diferencia entre utilizar %f y %g    
}
