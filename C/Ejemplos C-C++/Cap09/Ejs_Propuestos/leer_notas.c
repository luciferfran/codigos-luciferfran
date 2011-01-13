// leer_notas.c
//
#include <stdio.h>
#include <stdlib.h>
#define LONG 61

typedef struct
{
  unsigned char nombre[LONG];
  float nota;
} registro;

int existe(char *nombreFichero);
void visualizarFichero(char *nombreFichero);

main()
{
  char nombreFichero[30]; // nombre del fichero
  char resp = 's';
  
  // Solicitar el nombre del fichero
  printf("Nombre del fichero: ");
  gets(nombreFichero);
  
  // Verificar si el fichero existe
  if (existe(nombreFichero))
    visualizarFichero(nombreFichero);
  else
    printf("El fichero no existe\n");
}

int existe(char *nombreFichero)
{
  FILE *pf = NULL;
  // Verificar si el fichero existe
  int exis = 0; // no existe
  if ((pf = fopen(nombreFichero, "r")) != NULL)
  {
    exis = 1;   // existe
    fclose(pf);
  }
  return exis;
}

void visualizarFichero(char *nombreFichero)
{
  FILE *pf = NULL;   // identifica el fichero
  registro reg = {"", 0.0};      // definir un registro
  char resp;

  // Abrir el fichero nombreFichero para escribir "w"
  if ((pf = fopen(nombreFichero, "rb")) == NULL)
  {
    printf("El fichero no puede abrirse.");
    exit(1);
  }

  // Leer datos de la entrada estándar y escribirlos
  // en el fichero
  fread(&reg, sizeof(reg), 1, pf);
  while (!feof(pf))
  {
    printf("Nombre: %s,   ", reg.nombre);
    printf("Nota: %g\n", reg.nota);
    
    printf("¿desea escribir otro registro? (s/n) ");
    resp = getchar(); fflush(stdin);
    if (resp != 's') break;
    fread(&reg, sizeof(reg), 1, pf);
  }
}
