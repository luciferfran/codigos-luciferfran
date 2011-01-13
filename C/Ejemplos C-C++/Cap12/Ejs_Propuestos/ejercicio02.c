/* Método de ordenación de inserción para ficheros.
 *
 * ejercicio02.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char nombre[61];
  float nota;
} registro;

void insercion(FILE *pf, int nregs);
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

  // abrir el fichero argv[1] para leer/escribir "r+b"
  if ((pf = fopen(argv[1], "r+b")) == NULL)
  {
    printf("El fichero %s no puede abrirse\n", argv[1]);
    exit(1);
  }

  fseek(pf, 0L, SEEK_END);
  nregs = (int)ftell(pf)/t_reg;
  rewind(pf);
  insercion(pf, nregs);
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

// Función inserción para ordenar un fichero
void insercion(FILE *pf, int nregs)
{
  int i, k;
  char x[61];
  // Desde el segundo registro
  for (i = 1; i < nregs; i++)
  {
    strcpy(x, campo(pf, i));
    k = i-1;
    // Para k=-1, se ha alcanzado el extremo izquierdo.
    while (k >=0 && strcmp(x, campo(pf,k)) < 0)
    {
      permutarRegistros(pf, k+1, k);
      k--;
    }
  }
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
