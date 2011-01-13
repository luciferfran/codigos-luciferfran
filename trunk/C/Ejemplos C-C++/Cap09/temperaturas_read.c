/* Visualizar el fichero de temperaturas */
/* tempr.c
 */
#include <stdio.h>
#include <stdlib.h>

struct cabecera
{
  struct posicion
  {
    int grados, minutos;
    float segundos;
  } latitud, longitud; // posición geográfica del punto
  int total_muestras;
};

main(int argc, char *argv [])
{
  FILE *pf;
  struct cabecera cab;
  float temeperatura = 0.0F;
  int i;

  if (argc != 2)
  {
    fprintf(stderr, "Sintaxis: %s nombre_fichero\n", argv[0]);
    exit(-1);
  }
  if ((pf = fopen(argv[1], "r")) == NULL)
  {
    perror(argv[1]);
    exit(-1);
  }
  // Leer el registro de cabecera
  fread(&cab, 1, sizeof(cab), pf);

  // Visualizar las temperaturas
  for (i = 0; i < cab.total_muestras; i++)
  {
    fread(&temeperatura, 1, sizeof(float), pf);
    printf("%g\n", temeperatura);
  }
  fclose(pf);
}
