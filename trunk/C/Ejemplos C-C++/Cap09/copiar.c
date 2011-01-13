/********** Copiar el contenido de un fichero en otro **********/
/* copiar.c
 */
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
  FILE *des = NULL, *org = NULL;
  int conta = 0, car = 0;

  // Comprobar el número de argumentos pasados
  // en la línea de órdenes
  if (argc != 3)
  {
    printf("Sintaxis: copiar origen destino\n");
    exit(1);
  }

  // Abrir el fichero indicado por argv[1] para leer
  // y el indicado por argv[2] para escribir
  if ( (org = fopen(argv[1], "rb")) == NULL ||
       (des = fopen(argv[2], "wb")) == NULL )
  {
    printf("No se puede realizar la copia\n");
    exit(1);
  }

  // Copiar
  while (!ferror(org) && !feof(org) && !ferror(des))
  {
    car = fgetc(org);
    conta++;   // contar caracteres
    fputc(car, des);
  }

  // Verificar si la copia se hizo con éxito
  if (ferror(org) || ferror(des))
    perror("Error durante la copia");
  else
    printf("Se han copiado %d caracteres\n", conta-1);

  fclose(org);
  fclose(des);
}
