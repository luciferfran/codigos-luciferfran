/*** Leer datos de un fichero registro a registro ***/
/* fread.c
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
} registro;      // tipo registro

int existe(char *nombreFichero);
void mostrarFichero(char *nombreFichero);

main()
{
  char nombreFichero[30]; // nombre del fichero
  char resp = 's';
  
  // Solicitar el nombre del fichero
  printf("Nombre del fichero: ");
  gets(nombreFichero);
  
  // Verificar si el fichero existe
  if (existe(nombreFichero))
    mostrarFichero(nombreFichero);
  else
    printf("El fichero no existe.");
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

void mostrarFichero(char *nombreFichero)
{
  FILE *pfe = NULL; // identificador del fichero de entrada
  FILE *pfs = NULL; // identificador del dispositivo de salida
  registro reg;     // definir un registro
  char resp = 0;

  // Abrir el fichero nombreFichero para leer "r"
  if ((pfe = fopen(nombreFichero, "r")) == NULL)
  {
    printf("El fichero no puede abrirse.");
    exit(1);
  }

  // Leer datos del fichero y mostrarlos en la salida estándar,
  // o bien por la impresora.
  printf("¿desea escribir los datos por la impresora? (s/n) ");
  resp = getchar();
  fflush(stdin);
  if (resp == 's')
  {
    if ((pfs = fopen("lpt1", "w")) == NULL)
    {
      printf("La impresora no está disponible");
      pfs = stdout; // asumimos la pantalla
    }
  }
  else
    pfs = stdout; // pantalla

  fread(&reg, sizeof(reg), 1, pfe);
  while (!ferror(pfe) && !feof(pfe))
  {
    system("cls"); // limpiar la pantalla
    fprintf(pfs, "Nombre:    %s\n", reg.nombre);
    fprintf(pfs, "Dirección: %s\n", reg.direccion);
    fprintf(pfs, "Teléfono:  %ld\n\n", reg.telefono);

    // Hacer una pausa (sólo cuando los datos se muestran
    // por pantalla)
    if (pfs == stdout)
    {
      printf("Pulse <Entrar> para continuar ");
      getchar(); fflush(stdin);
    }

    // Leer el siguiente registro del fichero
    fread(&reg, sizeof(reg), 1, pfe);
  }

  if (pfs != stdout)
    fprintf(pfs, "\f"); // avanzar una página en la impresora

  if (ferror(pfe))
    perror("Error durante la lectura");
  fclose(pfe);
  fclose(pfs);
}
