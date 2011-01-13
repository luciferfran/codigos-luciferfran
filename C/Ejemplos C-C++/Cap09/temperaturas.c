/*************** Estadística de temperaturas ***************/
/* temperaturas.c
 */
#include <stdio.h>
#include <stdlib.h>

struct cabecera  // tipo del registro de cabecera del fichero
{
  struct posicion
  {
    int grados, minutos;
    float segundos;
  } latitud, longitud; // posición geográfica del punto
  
  int total_muestras;
};

struct temperaturas // tipo de la estructura para almacenar las
{                   // temperaturas guardadas en el fichero 
  int total_temp;
  float *temp;
};

struct temperaturas leer_temperaturas(char *nombrefich)
{
  // Almacenar las temperaturas en una estructura de
  // tipo struct temperaturas
  FILE *pf;
  struct cabecera cab;
  struct temperaturas temp;

  if ((pf = fopen(nombrefich, "r")) == NULL)
  {
    printf("No se puede abrir el fichero: %s\n", nombrefich);
    exit(-1);
  }

  // leer el registro de cabecera
  fread(&cab, 1, sizeof(struct cabecera), pf);

  // construir la estructura de temperaturas
  temp.total_temp = cab.total_muestras;
  temp.temp = (float *)malloc(temp.total_temp * sizeof(float));
  if (temp.temp == NULL)
  {
    printf("Insuficiente memoria.\n");
    exit(-1);
  }
  fread(temp.temp, temp.total_temp, sizeof(float), pf);
  fclose(pf);

  return temp;
}

float calcular_media(struct temperaturas temp)
{
  // Media del conjunto de temperaturas
  float suma = 0;
  int i;

  for (i = 0; i < temp.total_temp; i++)
    suma += temp.temp[i];

  return suma/temp.total_temp;
}

float calcular_varianza(struct temperaturas temp)
{
  // Varianza del conjunto de temperaturas
  float suma = 0, media = calcular_media(temp), aux;
  int i;

  for (i = 0; i < temp.total_temp; i++)
  {
    aux = temp.temp [i] - media;
    suma += aux*aux;
  }
  return suma / temp.total_temp;
}

main()
{
  char nombrefich[30];
  struct temperaturas temp;

  printf("Nombre del fichero: ");
  scanf("%s", nombrefich);

  // Construir la estructura temp
  temp = leer_temperaturas(nombrefich);
  printf("Temperatura media = %g grados\n", calcular_media(temp));
  printf("Desviación = %g\n", calcular_varianza(temp));
  
  // Liberar la memoria asignada
  free(temp.temp);
}


