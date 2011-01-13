/******************* Operaciones aritméticas *******************/
// ejercicio02.c

#include <stdio.h>

main()
{
  int dato1, dato2, dato3, resultado;

  dato1 = 20;
  dato2 = 10;
  dato3 = 2;
  
  // Suma
  resultado = dato1 + dato2 + dato3;
  printf("%d + %d + %d = %d\n", dato1, dato2, dato3, resultado);
  
  // Resta
  resultado = dato1 - dato2 - dato3;
  printf("%d - %d - %d = %d\n", dato1, dato2, dato3, resultado);
  
  // Producto
  resultado = dato1 * dato2 * dato3;
  printf("%d * %d * %d = %d\n", dato1, dato2, dato3, resultado);
  
  // Cociente
  resultado = dato1 / dato2 / dato3;
  printf("%d / %d / %d = %d\n", dato1, dato2, dato3, resultado);
  
  // Combinar operaciones aritméticas
  resultado = dato1 * dato2 + dato3;
  printf("resultado = %d\n", resultado);
}
  