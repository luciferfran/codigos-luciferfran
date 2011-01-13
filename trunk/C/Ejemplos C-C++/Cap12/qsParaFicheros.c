/* Método de ordenación quicksort para ficheros
 * accedidos aleatoriamente.
 *
 * qsParaFicheros.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  unsigned char nombre[61];
  float nota;
} registro;

void quicksort(FILE *pf, int nregs);
void qs(FILE *pf, int inf, int sup);
void permutarRegistros(FILE *pf, int izq, int der);
char *campo(FILE *pf, int n);

main(int argc, char *argv[])
{
  char respuesta;
  registro reg; // registro
  int t_reg = sizeof(registro);       // tamaño de un registro
  FILE *pf;                              // puntero al fichero
  int nregs;

  // Comprobar el número de argumentos pasados en la línea de
  // órdenes 
  if (argc != 2)
  {
    printf("Sintaxis: nombre_programa nombre_fichero\n");
    exit(1);
  }

  // Abrir el fichero argv[1] para leer/escribir "r+b"
  if ((pf = fopen(argv[1], "r+b")) == NULL)
  {
    printf("El fichero %s no puede abrirse\n", argv[1]);
    exit(1);
  }

  fseek(pf, 0L, SEEK_END);
  nregs = (int)ftell(pf)/t_reg;
  rewind(pf);
  quicksort(pf, nregs);
  printf("Fichero ordenado\n");

  do
  {
    printf("¿Desea visualizar el fichero? (s/n)  ");
    respuesta = getchar();
    fflush(stdin);
  }
  while (tolower(respuesta) != 's' && tolower(respuesta) != 'n');

  // Salida de datos
  if (respuesta == 's')
  {
    rewind(pf);
    // Leer el primer registro del fichero
    fread(&reg, t_reg, 1, pf);
    while (!ferror(pf) && !feof(pf))
    {
      printf("Nombre:    %s\n", reg.nombre);
      printf("Nota:      %g\n\n", reg.nota);

      // Leer el siguiente registro del fichero
      fread(&reg, t_reg, 1, pf);
    }
  }
  if (ferror(pf))
    perror("Error durante la lectura");

  fclose(pf);      // cerrar el fichero
}

// Función quicksort para ordenar un fichero
void quicksort(FILE *pf, int nregs)
{
  qs(pf, 0, nregs - 1);
}

// Función qs para ordenar un fichero
void qs(FILE *pf, int inf, int sup)
{
  register izq, der;
  char mitad[20];

  izq = inf; der = sup;
  // Obtener el campo mitad por el que se va a ordenar,
  // del registro mitad
  strcpy(mitad, campo(pf, (int)(izq+der)/2));
  do
  {
    while (strcmp(campo(pf,izq), mitad) < 0 && izq < sup) izq++;
    while (strcmp(mitad, campo(pf,der)) < 0 && der > inf) der--;
    if (izq <= der)
    {
      permutarRegistros(pf, izq, der);
      izq++; der--;
    }
  }
  while (izq <= der);
  if (inf < der) qs(pf, inf, der);
  if (izq < sup) qs(pf, izq, sup);
}

// Permutar los registros de las posiciones izq y der
void permutarRegistros(FILE *pf, int izq, int der)
{
  int t_reg = sizeof(registro); // tamaño de un registro
  registro x, y;

  fseek(pf, (long)izq * t_reg, SEEK_SET);
  fread(&x, t_reg, 1, pf);
  fseek(pf, (long)der * t_reg, SEEK_SET);
  fread(&y, t_reg, 1, pf);

  fseek(pf, (long)izq * t_reg, SEEK_SET);
  fwrite(&y, t_reg, 1, pf);
  fseek(pf, (long)der * t_reg, SEEK_SET);
  fwrite(&x, t_reg, 1, pf);
}

// Leer el campo utilizado para ordenar
char *campo(FILE *pf, int n)
{
  int t_reg = sizeof(registro); // tamaño de un registro
  static registro reg; // registro

  fseek(pf, (long)n * t_reg, SEEK_SET);
  fread(&reg, t_reg, 1, pf);
  return reg.nombre;
}
