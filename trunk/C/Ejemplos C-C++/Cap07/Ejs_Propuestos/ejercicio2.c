/* Diccionario-Traductor
 * 
 * ejercicio2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_PALABRAS 100
                              
int CrearDiccionario(char *); // El argumento es un puntero al diccionario.
                              // Retorna el número de palabras añadidas.
char *Traducir(char *, char *);
            /* Los argumentos son la palabra que se quiere traducir
               y un puntero al diccionario de consulta.
               Retorna el puntero a la palabra traducida o un 
               puntero NULL si no se encuentra. */                             
                              
main() 
{
  // Crear el bloque de memoria para almacenar el diccionario.
  // Puede haber N_PALABRAS en inglés y las misma en español.
  // Cada ocupará 40 caracteres del bloque de memoria.
  char *palabras = malloc(2 * N_PALABRAS * 40 * sizeof (char));
  if (palabras == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }
  if (CrearDiccionario(palabras) == 0)
  {
    printf("\nNinguna palabra en el diccionario.\n");
    return 0;
  }

  printf("Inserte las palabras que quiera traducir:\n"
         "(Para terminar pulse [Ctrl]+[z].)\n");
  while (1)
  {                     
    char palabra[40], *p;
    if (fgets(palabra, 40, stdin) == NULL) break;
    if ((p = Traducir(palabra, palabras)) == NULL) 
    {
      printf("Palabra no encontrada.\n");
      continue;
    }
    printf(" ===> %s\n", p);
  }
  free( palabras );
  return 0;
}

int CrearDiccionario(char *diccio)
{
  // El bloque de memoria empieza en diccio.
  // Las palabras en inglés están desde el byte 0 hasta el byte N_PALABRAS * 40.
  // Las palabras en español están desde el byte N_PALABRAS * 40 + 1
  // hasta el byte N_PALABRAS * 40 * 2, en el orden correspondiente.
  int cont;
  char palabra[40], *r = NULL;
  printf("Teclee cada palabra finalizada con [Entrar].\n");
  printf("Primero la palabra en inglés y después en español.\n");
  printf("Para finalizar pulse [Ctrl]+[z]\n");
  for(cont = 0; cont < N_PALABRAS; cont++)
  {
    printf("Palabra en inglés:  ");
    r = fgets(palabra, 40, stdin);
    if (r == NULL) break;
    strcpy(diccio + 40 * cont, palabra);
    printf("Palabra en español: ");
    r = fgets(palabra, 40, stdin);
    if (r == NULL) break;
    strcpy(diccio + N_PALABRAS * 40 + 40 * cont, palabra);
  }     
  return cont;
}

char *Traducir(char *palabra, char *diccio)
{
  int cont;
  for (cont = 0; cont < N_PALABRAS * 40; cont += 40)
    if(strcmp(palabra, (diccio + cont)) == 0)
      return (diccio + N_PALABRAS * 40 + cont);
  return NULL;
}    

