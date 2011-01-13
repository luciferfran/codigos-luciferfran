/********** Buscar cadenas de caracteres en ficheros **********/
/* grep.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BuscarCadena(char *cadena1, char *cadena2)
{
    // ¿cadena2 está contenida en cadena1?
    if (strstr(cadena1, cadena2))
      return 1; // se encontró
    else
      return 0;     // no se encontró
}

void BuscarEnFich(char *nombrefich, char *cadena)
{
  FILE *pf;
  char linea[256];
  int nrolinea = 0;
  
  // Abrir el fichero nombrefich
  if ((pf = fopen(nombrefich, "r")) == NULL)
  {
    perror(nombrefich);
    return;
  }
  
  // Buscar cadena en el fichero asociado con pf
  while (fgets(linea, sizeof(linea), pf) != NULL)
  {
    nrolinea++;
    if (BuscarCadena(linea, cadena))
      printf("%s[%d]: %s", nombrefich, nrolinea, linea);
  }
  fclose(pf);
}

main(int argc, char *argv[])
{
  int i;
  
  // Verificar el número de argumentos
  if (argc < 3)
  {
    printf("Sintaxis: %s palabra f1 f2 ... fn\n", argv[0]);
    exit(-1);
  }
  
  // Llamar a la función BuscarEnFich por cada fichero
  for (i = 2; i < argc; i++)
    BuscarEnFich(argv[i], argv[1]);
}
