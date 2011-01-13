/* Estadística de palabras
 * 
 * ejercicio05.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>                      

const int N = 200;         // Número máximo de palabras distintas
const int TAM_TEX = 1000;  // Número máximo de letras del texto

typedef struct
{
  char palabra[30]; // palabra 
  int contador;     // número de veces que aparece el texto 
} telem;

int BuscarPalabra(telem *a, char *palabra);
void InsertarPalabra(telem *a, char *palabra);
void VisualizarArray(telem *a);

void main()
{       
  char Palabra[30], letra;
  char *Cadena = malloc( TAM_TEX );       // Espacio para TAM_TEX letras
  telem *a = malloc( N * sizeof(telem) ); // Espacio para N palabras
  int cont;

  for(cont = 0; cont < N; cont++)
  {
    // Iniciar a 0 la matriz 'a'
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
  
  VisualizarArray ( a );
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
  int cont, cont2;
  if( a[N-1].contador != 0)
  {
    printf("*** ¡Matriz llena! ***\n");
    return;
    // También, utilizando realloc se podría agrandar la matriz
  }

  for(cont = 0; cont < N; cont++)
  {
    if( strcmp(a[cont].palabra, palabra) > 0 || a[cont].contador == 0)
    {
      for(cont2 = N-1; cont2 >= cont; cont2--)
      {
        if( a[cont2].contador == 0) continue;
        // Se desplaza toda la matriz restante una posición hacia abajo
        strcpy(a[cont2+1].palabra, a[cont2].palabra);
        a[cont2+1].contador = a[cont2].contador;
      }      
      strcpy(a[cont].palabra, palabra); // Se inserta la palabra en el lugar desocupado
      a[cont].contador = 1;             // Inicializa su contador.
      return;
    }
  }    
}

void VisualizarArray(telem *a)
{
  int cont;
  printf("\nEstadística de palabras:\nVeces Palabra\n--------------\n");
  for(cont = 0; cont < N && a[cont].contador != 0; cont++)
    printf("%4d    %s\n", a[cont].contador, a[cont].palabra);
}
