/* Cotas de altitud
 * ejercicio04.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  unsigned int total_cotas_eje_x;
  unsigned int total_cotas_eje_y;
  float resolucion; // en metros
} cabecera;         
                                            

main(int argc, char *argv [])
{
  FILE *pf; 
  cabecera cab;
  char nomfich[20], *fich;
  float max, min, med, dato;

  if (argc == 2)
    fich = argv[1];
  else
    do
    { 
      printf("Introduzca el nombre del fichero de cotas de altitud: ");
    }while ((fich = gets(nomfich)) == NULL);

  if ((pf = fopen(fich, "rb")) == NULL)
  {
    perror(fich);
    exit(-1);
  }

  // Leer la cabecera del fichero
  if (fread(&cab, 1, sizeof(cabecera), pf) < 1)
    exit(-1);
  
  // Leer las cotas de altitud
  fread(&dato, 1, sizeof(dato), pf);
  max = min = dato;            
  med = 0.0F;

  while( fread(&dato, sizeof(float), 1, pf) == 1 )
  {
    // Se leen todos los datos
    if (dato > max) max = dato; // 'max' tendrá el máximo dato
    if (dato < min) min = dato; // 'min' tendrá el mínimo dato
    med += dato; // Suma de los datos
  }             
  printf("Ancho:\t%g metros\nLargo:\t%g metros\nAlturas:\n  - Máxima:\t%g metros\n"
    "  - Mínima:\t%g metros\nMedia:\t%g metros\n",
    (cab.total_cotas_eje_x-1) * cab.resolucion, (cab.total_cotas_eje_y-1) * cab.resolucion,
    max, min, med/( cab.total_cotas_eje_x * cab.total_cotas_eje_y));                
  fclose(pf);
}