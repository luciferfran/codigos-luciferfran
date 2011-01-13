/* Cuadrados mágicos
 * 
 * ejercicio3.c
 */

#include <stdio.h>
#include <stdlib.h>
/*                                             
   Se definen dos macros para manejar una matriz:
   INC(a, b) incrementa una coordenada; si se sale de la matriz, empieza por el 
   lado contrario.

   DEC(a, b) decrementa una coordenada; si se sale de la matriz, empieza por el 
   lado contrario.
   b es el número de filas o columnas
   a es la fila o columna que se quiere incrementar
*/                                                                             

#define INC(a, b)  ++(a) >= (b) ? (a) = 0 : (a)
#define DEC(c, d)  --(c) < 0 ? (c) = (d-1) : (c)

void Es_impar(int n);
void Cuadrado_magico(int n);  
                            
main() 
{                              
  int n = 3;
  #if defined(DEBUG)
    printf("*** Entrando en el programa ***\n");
  #endif
  printf("\nCUADRADOS MÁGICOS\n=================\n\nIntroduzca el número n impar"
    " de filas y columnas,\nsiendo n mayor o igual a 3 y menor o igual a 15:\n");
  scanf("%d", &n);
  Es_impar(n);                      
  Cuadrado_magico(n);
  #if defined(DEBUG)
    printf("*** Saliendo del programa ***\n");
  #endif
}

void Es_impar(int n)
{
  #if defined(DEBUG)
    printf("*** Comprobando si %d es par o impar ***\n", n);
  #endif
  if(n % 2 == 0)
  {
    printf("El número %d es par.\n", n);
    exit(0);
  }
  if(n < 3 || n > 15)
  {
    printf("El número %d no está entre los límites permitidos.\n", n);
    #if defined(DEBUG)
      printf("*** Los números posibles están entre 3 y 15 inclusive ***\n");
    #endif
    exit(0);
  }                                 
}

void Cuadrado_magico(int n)
{
  // Se asigna memoria dinámicamente
  int **Matriz = (int **) malloc( n * sizeof(int *) );
  int cont = 0, cont2 = 0, fila = 0, columna = n/2 ;
  #if defined(DEBUG)
    printf("*** Construyendo la matriz... ***\n");
  #endif                                 
  if (Matriz == NULL)
  {
    perror("*** Error al asignar memoria ***");
    exit(-1);
  }

  for(cont = 0; cont < n; cont++)
  {
    Matriz[cont] = (int *)malloc(n * sizeof(int));
    if (Matriz[cont] == NULL)
    {
      perror("*** Error al asignar memoria ***");
      free(Matriz);
      exit(-1);
    }                                         
    for (cont2 = 0; cont2 < n; cont2++)
      Matriz[cont][cont2] = 0;       // se inicia la matriz a 0
  }

  for (cont = 1; cont <= n*n; cont++)
  {  // Se calcula la matriz
    Matriz[fila][columna] = cont;
    DEC(fila, n);
    INC(columna, n);
    if( Matriz[fila][columna] != 0)
    { // Si el elemento ya está ocupado:
      // Deshacer el DEC e INC anteriores
      INC(fila, n);
      DEC(columna, n);
      // Casilla situada debajo del último número
      INC(fila, n);
    }
  }

  for(fila = 0; fila < n; fila++)
  {
    // Se visualiza la matriz
    printf("\n\t");
    for (columna=0; columna < n; columna++)
      printf("%3d ", Matriz[fila][columna] );
    // Liberar memoria de las filas
    free(Matriz[fila]);
  }                
  printf("\n");
  free (Matriz);
}             

