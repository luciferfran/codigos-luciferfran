/* Estadística de palabras
 * ejercicio04.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                      

/* *** Es aconsejable, cuando sea posible, que las constantes se definan así:
       (de esta forma son tratadas y optimizadas por el compilador y no por el 
       preprocesador)
*/
const int N = 200;        // Número máximo de palabras distintas
const int TAM_TEX = 1000; // Número máximo de letras del texto

typedef struct
{
  char palabra[30]; // palabra
  int contador;     // número de veces que aparece en el texto
} telem;

int BuscarPalabra(telem *a, char *palabra);
void InsertarPalabra(telem *a, char *palabra);
void VisualizarMatriz(telem *a);

main()
{       
  char Palabra[30], letra;
  char *Cadena = malloc( TAM_TEX );       // espacio para TAM_TEX letras
  telem *a = malloc( N * sizeof(telem) ); // espacio para N palabras
  int cont;

  // Iniciar a 0 la matriz 'a'
  for(cont = 0; cont < N; cont++)
  {
    a[cont].palabra[0] = '\0';
    a[cont].contador = 0;
  }

  puts("Introduzca una cadena: \n");
  gets ( Cadena );
  for (cont = 0; (letra = Cadena[cont]) != '\0' && cont < TAM_TEX; cont++)
  {
    // Mientras que no se acabe la cadena:
    if(letra >= 'a' && letra <= 'z')
    {
      int ind;
      for (ind = 0; (letra = Cadena[cont]) >= 'a' && letra <= 'z'; cont++, ind++)
        Palabra[ind] = letra;// Si hay en 'Cadena' una palabra válida, la copia a 'Palabra'
      Palabra[ind] = '\0';   // Pone el carácter de fin de cadena
      cont--;                // Ajusta 'cont'      
      if (BuscarPalabra( a, Palabra) == 0)// Si no se encuentra la palabra en 'a'
        InsertarPalabra( a, Palabra);     // la inserta
    }
  }
  
  VisualizarMatriz( a );
  free(Cadena);
  free(a);
}

int BuscarPalabra(telem *a, char *palabra)
{
  int cont;
  for(cont = 0; cont < N; cont++)
  {
    // Se recorre la matriz 'a'
    if( strcmp( a[cont].palabra, palabra) == 0)
    {
      // Si hay una palabra en 'a' que es igual a 'palabra' entonces
      a[cont].contador++; // Incrementa su contador.
      return 1;
    }
  }    
  return 0; // Si no hubo coincidencias, devuelve 0.
}

void InsertarPalabra(telem *a, char *palabra)
{
  int cont;
  for(cont = 0; cont < N; cont++)
  {
    // Se recorre la matriz 'a'
    if( a[cont].contador == 0)
    {
      // Se inserta la palabra en el primer lugar vacío
      strcpy(a[cont].palabra, palabra);
      a[cont].contador = 1; // Inicia su contador. 
      return;
    }
  }                                      
  printf("*** ¡Matriz llena! ***\n");
  // También, utilizando realloc se podría agrandar la matriz
}

void VisualizarMatriz(telem *a)
{
  int cont;
  printf("\nEstadística de palabras:\nVeces Palabra\n--------------\n");
  for(cont = 0; cont < N && a[cont].contador != 0; cont++)
    printf("%4d    %s\n", a[cont].contador, a[cont].palabra);
}
                           