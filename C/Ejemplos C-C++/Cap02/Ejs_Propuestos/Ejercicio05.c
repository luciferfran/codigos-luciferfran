/*************************** Tipos primitivos ***********************/
// Cap2\ejercicio05.c

#include <stdio.h>

main()
{
  printf("Enteros:\n char = %2d bytes\n short = %2d bytes\n int = %2d bytes\n long = %2d bytes\n",
	sizeof(char), sizeof(short), sizeof(int), sizeof(long));
  printf(" (Los tipos signed, ocupan igual que sus respectivos unsigned)\n");   
  printf("Reales:\n float = %2d bytes\n double = %2d bytes\n long double = %2d bytes\n",
	sizeof(float), sizeof(double), sizeof(long double));    
}
