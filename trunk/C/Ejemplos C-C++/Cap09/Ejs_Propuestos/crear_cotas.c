// crear_cotas.c
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
  unsigned int total_cotas_eje_x;
  unsigned int total_cotas_eje_y;
  float resolucion; // en metros
} cabecera;         

int existe(char *nombreFichero);
void crearFichero(char *nombreFichero);
float rnd(long *);

main()
{
  char nombreFichero[30]; // nombre del fichero
  char resp = 's';
  
  // Solicitar el nombre del fichero
  printf("Nombre del fichero: ");
  gets(nombreFichero);
  
  // Verificar si el fichero existe
  if (existe(nombreFichero))
  {
    printf("El fichero existe ¿desea sobrescribirlo? (s/n) ");
    resp = getchar();
    fflush(stdin);
  }
  if (resp == 's')
  {
    crearFichero(nombreFichero);
  }
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

void crearFichero(char *nombreFichero)
{
  FILE *pf = NULL;   // identifica el fichero
  cabecera cab = {201, 101, 100.0}; // definir un registro
  int ancho = 20000, largo = 10000, i = 0, c = 0;
  float res = 100.0, r = 0.0;
  long random = time(NULL) % 65536;  // semilla

  // Abrir el fichero nombreFichero para escribir "w"
  if ((pf = fopen(nombreFichero, "wb")) == NULL)
  {
    printf("El fichero no puede abrirse.");
    exit(1);
  }

  // Leer datos del terreno
  printf("Resolución en mentros: "); scanf("%f", &res);
  cab.resolucion = res;
  printf("Ancho en metros      : "); scanf("%d", &ancho);
  cab.total_cotas_eje_x = (int)(ancho/res + 1);
  printf("Largo en metros      : "); scanf("%d", &largo);
  cab.total_cotas_eje_y = (int)(largo/res +1);
  fwrite(&cab, sizeof(cabecera), 1, pf);
  if (ferror(pf))
  {
    perror("Error durante la escritura");
    exit(2);
  }

  // Leer datos de las cotas.
  // Se simula generando números seudoaleatorios.
  c = (int)cab.total_cotas_eje_x * cab.total_cotas_eje_y;
  for (i = 0; i < c; i++)
  {
    r = rnd(&random) * 2000;
    fwrite(&r, sizeof(float), 1, pf);
    if (ferror(pf))
    {
      perror("Error durante la escritura");
      exit(2);
    }
  }
}

float rnd(long *prandom)
{
  *prandom = (25173 * *prandom + 13849) % 65536;
  return((float)*prandom / 65535);
}
